#ifndef KASPERSKIYTEST1_SRC_SCANRESULT_H_
#define KASPERSKIYTEST1_SRC_SCANRESULT_H_

#include <chrono>
#include <string>
#include <unordered_map>
#include "ParseFileResult.h"

class ScanResult {
private:
    std::unordered_map<ParseFileResult, int> file_res_counter;
    int processed_files_ = 0;
    std::chrono::microseconds execution_time_{0};

public:
    operator std::string();

    void setExecutionTime(const std::chrono::microseconds &execution_time);

    void loadParseResult(ParseFileResult parseFileResult);
};

#endif //KASPERSKIYTEST1_SRC_SCANRESULT_H_
