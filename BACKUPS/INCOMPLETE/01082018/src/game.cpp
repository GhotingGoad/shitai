#include <SDL.h>
#include <stdio.h>
#include <string>
#include "wTexture.h"
#include "tetromino.h"
#include <math.h>

SDL_Window* gameWindow = NULL;
SDL_Renderer* gameRenderer = NULL;

wTexture textureBackground;
SDL_Rect textureBackgroundClips;
wTexture textureTetrominos;
SDL_Rect textureTetrominosClips[7];

int mapTetris[22][10];

tetromino gameBlock;
bool block1Collision;
bool block2Collision;
bool block3Collision;
bool block4Collision;

int rotationStep = 2;
int rotationTable[6] = {1, 1, -1, -1, 1, 1};

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
                printf("Window successfully created.");
            }
        }
    }
    for(int i = 0; i < 22; i++){
        for(int j = 0; j < 10; j++){
            mapTetris[i][j] = -1;
        }
    }
    gameBlock.random();
    return flagError;
}

bool loadMedia(bool flagError)
{
    if(!textureBackground.loadFromFile("media/background.png", gameRenderer)){
        printf("Failed to load Background image!\n");
        flagError = true;
    }
    else{
        if(!textureTetrominos.loadFromFile("media/blocks.png", gameRenderer)){
            printf("Failed to load Blocks image!\n");
            flagError = true;
        }else{
            textureTetrominosClips[0].x = 0;
            textureTetrominosClips[0].w = 20;
            textureTetrominosClips[0].h = 20;

            textureTetrominosClips[1].x = 20;
            textureTetrominosClips[1].w = 20;
            textureTetrominosClips[1].h = 20;

            textureTetrominosClips[2].x = 40;
            textureTetrominosClips[2].w = 20;
            textureTetrominosClips[2].h = 20;

            textureTetrominosClips[3].x = 60;
            textureTetrominosClips[3].w = 20;
            textureTetrominosClips[3].h = 20;

            textureTetrominosClips[4].x = 80;
            textureTetrominosClips[4].w = 20;
            textureTetrominosClips[4].h = 20;

            textureTetrominosClips[5].x = 100;
            textureTetrominosClips[5].w = 20;
            textureTetrominosClips[5].h = 20;

            textureTetrominosClips[6].x = 120;
            textureTetrominosClips[6].w = 20;
            textureTetrominosClips[6].h = 20;
        }
    }

    return flagError;
}

void refreshWindow()
{
    SDL_RenderClear(gameRenderer);

    //textureBackground.renderBackground(gameRenderer);
    textureBackground.renderBackground(gameRenderer);


    mapTetris[gameBlock.getBlock1Y()][gameBlock.getBlock1X()] = gameBlock.getTetrominoType();
    mapTetris[gameBlock.getBlock2Y()][gameBlock.getBlock2X()] = gameBlock.getTetrominoType();
    mapTetris[gameBlock.getBlock3Y()][gameBlock.getBlock3X()] = gameBlock.getTetrominoType();
    mapTetris[gameBlock.getBlock4Y()][gameBlock.getBlock4X()] = gameBlock.getTetrominoType();

    //Render Player Sprite to the screen
    //printf is for debugging, used to see what is in the game array
    for(int i = 2; i < 22; i++){
        for(int j = 0; j < 10; j++){
            int clip = mapTetris[i][j];
            if(clip<10) textureTetrominos.renderSprite(40 + j*20, i*20, &textureTetrominosClips[clip], gameRenderer);
            else textureTetrominos.renderSprite(40 + j*20, i*20, &textureTetrominosClips[clip-10], gameRenderer);
        }
    }
    //Update screen
    SDL_RenderPresent(gameRenderer);
}

void tetrominoRefresh(){
    mapTetris[gameBlock.getBlock1Y()][gameBlock.getBlock1X()] = -1;
    mapTetris[gameBlock.getBlock2Y()][gameBlock.getBlock2X()] = -1;
    mapTetris[gameBlock.getBlock3Y()][gameBlock.getBlock3X()] = -1;
    mapTetris[gameBlock.getBlock4Y()][gameBlock.getBlock4X()] = -1;
}

