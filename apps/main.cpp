#include <iostream>
#include "model.h"

using namespace std;

int main(int, char**) {
    std::string helloJim = generateHelloString("Jim");
    std::cout << helloJim << std::endl;

    Model model;

    return 0;
}