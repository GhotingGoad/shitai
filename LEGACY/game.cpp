#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>
#include "wTexture.h"
#include <math.h>

SDL_Window* gameWindow = NULL;
SDL_Renderer* gameRenderer = NULL;

wTexture textureBackground;
SDL_Rect textureBackgroundClip;
wTexture textureTetromino;
SDL_Rect textureTetrominoClip[7];

int mapTetris[10][22];
//00 = block1x, 01 = block1y, 10 = block2x, 11 = block2y etc etc
int tetrominoPosition[4][2];
int tetrominoPreviousPosition[4][2];
int tetrominoType;

//individual collision block for Player controlled Tetromino
bool collisionFlag1;
bool collisionFlag2;
bool collisionFlag3;
bool collisionFlag4;

//offset and step for Tetromino I SRS
int tetrominoRotationStep;
int tetrominoRotationOffset[8] = {0, 1, 1, 0, 0, -1, -1, 0};


void generateTetromino(){
    srand(time(NULL));
    tetrominoType = rand()%7;
    switch(tetrominoType){
        case 0:
            mapTetris[4][0] = 0;
            mapTetris[5][0] = 0;
            mapTetris[4][1] = 0;
            mapTetris[5][1] = 0;

            tetrominoPosition[0][0] = 4;
            tetrominoPosition[0][1] = 0;
            tetrominoPosition[1][0] = 5;
            tetrominoPosition[1][1] = 0;
            tetrominoPosition[2][0] = 4;
            tetrominoPosition[2][1] = 1;
            tetrominoPosition[3][0] = 5;
            tetrominoPosition[3][1] = 1;
            break;
        case 1:
            mapTetris[3][1] = 1;
            mapTetris[4][1] = 1;
            mapTetris[5][1] = 1;
            mapTetris[6][1] = 1;

            tetrominoPosition[0][0] = 4;
            tetrominoPosition[0][1] = 1;
            tetrominoPosition[1][0] = 5;
            tetrominoPosition[1][1] = 1;
            tetrominoPosition[2][0] = 3;
            tetrominoPosition[2][1] = 1;
            tetrominoPosition[3][0] = 6;
            tetrominoPosition[3][1] = 1;

            tetrominoRotationStep = 0;
            break;
        case 2:
            mapTetris[3][0] = 2;
            mapTetris[4][0] = 2;
            mapTetris[4][1] = 2;
            mapTetris[5][1] = 2;

            tetrominoPosition[0][0] = 4;
            tetrominoPosition[0][1] = 1;
            tetrominoPosition[1][0] = 3;
            tetrominoPosition[1][1] = 0;
            tetrominoPosition[2][0] = 4;
            tetrominoPosition[2][1] = 0;
            tetrominoPosition[3][0] = 5;
            tetrominoPosition[3][1] = 1;
            break;
        case 3:
            mapTetris[3][0] = 3;
            mapTetris[3][1] = 3;
            mapTetris[4][1] = 3;
            mapTetris[5][1] = 3;

            tetrominoPosition[0][0] = 4;
            tetrominoPosition[0][1] = 1;
            tetrominoPosition[1][0] = 3;
            tetrominoPosition[1][1] = 0;
            tetrominoPosition[2][0] = 3;
            tetrominoPosition[2][1] = 1;
            tetrominoPosition[3][0] = 5;
            tetrominoPosition[3][1] = 1;
            break;
        case 4:
            mapTetris[4][0] = 4;
            mapTetris[3][1] = 4;
            mapTetris[4][1] = 4;
            mapTetris[5][1] = 4;

            tetrominoPosition[0][0] = 4;
            tetrominoPosition[0][1] = 1;
            tetrominoPosition[1][0] = 3;
            tetrominoPosition[1][1] = 1;
            tetrominoPosition[2][0] = 4;
            tetrominoPosition[2][1] = 0;
            tetrominoPosition[3][0] = 5;
            tetrominoPosition[3][1] = 1;
            break;
        case 5:
            mapTetris[4][0] = 5;
            mapTetris[5][0] = 5;
            mapTetris[3][1] = 5;
            mapTetris[4][1] = 5;

            tetrominoPosition[0][0] = 4;
            tetrominoPosition[0][1] = 1;
            tetrominoPosition[1][0] = 4;
            tetrominoPosition[1][1] = 0;
            tetrominoPosition[2][0] = 5;
            tetrominoPosition[2][1] = 0;
            tetrominoPosition[3][0] = 3;
            tetrominoPosition[3][1] = 1;
            break;
        case 6:
            mapTetris[5][0] = 6;
            mapTetris[3][1] = 6;
            mapTetris[4][1] = 6;
            mapTetris[5][1] = 6;

            tetrominoPosition[0][0] = 4;
            tetrominoPosition[0][1] = 1;
            tetrominoPosition[1][0] = 3;
            tetrominoPosition[1][1] = 1;
            tetrominoPosition[2][0] = 5;
            tetrominoPosition[2][1] = 0;
            tetrominoPosition[3][0] = 5;
            tetrominoPosition[3][1] = 1;
            break;
    };
}


