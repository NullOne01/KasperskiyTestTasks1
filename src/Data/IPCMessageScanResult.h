#ifndef KASPERSKIYTEST1_IPCMESSAGESCANRESULT_H
#define KASPERSKIYTEST1_IPCMESSAGESCANRESULT_H

struct IPCMessageScanResult {
    long type = 2;

    int processed_files;
    int js_detects;
    int unix_detects;
    int macos_detects;
    int error_detects;
    int64_t execution_time;
};

#endif //KASPERSKIYTEST1_IPCMESSAGESCANRESULT_H
