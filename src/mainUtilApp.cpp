#include <iostream>
#include <filesystem>
#include <sys/msg.h>
#include <random>
#include "MalwareScanner.h"
#include "Data/IPCMessageScanRequest.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cout << "How to use: ./scan_util PATH_TO_DIRECTORY";
        return -1;
    }

    std::string path = argv[1];

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

    // Generating random id to receive message prepared for you
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(1,99999);
    int random_id = static_cast<int>(dist6(rng));

    IPCMessageScanRequest request_message{};
    request_message.id = random_id;
    strcpy(request_message.path, path.c_str());

    ssize_t code;
    if ((code = msgsnd(msg_id, &request_message, sizeof(IPCMessageScanRequest), 0)) < 0) {
        std::cout << "Can\'t send message to queue" << std::endl;
        perror("error");
        return -1;
    }

    std::cout << "Sent request" << std::endl;

    IPCMessageScanResult ipc_res{};
    if ((code = msgrcv(msg_id, &ipc_res, sizeof(IPCMessageScanResult), random_id, 0)) < 0) {
        std::cout << "Can\'t receive message from queue" << std::endl;
        perror("error");
        return -1;
    }

    ScanResult res(ipc_res);

    std::cout << "====== Scan result ======" << std::endl;
    std::cout << std::string(res) << std::endl;
    std::cout << "=========================" << std::endl;

    return 0;
}
