#include <stdio.h>
#include <windows.h>

#include "GLFW/glfw3.h"
#include "reloading.h"
#include "window/input.h"
#include "window/window.h"

int main()
{
    if(!initGl())
    {
        printf("Error: Failed to init OpenGL constext!\n");
        return 1;
    }
    const char *lib_path = "./build/bin/libhot.dll";
    const char *cpy_path = "./build/bin/_libhot.dll";

    struct HotContext hctx = hr_initialize(lib_path, cpy_path);
    hr_set_ctx(&hctx);
    if(!hr_load()) return 1;

    struct GameContext gctx;
    gctx.window_ctx = w_get_window_ctx();
    gctx.delta_time = 0;

    double last_frame_time = glfwGetTime();

    i_initialize();
    hctx.fuctions.init(&gctx);

    while(!window_should_close())
    {
        double frame_time = glfwGetTime();
        gctx.delta_time = last_frame_time - frame_time;
        last_frame_time = frame_time;

        gctx.inputinfo = i_get_info();

        if(hr_newer_available()) 
        {
            hctx.fuctions.deinit(&gctx);
            while(!hr_load()){}
            hctx.fuctions.init(&gctx);
            printf("Game reloaded !\n");
        }

        hctx.fuctions.update(&gctx);

        i_clear();
        glfwPollEvents();
    }

    return 0;
}
