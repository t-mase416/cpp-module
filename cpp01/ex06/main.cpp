#include "Harl.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
        return 1;
    }
    // コマンドライン引数を const std::string& で引き渡す
    harlFilter(argv[1]);
    return 0;
}