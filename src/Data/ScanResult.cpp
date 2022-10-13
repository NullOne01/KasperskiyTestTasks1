#include <sstream>
#include <iomanip>
#include "ScanResult.h"
#include "../Utils/ChronoUtils.h"

ScanResult::operator std::string() {
    const auto [hrs, mins, secs, ms] = ChronoUtils::chronoBurst(execution_time_);

    std::ostringstream out;
    out << "Processed files: " << processed_files_ << "\n"
        << "JS detects: " << file_res_counter[ParseFileResult::MALWARE_JS] << "\n"
        << "Unix detects: " << file_res_counter[ParseFileResult::MALWARE_UNIX] << "\n"
        << "macOS detects: " << file_res_counter[ParseFileResult::MALWARE_MACOS] << "\n"
        << "Errors: " << file_res_counter[ParseFileResult::ERROR] << "\n"
        << "Execution time: " << std::setfill('0') << std::setw(2) << hrs.count() << ":"
                                                      << std::setw(2) << mins.count() << ":"
                                                      << std::setw(2) << secs.count() << ":"
                                                      << std::setw(3) << ms.count();
    return out.str();
}

void ScanResult::setExecutionTime(const std::chrono::microseconds &execution_time) {
    execution_time_ = execution_time;
}

void ScanResult::loadParseResult(ParseFileResult parseFileResult) {
    processed_files_++;
    file_res_counter[parseFileResult]++;
}
