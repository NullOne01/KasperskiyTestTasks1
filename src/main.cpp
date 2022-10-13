#include <iostream>
#include <filesystem>
#include "MalwareScanner.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cout << "Eblan?";
        return -1;
    }

    MalwareScanner scanner;
    auto res = scanner.scanDirectory(std::filesystem::path(argv[1]));

    std::cout << std::string(res) << std::endl;
    return 0;
}
