#include <iostream>
#include "1.h"
#include "Fbi.h"
int main() {
    std::cout << "Hello, World!" << std::endl;
    int i;
    for (int i = 0; i < 40; ++i) {
        printf("%d ",Fbi(i));
    }
    return 0;
}

