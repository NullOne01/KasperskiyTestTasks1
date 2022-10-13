cmake_minimum_required(VERSION 3.20)
project(KasperskiyTest1)

set(CMAKE_CXX_STANDARD 17)

add_executable(KasperskiyTest1 main.cpp MalwareParser.cpp MalwareParser.h MalwareScanner.cpp MalwareScanner.h ScanResult.cpp ScanResult.h Utils/ChronoUtils.h)
