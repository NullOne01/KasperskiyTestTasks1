cmake_minimum_required(VERSION 3.20)
project(KasperskiyTest1)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
# Set runtime resources.
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/../input_data/ DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/input_data/)

set(CMAKE_CXX_STANDARD 17)

add_executable(scan_service mainServiceApp.cpp MalwareParser.cpp MalwareParser.h MalwareScanner.cpp MalwareScanner.h Utils/ChronoUtils.h Data/ScanResult.cpp Data/ScanResult.h Data/ParseFileResult.h Data/MalwareLineDatabase.cpp Data/MalwareLineDatabase.h Data/IPCMessageScanRequest.h Data/IPCMessageScanResult.h)

add_executable(scan_util mainUtilApp.cpp Data/IPCMessageScanRequest.h Data/ScanResult.cpp Data/ScanResult.h)