void tetrominoNextBlock(){
    mapTetris[gameBlock.getBlock1Y()][gameBlock.getBlock1X()] += 10;
    mapTetris[gameBlock.getBlock2Y()][gameBlock.getBlock2X()] += 10;
    mapTetris[gameBlock.getBlock3Y()][gameBlock.getBlock3X()] += 10;
    mapTetris[gameBlock.getBlock4Y()][gameBlock.getBlock4X()] += 10;
}

void tetrominoMoveUp(){
    tetrominoRefresh();
    gameBlock.tetrominoUp();
}

void tetrominoMoveDown(){
    if(gameBlock.getBlock1Y() != 21 && gameBlock.getBlock2Y() != 21 && gameBlock.getBlock3Y() != 21 && gameBlock.getBlock4Y() != 21){
        if(mapTetris[gameBlock.getBlock1Y() +1][gameBlock.getBlock1X()] == -1 || mapTetris[gameBlock.getBlock1Y() +1][gameBlock.getBlock1X()] == gameBlock.getTetrominoType()){
            block1Collision = false;
        }else{block1Collision = true;
        }
        if(mapTetris[gameBlock.getBlock2Y() +1][gameBlock.getBlock2X()] == -1 || mapTetris[gameBlock.getBlock2Y() +1][gameBlock.getBlock2X()] == gameBlock.getTetrominoType()){
            block2Collision = false;
        }else{block2Collision = true;
        }
        if(mapTetris[gameBlock.getBlock3Y() +1][gameBlock.getBlock3X()] == -1 || mapTetris[gameBlock.getBlock3Y() +1][gameBlock.getBlock3X()] == gameBlock.getTetrominoType()){
            block3Collision = false;
        }else{block3Collision = true;
        }
        if(mapTetris[gameBlock.getBlock4Y() +1][gameBlock.getBlock4X()] == -1 || mapTetris[gameBlock.getBlock4Y() +1][gameBlock.getBlock4X()] == gameBlock.getTetrominoType()){
            block4Collision = false;
        }else{block4Collision = true;
        }

        if(!block1Collision && !block2Collision && !block3Collision && !block4Collision){
            tetrominoRefresh();
            gameBlock.tetrominoDown();
        }else{
            tetrominoNextBlock();
            gameBlock.random();
        }
    }else{
        tetrominoNextBlock();
        gameBlock.random();
        rotationStep = 2;
    }
}

void tetrominoMoveLeft(){
    if(gameBlock.getBlock1X() != 0 && gameBlock.getBlock2X() != 0 && gameBlock.getBlock3X() != 0 && gameBlock.getBlock4X() != 0){
        if(mapTetris[gameBlock.getBlock1Y()][gameBlock.getBlock1X() - 1] == -1 || mapTetris[gameBlock.getBlock1Y()][gameBlock.getBlock1X() - 1] == gameBlock.getTetrominoType()){
            block1Collision = false;
        }else{block1Collision = true;
        }
        if(mapTetris[gameBlock.getBlock2Y()][gameBlock.getBlock2X() - 1] == -1 || mapTetris[gameBlock.getBlock2Y()][gameBlock.getBlock2X() - 1] == gameBlock.getTetrominoType()){
            block2Collision = false;
        }else{block2Collision = true;
        }
        if(mapTetris[gameBlock.getBlock3Y()][gameBlock.getBlock3X() - 1] == -1 || mapTetris[gameBlock.getBlock3Y()][gameBlock.getBlock3X() - 1] == gameBlock.getTetrominoType()){
            block3Collision = false;
        }else{block3Collision = true;
        }
        if(mapTetris[gameBlock.getBlock4Y()][gameBlock.getBlock4X() - 1] == -1 || mapTetris[gameBlock.getBlock4Y()][gameBlock.getBlock4X() - 1] == gameBlock.getTetrominoType()){
            block4Collision = false;
        }else{block4Collision = true;
        }
        if(!block1Collision && !block2Collision && !block3Collision && !block4Collision){
            tetrominoRefresh();
            gameBlock.tetrominoLeft();
        }
    }
}

