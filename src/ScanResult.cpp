#include <sstream>
#include <iomanip>
#include "ScanResult.h"
#include "Utils/ChronoUtils.h"

ScanResult::ScanResult() {}

ScanResult::operator std::string() const {
    const auto[hrs, mins, secs, ms] = ChronoUtils::chronoBurst(execution_time);

    std::ostringstream out;
    out << "Processed files: " << processed_files << "\n"
        << "JS detects: " << js_detects << "\n"
        << "Unix detects: " << unix_detects << "\n"
        << "macOS detects: " << macos_detects << "\n"
        << "Errors:" << errors_num << "\n"
        << "Execution time: " << std::setw(2) << hrs << ":"
                              << std::setw(2) << mins << ":"
                              << std::setw(2) << secs << ":"
                              << std::setw(5) << ms << "\n";
    return out.str();
}
