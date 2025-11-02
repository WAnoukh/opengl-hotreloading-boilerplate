#ifndef INTERFACE_H
#define INTERFACE_H

#include "input_def.h"

typedef struct GLFWwindow GLFWwindow;

struct GameContext
{
   GLFWwindow *window_ctx; 
   struct ImGuiContext *ig_ctx;
   struct InputInfo inputinfo;
   float delta_time;
};

typedef int (*HotInitFunction)(struct GameContext *);
typedef void (*HotDeinitFunction)(struct GameContext *);
typedef int (*HotUpdateFunction)(struct GameContext *);

struct HotFunctions
{
    HotInitFunction init;
    HotDeinitFunction deinit;
    HotUpdateFunction update;
};

__declspec(dllexport) int init(struct GameContext *gctx);

__declspec(dllexport) void deinit(struct GameContext *gctx);

__declspec(dllexport) void update(struct GameContext *gctx);

#endif // INTERFACE_H