void tetrominoMoveRight(){
    if(gameBlock.getBlock1X() != 9 && gameBlock.getBlock2X() != 9 && gameBlock.getBlock3X() != 9 && gameBlock.getBlock4X() != 9){
        if(mapTetris[gameBlock.getBlock1Y()][gameBlock.getBlock1X() + 1] == -1 || mapTetris[gameBlock.getBlock1Y()][gameBlock.getBlock1X() + 1] == gameBlock.getTetrominoType()){
            block1Collision = false;
        }else{block1Collision = true;
        }
        if(mapTetris[gameBlock.getBlock2Y()][gameBlock.getBlock2X() + 1] == -1 || mapTetris[gameBlock.getBlock2Y()][gameBlock.getBlock2X() + 1] == gameBlock.getTetrominoType()){
            block2Collision = false;
        }else{block2Collision = true;
        }
        if(mapTetris[gameBlock.getBlock3Y()][gameBlock.getBlock3X() + 1] == -1 || mapTetris[gameBlock.getBlock3Y()][gameBlock.getBlock3X() + 1] == gameBlock.getTetrominoType()){
            block3Collision = false;
        }else{block3Collision = true;
        }
        if(mapTetris[gameBlock.getBlock4Y()][gameBlock.getBlock4X() + 1] == -1 || mapTetris[gameBlock.getBlock4Y()][gameBlock.getBlock4X() + 1] == gameBlock.getTetrominoType()){
            block4Collision = false;
        }else{block4Collision = true;
        }
        if(!block1Collision && !block2Collision && !block3Collision && !block4Collision){
            tetrominoRefresh();
            gameBlock.tetrominoRight();
        }
    }
}

void tetrominoRotateLeft(){
    tetrominoRefresh();
    switch(gameBlock.getTetrominoType()){
        case 1:
            gameBlock.tetrominoPosition[2] += rotationTable[rotationStep];
            gameBlock.tetrominoPosition[3] += rotationTable[rotationStep + 1];
            gameBlock.tetrominoPosition[4] += 2*rotationTable[rotationStep];
            gameBlock.tetrominoPosition[5] += 2*rotationTable[rotationStep + 1];
            gameBlock.tetrominoPosition[6] += 3*rotationTable[rotationStep];
            gameBlock.tetrominoPosition[7] += 3*rotationTable[rotationStep + 1];
            if(rotationStep == 4) rotationStep = 1;
            else rotationStep += 1;
            printf(" %d ", rotationStep);
            break;

    }
}

void tetrominoRotateRight(){
    tetrominoRefresh();
    switch(gameBlock.getTetrominoType()){
        case 1:
            gameBlock.tetrominoPosition[2] -= rotationTable[rotationStep - 1];
            gameBlock.tetrominoPosition[3] -= rotationTable[rotationStep];
            gameBlock.tetrominoPosition[4] -= 2*rotationTable[rotationStep - 1];
            gameBlock.tetrominoPosition[5] -= 2*rotationTable[rotationStep];
            gameBlock.tetrominoPosition[6] -= 3*rotationTable[rotationStep - 1];
            gameBlock.tetrominoPosition[7] -= 3*rotationTable[rotationStep];
            if(rotationStep == 1) rotationStep = 4;
            else rotationStep -= 1;
            printf(" %d ", rotationStep);
    }
}

void quit()
{
    //Free loaded images
    textureTetrominos.clearTexture();

    //Destroy window
    SDL_DestroyRenderer(gameRenderer);
    SDL_DestroyWindow(gameWindow);
    gameWindow = NULL;
    gameRenderer = NULL;

    //Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();
}

