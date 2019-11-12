#include <iostream>
#include "irulan.h"
#include "irulan_e.h"
#include "TestApp.h"

int main(int argc, char *argv[]) {
    std::cout << "Hello, World!" << std::endl;

    Iru::Matrix matrix({
                               1, 3, 5, 6,
                               1, 3, 5, 6,
                               1, 3, 5, 6,
                               1, 3, 5, 6,
                       });

    Iru::Matrix matrix2({
                                -0.1, 1.4, 5, -66,
                                66, -3, 15, 6,
                                1, 2, 5, 6.5,
                                1, 4, 55, 6,
                        });

    std::cout << matrix << std::endl;
    std::cout << matrix2 << std::endl;
    std::cout << matrix * matrix2 << std::endl;

    TestApp app;
    app.run();

    return 0;
}