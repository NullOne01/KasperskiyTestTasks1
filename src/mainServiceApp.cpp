#include <iostream>
#include <filesystem>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include "MalwareScanner.h"
#include "Data/IPCMessageScanRequest.h"

int main(int argc, char *argv[]) {
    key_t key = ftok("shared", 0);
    if (key < 0) {
        std::cout << "Can\'t generate key" << std::endl;
        return -1;
    }

    int msg_id = msgget(key, 0666 | IPC_CREAT);
    if (msg_id < 0) {
        std::cout << "Can\'t get msqid" << std::endl;
        return -1;
    }

    MalwareScanner scanner;
    std::cout << "== Scan service is started ==" << std::endl;

    while (true) {
        IPCMessageScanRequest request_message{};

        ssize_t code;
        // Idk why MSG_EXCEPT is not supported :/ I would use it here
        if ((code = msgrcv(msg_id, &request_message, sizeof(IPCMessageScanRequest), 1, 0)) < 0) {
            std::cout << "Can\'t receive message from queue" << std::endl;
            perror("error");
            return -1;
        }

        std::cout << "Received request: " << request_message.path << std::endl;

        ScanResult res = scanner.scanDirectory(std::filesystem::path(request_message.path));
        IPCMessageScanResult ipc_res = res.getResultIPC();
        // Return result to its owner.
        ipc_res.type = request_message.id;

        if ((code = msgsnd(msg_id, &ipc_res, sizeof(IPCMessageScanResult), 0)) < 0) {
            std::cout << "Can\'t send message to queue" << std::endl;
            perror("error");
            return -1;
        }

        std::cout << "Sent result" << std::endl;
    }

    return 0;
}
