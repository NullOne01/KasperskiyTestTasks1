#ifndef KASPERSKIYTEST1_IPCMESSAGESCANREQUEST_H
#define KASPERSKIYTEST1_IPCMESSAGESCANREQUEST_H

struct IPCMessageScanRequest {
    long type = 1;
    // Request's owner's id
    int id;
    char path[128];
};

#endif //KASPERSKIYTEST1_IPCMESSAGESCANREQUEST_H
