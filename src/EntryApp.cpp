#include "EntryApp.h"

namespace Alym {
    void EntryApp::run() {
        while (!Window.shouldClose()){
            glfwPollEvents();
        }
    }
}