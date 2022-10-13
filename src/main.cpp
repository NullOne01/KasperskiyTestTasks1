#include <iostream>
#include <filesystem>
#include "MalwareScanner.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cout << "How to use: ./scan_util PATH_TO_DIRECTORY";
        return -1;
    }

    MalwareScanner scanner;
    auto res = scanner.scanDirectory(std::filesystem::path(argv[1]));

    std::cout << "====== Scan result ======" << std::endl;
    std::cout << std::string(res) << std::endl;
    std::cout << "=========================" << std::endl;

    return 0;
}
