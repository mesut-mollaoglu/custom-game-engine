#define STB_IMAGE_IMPLEMENTATION
#include "headers/includes.h"

int main()
{
    Window window = Window(1024, 768);
    while(!glfwWindowShouldClose(window.handle))
    {
        window.Begin();
        window.Clear({255, 125, 25, 255});
        window.SwapBuffers();
        window.End();
    }
    return 0;
}