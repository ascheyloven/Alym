#pragma once

#include "Window.h"

namespace Alym{
    class EntryApp{
    public:
        static constexpr int WIDTH = 800;
        static constexpr int HEIGHT = 600;

        void run();

    private:
        Window Window{WIDTH, HEIGHT, "First Vulkan Window"};
    };
}