bool initializeGame(int SCREEN_WIDTH, int SCREEN_HEIGHT, bool flagError){
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        printf("SDL cannot initialize due to %s", SDL_GetError());
        flagError = true;
    }else{
        printf("SDL successfully initialized.");
        gameWindow = SDL_CreateWindow("SDL Tetris", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if(gameWindow == NULL){
            printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
            flagError = true;
        }else{
            //initialize SDL_Image
            int imgFlags = IMG_INIT_PNG;
            if(!(IMG_Init(imgFlags) & imgFlags)){
                printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
                flagError = true;
            }else{
                gameRenderer = SDL_CreateRenderer(gameWindow, -1, SDL_RENDERER_ACCELERATED);
                printf("Window successfully created.\n");
            }
        }
    }
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 22; j++){
            mapTetris[i][j] = -1;
        }
    }
    generateTetromino();
    return flagError;
}

bool loadMedia(bool flagError)
{
    if(!textureBackground.loadFromFile("media/background.png", gameRenderer)){
        printf("Failed to load Background image!\n");
        flagError = true;
    }
    else{
        if(!textureTetromino.loadFromFile("media/blocks.png", gameRenderer)){
            printf("Failed to load Blocks image!\n");
            flagError = true;
        }else{
            textureTetrominoClip[0].x = 0;
            textureTetrominoClip[0].w = 20;
            textureTetrominoClip[0].h = 20;

            textureTetrominoClip[1].x = 20;
            textureTetrominoClip[1].w = 20;
            textureTetrominoClip[1].h = 20;

            textureTetrominoClip[2].x = 40;
            textureTetrominoClip[2].w = 20;
            textureTetrominoClip[2].h = 20;

            textureTetrominoClip[3].x = 60;
            textureTetrominoClip[3].w = 20;
            textureTetrominoClip[3].h = 20;

            textureTetrominoClip[4].x = 80;
            textureTetrominoClip[4].w = 20;
            textureTetrominoClip[4].h = 20;

            textureTetrominoClip[5].x = 100;
            textureTetrominoClip[5].w = 20;
            textureTetrominoClip[5].h = 20;

            textureTetrominoClip[6].x = 120;
            textureTetrominoClip[6].w = 20;
            textureTetrominoClip[6].h = 20;
        }
    }

    return flagError;
}

void refreshWindow()
{
    SDL_RenderClear(gameRenderer);

    //textureBackground.renderBackground(gameRenderer);
    textureBackground.renderBackground(gameRenderer);
    for(int i = 0; i < 10; i++){
        for(int j = 2; j < 22; j++){
            int clip = mapTetris[i][j];
            if(clip<10) textureTetromino.renderSprite(i * 20 + 40, j * 20, &textureTetrominoClip[clip], gameRenderer);
            else textureTetromino.renderSprite(i * 20 + 40, j * 20, &textureTetrominoClip[clip-10], gameRenderer);
        }
    }
    SDL_RenderPresent(gameRenderer);
}

