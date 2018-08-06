#ifndef LIBRARIES_H
#define LIBRARIES_H

#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <time.h>

#include <SDL.h>
#include <SDL_image.h>

#include "game.h"
#include "cTexture.h"
#include "cTimer.h"
#include "tetromino.h"

extern bool flagError;
extern bool flagQuit;

extern int mapTetris[10][22];
extern int mapNext[4][2];
extern int tetrominoType[6];


#endif // TETROMINO_H
