#ifndef KASPERSKIYTEST1_SRC_SCANRESULT_H_
#define KASPERSKIYTEST1_SRC_SCANRESULT_H_

#include <chrono>
#include <string>
#include "ParseFileResult.h"

class ScanResult {
private:
    int processed_files_ = 0;
    int js_detects_ = 0;
    int unix_detects_ = 0;
    int macos_detects_ = 0;
    int errors_num_ = 0;
    std::chrono::microseconds execution_time_{0};

public:
    operator std::string() const;

    void setExecutionTime(const std::chrono::microseconds &execution_time);

    void loadParseResult(ParseFileResult parseFileResult);
};

#endif //KASPERSKIYTEST1_SRC_SCANRESULT_H_