void checkClearRows(){

    int rowEmptyCount[22] = {};
    int rowEmptyNumber[4] = {};
    int rowEmptyNumberCount = 0;
    int rowEmptyNumberLoop = 0;

    for(int i = 21; i != 0; i--){
        for(int j = 0; j <10; j++){
            if(mapTetris[j][i] == -1) rowEmptyCount[i]++;
        }
        if(rowEmptyCount[i] == 0){
            for(int j = 0; j <10; j++){
                mapTetris[j][i] = -1;
                rowEmptyNumber[rowEmptyNumberCount] = i;
            }
            rowEmptyNumberCount++;
            rowEmptyCount[i] = 0;
        }
    }
    rowEmptyNumberLoop = rowEmptyNumberCount;
    for(int k = 0; k < rowEmptyNumberLoop; k++){
        //find place to put rowEmptyNumberCount = 0;
        rowEmptyNumberCount = 0;
        for(int i = rowEmptyNumber[rowEmptyNumberCount]; i != 0; i--){
            for(int j = 0; j <10; j++){
                mapTetris[j][i] = mapTetris[j][i - 1];
            }
        }
        rowEmptyNumberCount++;
    }
}

void moveDown(){
    if(tetrominoPosition[0][1] + 1 != 22 && tetrominoPosition[1][1] + 1 != 22 && tetrominoPosition[2][1] + 1 != 22 && tetrominoPosition[3][1] + 1 != 22){
        if(mapTetris[tetrominoPosition[0][0]][tetrominoPosition[0][1] + 1] == -1 || mapTetris[tetrominoPosition[0][0]][tetrominoPosition[0][1] + 1] == tetrominoType){
            collisionFlag1 = true;
        }else{
            collisionFlag1 = false;
        }
        if(mapTetris[tetrominoPosition[1][0]][tetrominoPosition[1][1] + 1] == -1 || mapTetris[tetrominoPosition[1][0]][tetrominoPosition[1][1] + 1] == tetrominoType){
            collisionFlag2 = true;
        }else{
            collisionFlag2 = false;
        }
        if(mapTetris[tetrominoPosition[2][0]][tetrominoPosition[2][1] + 1] == -1 || mapTetris[tetrominoPosition[2][0]][tetrominoPosition[2][1] + 1] == tetrominoType){
            collisionFlag3 = true;
        }else{
            collisionFlag3 = false;
        }
        if(mapTetris[tetrominoPosition[3][0]][tetrominoPosition[3][1] + 1] == -1 || mapTetris[tetrominoPosition[3][0]][tetrominoPosition[3][1] + 1] == tetrominoType){
            collisionFlag4 = true;
        }else{
            collisionFlag4 = false;
        }

        if(collisionFlag1 && collisionFlag2 && collisionFlag3 && collisionFlag4){
            mapTetris[tetrominoPosition[0][0]][tetrominoPosition[0][1]] = -1;
            mapTetris[tetrominoPosition[1][0]][tetrominoPosition[1][1]] = -1;
            mapTetris[tetrominoPosition[2][0]][tetrominoPosition[2][1]] = -1;
            mapTetris[tetrominoPosition[3][0]][tetrominoPosition[3][1]] = -1;

            mapTetris[tetrominoPosition[0][0]][tetrominoPosition[0][1] + 1] = tetrominoType;
            mapTetris[tetrominoPosition[1][0]][tetrominoPosition[1][1] + 1] = tetrominoType;
            mapTetris[tetrominoPosition[2][0]][tetrominoPosition[2][1] + 1] = tetrominoType;
            mapTetris[tetrominoPosition[3][0]][tetrominoPosition[3][1] + 1] = tetrominoType;

            tetrominoPosition[0][1] += 1;
            tetrominoPosition[1][1] += 1;
            tetrominoPosition[2][1] += 1;
            tetrominoPosition[3][1] += 1;
        }else{
            mapTetris[tetrominoPosition[0][0]][tetrominoPosition[0][1]] = tetrominoType + 10;
            mapTetris[tetrominoPosition[1][0]][tetrominoPosition[1][1]] = tetrominoType + 10;
            mapTetris[tetrominoPosition[2][0]][tetrominoPosition[2][1]] = tetrominoType + 10;
            mapTetris[tetrominoPosition[3][0]][tetrominoPosition[3][1]] = tetrominoType + 10;

            checkClearRows();

            generateTetromino();
        }
    }else{
        mapTetris[tetrominoPosition[0][0]][tetrominoPosition[0][1]] = tetrominoType + 10;
        mapTetris[tetrominoPosition[1][0]][tetrominoPosition[1][1]] = tetrominoType + 10;
        mapTetris[tetrominoPosition[2][0]][tetrominoPosition[2][1]] = tetrominoType + 10;
        mapTetris[tetrominoPosition[3][0]][tetrominoPosition[3][1]] = tetrominoType + 10;

        checkClearRows();

        generateTetromino();
    }
}

