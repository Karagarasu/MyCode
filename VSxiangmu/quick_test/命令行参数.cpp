#include <iostream>
int main(int argc, char* argv[]) {
    for (int i = 0; i < argc; i++) {
        std::cout << "参数 " << i << ": " << argv[i] << std::endl;
    }
    return 0;
}