#include <sstream>
#include <iomanip>
#include "ScanResult.h"
#include "../Utils/ChronoUtils.h"

ScanResult::operator std::string() const {
    const auto[hrs, mins, secs, ms] = ChronoUtils::chronoBurst(execution_time_);

    std::ostringstream out;
    out << "Processed files: " << processed_files_ << "\n"
        << "JS detects: " << js_detects_ << "\n"
        << "Unix detects: " << unix_detects_ << "\n"
        << "macOS detects: " << macos_detects_ << "\n"
        << "Errors: " << errors_num_ << "\n"
        << "Execution time: " << std::setfill('0') << std::setw(2) << hrs.count() << ":"
                              << std::setw(2) << mins.count() << ":"
                              << std::setw(2) << secs.count() << ":"
                              << std::setw(4) << ms.count() << "\n";
    return out.str();
}

void ScanResult::setExecutionTime(const std::chrono::microseconds &execution_time) {
    execution_time_ = execution_time;
}

void ScanResult::loadParseResult(ParseFileResult parseFileResult) {
    processed_files_++;

    switch (parseFileResult) {
        case ParseFileResult::ERROR:
            errors_num_++;
            break;
        case MALWARE_JS:
            js_detects_++;
            break;
        case MALWARE_UNIX:
            unix_detects_++;
            break;
        case MALWARE_MACOS:
            macos_detects_++;
            break;
        case CLEAR:
            break;
    }
}
