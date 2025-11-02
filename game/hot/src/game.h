#ifndef GAME_H
#define GAME_H

struct GameContext;

int game_init(struct GameContext *gctx);

void game_deinit(struct GameContext *gctx);

void game_update(struct GameContext *gctx);

// Interface Definition
#include "interface.h"
int init(struct GameContext *gctx)
{
    return game_init(gctx);
}
void deinit(struct GameContext *gctx)
{
    game_deinit(gctx);
}
void update(struct GameContext *gctx)
{
    game_update(gctx);
}
///////////////////////
#endif // GAME_H
