#include "EntryApp.h"
#include <glm/mat4x4.hpp>

#include <cstdlib>
#include <stdexcept>
#include <iostream>

int main() {
    Alym::EntryApp app{};

    try {
        app.run();
    }
    catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}