void moveLeft(){
    if(mapTetris[tetrominoPosition[0][0] - 1][tetrominoPosition[0][1]] == -1 || mapTetris[tetrominoPosition[0][0] - 1][tetrominoPosition[0][1]] == tetrominoType){
        collisionFlag1 = true;
    }else{
        collisionFlag1 = false;
    }
    if(mapTetris[tetrominoPosition[1][0] - 1][tetrominoPosition[1][1]] == -1 || mapTetris[tetrominoPosition[1][0] - 1][tetrominoPosition[1][1]] == tetrominoType){
        collisionFlag2 = true;
    }else{
        collisionFlag2 = false;
    }
    if(mapTetris[tetrominoPosition[2][0] - 1][tetrominoPosition[2][1]] == -1 || mapTetris[tetrominoPosition[2][0] - 1][tetrominoPosition[2][1]] == tetrominoType){
        collisionFlag3 = true;
    }else{
        collisionFlag3 = false;
    }
    if(mapTetris[tetrominoPosition[3][0] - 1][tetrominoPosition[3][1]] == -1 || mapTetris[tetrominoPosition[3][0] - 1][tetrominoPosition[3][1]] == tetrominoType){
        collisionFlag4 = true;
    }else{
        collisionFlag4 = false;
    }

    if(collisionFlag1 && collisionFlag2 && collisionFlag3 && collisionFlag4){
        mapTetris[tetrominoPosition[0][0]][tetrominoPosition[0][1]] = -1;
        mapTetris[tetrominoPosition[1][0]][tetrominoPosition[1][1]] = -1;
        mapTetris[tetrominoPosition[2][0]][tetrominoPosition[2][1]] = -1;
        mapTetris[tetrominoPosition[3][0]][tetrominoPosition[3][1]] = -1;

        mapTetris[tetrominoPosition[0][0] - 1][tetrominoPosition[0][1]] = tetrominoType;
        mapTetris[tetrominoPosition[1][0] - 1][tetrominoPosition[1][1]] = tetrominoType;
        mapTetris[tetrominoPosition[2][0] - 1][tetrominoPosition[2][1]] = tetrominoType;
        mapTetris[tetrominoPosition[3][0] - 1][tetrominoPosition[3][1]] = tetrominoType;

        tetrominoPosition[0][0] -= 1;
        tetrominoPosition[1][0] -= 1;
        tetrominoPosition[2][0] -= 1;
        tetrominoPosition[3][0] -= 1;
    }
    refreshWindow();
}

