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

public:
    ScanResult();

    operator std::string() const;

    void setExecutionTime(const std::chrono::microseconds &execution_time);
};

#endif //KASPERSKIYTEST1_SRC_SCANRESULT_H_
