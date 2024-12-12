#include <iostream>
#include <fstream>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "Incorrect Usage. Try ./solution <filename>\n";
        return -1;
    }

    std::ifstream inputFile(argv[1]);

    return 0;
}