void moveRight(){
    if(mapTetris[tetrominoPosition[0][0] + 1][tetrominoPosition[0][1]] == -1 || mapTetris[tetrominoPosition[0][0] + 1][tetrominoPosition[0][1]] == tetrominoType){
        collisionFlag1 = true;
    }else{
        collisionFlag1 = false;
    }
    if(mapTetris[tetrominoPosition[1][0] + 1][tetrominoPosition[1][1]] == -1 || mapTetris[tetrominoPosition[1][0] + 1][tetrominoPosition[1][1]] == tetrominoType){
        collisionFlag2 = true;
    }else{
        collisionFlag2 = false;
    }
    if(mapTetris[tetrominoPosition[2][0] + 1][tetrominoPosition[2][1]] == -1 || mapTetris[tetrominoPosition[2][0] + 1][tetrominoPosition[2][1]] == tetrominoType){
        collisionFlag3 = true;
    }else{
        collisionFlag3 = false;
    }
    if(mapTetris[tetrominoPosition[3][0] + 1][tetrominoPosition[3][1]] == -1 || mapTetris[tetrominoPosition[3][0] + 1][tetrominoPosition[3][1]] == tetrominoType){
        collisionFlag4 = true;
    }else{
        collisionFlag4 = false;
    }

    if(collisionFlag1 && collisionFlag2 && collisionFlag3 && collisionFlag4){
        mapTetris[tetrominoPosition[0][0]][tetrominoPosition[0][1]] = -1;
        mapTetris[tetrominoPosition[1][0]][tetrominoPosition[1][1]] = -1;
        mapTetris[tetrominoPosition[2][0]][tetrominoPosition[2][1]] = -1;
        mapTetris[tetrominoPosition[3][0]][tetrominoPosition[3][1]] = -1;

        mapTetris[tetrominoPosition[0][0] + 1][tetrominoPosition[0][1]] = tetrominoType;
        mapTetris[tetrominoPosition[1][0] + 1][tetrominoPosition[1][1]] = tetrominoType;
        mapTetris[tetrominoPosition[2][0] + 1][tetrominoPosition[2][1]] = tetrominoType;
        mapTetris[tetrominoPosition[3][0] + 1][tetrominoPosition[3][1]] = tetrominoType;

        tetrominoPosition[0][0] += 1;
        tetrominoPosition[1][0] += 1;
        tetrominoPosition[2][0] += 1;
        tetrominoPosition[3][0] += 1;
    }
    refreshWindow();
}

