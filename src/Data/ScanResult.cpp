#include <sstream>
#include <iomanip>
#include "ScanResult.h"
#include "../Utils/ChronoUtils.h"

ScanResult::ScanResult() {}

ScanResult::operator std::string() const {
    const auto[hrs, mins, secs, ms] = ChronoUtils::chronoBurst(execution_time);

    std::ostringstream out;
    out << "Processed files: " << processed_files << "\n"
        << "JS detects: " << js_detects << "\n"
        << "Unix detects: " << unix_detects << "\n"
        << "macOS detects: " << macos_detects << "\n"
        << "Errors:" << errors_num << "\n"
        << "Execution time: " << std::setw(2) << hrs.count() << ":"
                              << std::setw(2) << mins.count() << ":"
                              << std::setw(2) << secs.count() << ":"
                              << std::setw(5) << ms.count() << "\n";
    return out.str();
}
void ScanResult::setExecutionTime(const std::chrono::microseconds &execution_time) {
    ScanResult::execution_time = execution_time;
}
