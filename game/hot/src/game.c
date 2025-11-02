#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include "game.h"
#define CIMGUI_DEFINE_ENUMS_AND_STRUCTS
#define CIMGUI_USE_OPENGL3
#define CIMGUI_USE_GLFW
#include "cimgui.h"
#include "cimgui_impl.h"

void setup_contexts(struct GameContext *gctx)
{
    glfwMakeContextCurrent(gctx->window_ctx);
    gctx->ig_ctx = igCreateContext(NULL);
    igSetCurrentContext(gctx->ig_ctx);

    ImGui_ImplGlfw_InitForOpenGL(gctx->window_ctx, true);
    ImGui_ImplOpenGL3_Init("#version 130");
    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
}

int game_init(struct GameContext *gctx)
{
    printf("Game initialised\n");
    setup_contexts(gctx);
    return 1;
}

void game_deinit(struct GameContext *gctx)
{
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    igDestroyContext(gctx->ig_ctx);
}

void game_update(struct GameContext *gctx)
{

    if(is_key_pressed(gctx->inputinfo, GLFW_KEY_ESCAPE))
    {
        glfwSetWindowShouldClose(gctx->window_ctx, 1);
    }

    glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    igNewFrame();

    igText("Hey !");

    igRender();
    ImGui_ImplOpenGL3_RenderDrawData(igGetDrawData());
    glfwSwapBuffers(gctx->window_ctx);
}