void rotateClockwise(){
    if(tetrominoType != 0){
        tetrominoPreviousPosition[0][0] = tetrominoPosition[0][0];
        tetrominoPreviousPosition[0][1] = tetrominoPosition[0][1];
        tetrominoPreviousPosition[1][0] = tetrominoPosition[1][0];
        tetrominoPreviousPosition[1][1] = tetrominoPosition[1][1];
        tetrominoPreviousPosition[2][0] = tetrominoPosition[2][0];
        tetrominoPreviousPosition[2][1] = tetrominoPosition[2][1];
        tetrominoPreviousPosition[3][0] = tetrominoPosition[3][0];
        tetrominoPreviousPosition[3][1] = tetrominoPosition[3][1];

        mapTetris[tetrominoPosition[0][0]][tetrominoPosition[0][1]] = -1;
        mapTetris[tetrominoPosition[1][0]][tetrominoPosition[1][1]] = -1;
        mapTetris[tetrominoPosition[2][0]][tetrominoPosition[2][1]] = -1;
        mapTetris[tetrominoPosition[3][0]][tetrominoPosition[3][1]] = -1;

        // {0, -1, -1, 0, 0, 1, 1, 0};

        if(tetrominoType == 1){
            tetrominoPosition[0][0] = (tetrominoPreviousPosition[0][1] - tetrominoPreviousPosition[0][1]) + tetrominoPreviousPosition[0][0] + tetrominoRotationOffset[tetrominoRotationStep];
            tetrominoPosition[0][1] = -(tetrominoPreviousPosition[0][0] - tetrominoPreviousPosition[0][0]) + tetrominoPreviousPosition[0][1] + tetrominoRotationOffset[tetrominoRotationStep + 1];
            tetrominoPosition[1][0] = (tetrominoPreviousPosition[1][1] - tetrominoPreviousPosition[0][1]) + tetrominoPreviousPosition[0][0] + tetrominoRotationOffset[tetrominoRotationStep];
            tetrominoPosition[1][1] = -(tetrominoPreviousPosition[1][0] - tetrominoPreviousPosition[0][0]) + tetrominoPreviousPosition[0][1] + tetrominoRotationOffset[tetrominoRotationStep + 1];
            tetrominoPosition[2][0] = (tetrominoPreviousPosition[2][1] - tetrominoPreviousPosition[0][1]) + tetrominoPreviousPosition[0][0] + tetrominoRotationOffset[tetrominoRotationStep];
            tetrominoPosition[2][1] = -(tetrominoPreviousPosition[2][0] - tetrominoPreviousPosition[0][0]) + tetrominoPreviousPosition[0][1] + tetrominoRotationOffset[tetrominoRotationStep + 1];
            tetrominoPosition[3][0] = (tetrominoPreviousPosition[3][1] - tetrominoPreviousPosition[0][1]) + tetrominoPreviousPosition[0][0] + tetrominoRotationOffset[tetrominoRotationStep];
            tetrominoPosition[3][1] = -(tetrominoPreviousPosition[3][0] - tetrominoPreviousPosition[0][0]) + tetrominoPreviousPosition[0][1] + tetrominoRotationOffset[tetrominoRotationStep + 1];

            if(tetrominoRotationStep == 6) tetrominoRotationStep = 0;
            else tetrominoRotationStep += 2;
        }else{
            tetrominoPosition[0][0] = (tetrominoPreviousPosition[0][1] - tetrominoPreviousPosition[0][1]) + tetrominoPreviousPosition[0][0];
            tetrominoPosition[0][1] = -(tetrominoPreviousPosition[0][0] - tetrominoPreviousPosition[0][0]) + tetrominoPreviousPosition[0][1];
            tetrominoPosition[1][0] = (tetrominoPreviousPosition[1][1] - tetrominoPreviousPosition[0][1]) + tetrominoPreviousPosition[0][0];
            tetrominoPosition[1][1] = -(tetrominoPreviousPosition[1][0] - tetrominoPreviousPosition[0][0]) + tetrominoPreviousPosition[0][1];
            tetrominoPosition[2][0] = (tetrominoPreviousPosition[2][1] - tetrominoPreviousPosition[0][1]) + tetrominoPreviousPosition[0][0];
            tetrominoPosition[2][1] = -(tetrominoPreviousPosition[2][0] - tetrominoPreviousPosition[0][0]) + tetrominoPreviousPosition[0][1];
            tetrominoPosition[3][0] = (tetrominoPreviousPosition[3][1] - tetrominoPreviousPosition[0][1]) + tetrominoPreviousPosition[0][0];
            tetrominoPosition[3][1] = -(tetrominoPreviousPosition[3][0] - tetrominoPreviousPosition[0][0]) + tetrominoPreviousPosition[0][1];
        }
            mapTetris[tetrominoPosition[0][0]][tetrominoPosition[0][1]] = tetrominoType;
            mapTetris[tetrominoPosition[1][0]][tetrominoPosition[1][1]] = tetrominoType;
            mapTetris[tetrominoPosition[2][0]][tetrominoPosition[2][1]] = tetrominoType;
            mapTetris[tetrominoPosition[3][0]][tetrominoPosition[3][1]] = tetrominoType;
        refreshWindow();
    }
}

