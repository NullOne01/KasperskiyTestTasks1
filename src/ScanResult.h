#ifndef KASPERSKIYTEST1_SRC_SCANRESULT_H_
#define KASPERSKIYTEST1_SRC_SCANRESULT_H_

#include <chrono>
#include <string>

class ScanResult {
private:
    int processed_files = 0;
    int js_detects = 0;
    int unix_detects = 0;
    int macos_detects = 0;
    int errors_num = 0;
    std::chrono::microseconds execution_time{0};

//    std::chrono::time_point<std::chrono::system_clock> start_time = std::chrono::high_resolution_clock::now();

public:
    ScanResult();

    operator std::string() const;
};

#endif //KASPERSKIYTEST1_SRC_SCANRESULT_H_
