#ifndef GLOBAL_H
#define GLOBAL_H

#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <time.h>

#include <SDL.h>
#include <SDL2/SDL_image.h>

#include "include/game.h"
#include "include/cTexture.h"
#include "include/cTimer.h"
#include "include/collision.h"
#include "include/tetromino.h"

extern SDL_Event event;

extern bool flagError;
extern bool flagQuit;

extern int mapTetris[14][24];
extern int mapNext[4][2];
extern int tetrominoPosition[4][2];
extern int tetrominoType[6];
extern int tetrominoRotationStep;
extern int tetrominoRotationOffset[16];// = {0, 1, 1, 0, 0, -1, -1, 0};

extern bool collisionFlag1;
extern bool collisionFlag2;
extern bool collisionFlag3;
extern bool collisionFlag4;

#endif