void rotateCounterClockwise(){
    if(tetrominoType != 0){
        tetrominoPreviousPosition[0][0] = tetrominoPosition[0][0];
        tetrominoPreviousPosition[0][1] = tetrominoPosition[0][1];
        tetrominoPreviousPosition[1][0] = tetrominoPosition[1][0];
        tetrominoPreviousPosition[1][1] = tetrominoPosition[1][1];
        tetrominoPreviousPosition[2][0] = tetrominoPosition[2][0];
        tetrominoPreviousPosition[2][1] = tetrominoPosition[2][1];
        tetrominoPreviousPosition[3][0] = tetrominoPosition[3][0];
        tetrominoPreviousPosition[3][1] = tetrominoPosition[3][1];

        mapTetris[tetrominoPosition[0][0]][tetrominoPosition[0][1]] = -1;
        mapTetris[tetrominoPosition[1][0]][tetrominoPosition[1][1]] = -1;
        mapTetris[tetrominoPosition[2][0]][tetrominoPosition[2][1]] = -1;
        mapTetris[tetrominoPosition[3][0]][tetrominoPosition[3][1]] = -1;

        if(tetrominoType == 1){
            tetrominoPosition[0][0] = -(tetrominoPreviousPosition[0][1] - tetrominoPreviousPosition[0][1]) + tetrominoPreviousPosition[0][0] - tetrominoRotationOffset[tetrominoRotationStep];
            tetrominoPosition[0][1] = (tetrominoPreviousPosition[0][0] - tetrominoPreviousPosition[0][0]) + tetrominoPreviousPosition[0][1] - tetrominoRotationOffset[tetrominoRotationStep + 1];
            tetrominoPosition[1][0] = -(tetrominoPreviousPosition[1][1] - tetrominoPreviousPosition[0][1]) + tetrominoPreviousPosition[0][0] - tetrominoRotationOffset[tetrominoRotationStep];
            tetrominoPosition[1][1] = (tetrominoPreviousPosition[1][0] - tetrominoPreviousPosition[0][0]) + tetrominoPreviousPosition[0][1] - tetrominoRotationOffset[tetrominoRotationStep + 1];
            tetrominoPosition[2][0] = -(tetrominoPreviousPosition[2][1] - tetrominoPreviousPosition[0][1]) + tetrominoPreviousPosition[0][0] - tetrominoRotationOffset[tetrominoRotationStep];
            tetrominoPosition[2][1] = (tetrominoPreviousPosition[2][0] - tetrominoPreviousPosition[0][0]) + tetrominoPreviousPosition[0][1] - tetrominoRotationOffset[tetrominoRotationStep + 1];
            tetrominoPosition[3][0] = -(tetrominoPreviousPosition[3][1] - tetrominoPreviousPosition[0][1]) + tetrominoPreviousPosition[0][0] - tetrominoRotationOffset[tetrominoRotationStep];
            tetrominoPosition[3][1] = (tetrominoPreviousPosition[3][0] - tetrominoPreviousPosition[0][0]) + tetrominoPreviousPosition[0][1] - tetrominoRotationOffset[tetrominoRotationStep + 1];

            if(tetrominoRotationStep == 0) tetrominoRotationStep = 6;
            else tetrominoRotationStep -= 2;
        }else{
            tetrominoPosition[0][0] = -(tetrominoPreviousPosition[0][1] - tetrominoPreviousPosition[0][1]) + tetrominoPreviousPosition[0][0];
            tetrominoPosition[0][1] = (tetrominoPreviousPosition[0][0] - tetrominoPreviousPosition[0][0]) + tetrominoPreviousPosition[0][1];
            tetrominoPosition[1][0] = -(tetrominoPreviousPosition[1][1] - tetrominoPreviousPosition[0][1]) + tetrominoPreviousPosition[0][0];
            tetrominoPosition[1][1] = (tetrominoPreviousPosition[1][0] - tetrominoPreviousPosition[0][0]) + tetrominoPreviousPosition[0][1];
            tetrominoPosition[2][0] = -(tetrominoPreviousPosition[2][1] - tetrominoPreviousPosition[0][1]) + tetrominoPreviousPosition[0][0];
            tetrominoPosition[2][1] = (tetrominoPreviousPosition[2][0] - tetrominoPreviousPosition[0][0]) + tetrominoPreviousPosition[0][1];
            tetrominoPosition[3][0] = -(tetrominoPreviousPosition[3][1] - tetrominoPreviousPosition[0][1]) + tetrominoPreviousPosition[0][0];
            tetrominoPosition[3][1] = (tetrominoPreviousPosition[3][0] - tetrominoPreviousPosition[0][0]) + tetrominoPreviousPosition[0][1];
        }
        mapTetris[tetrominoPosition[0][0]][tetrominoPosition[0][1]] = tetrominoType;
        mapTetris[tetrominoPosition[1][0]][tetrominoPosition[1][1]] = tetrominoType;
        mapTetris[tetrominoPosition[2][0]][tetrominoPosition[2][1]] = tetrominoType;
        mapTetris[tetrominoPosition[3][0]][tetrominoPosition[3][1]] = tetrominoType;
        refreshWindow();
    }
}

void quit()
{
    //Free loaded images
    textureTetromino.clearTexture();

    //Destroy window
    SDL_DestroyRenderer(gameRenderer);
    SDL_DestroyWindow(gameWindow);
    gameWindow = NULL;
    gameRenderer = NULL;

    //Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();
}

