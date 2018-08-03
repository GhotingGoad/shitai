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

int mapTetris[10][23];

int tetrominoType;
int tetrominoPositionX;
int tetrominoPositionY;

int tetrominoGame3[3][3];
int tetrominoGame4[4][4];
int tetrominoPrevious3[3][3];
int tetrominoPrevious4[4][4];

int tetrominoStart0[2][2] = {0, 0, 0, 0};
int tetrominoStart1[4][4] = {-1, 1, -1, -1, -1, 1, -1, -1, -1, 1, -1, -1, -1, 1, -1, -1};
int tetrominoStart2[3][3] = {-1, 2, -1, 2, 2, -1, 2, -1, -1};
int tetrominoStart3[3][3] = {-1, 3, -1, -1, 3, -1, 3, 3, -1};
int tetrominoStart4[3][3] = {-1, 4, -1, 4, 4, -1, -1, 4, -1};
int tetrominoStart5[3][3] = {5, -1, -1, 5, 5, -1, -1, 5, -1};
int tetrominoStart6[3][3] = {6, 6, -1, -1, 6, -1, -1, 6, -1};

void generateTetromino(){
    srand(time(NULL));
    tetrominoType = rand()%7;
    switch(tetrominoType){
        case 0:
            tetrominoPositionX = 4;
            tetrominoPositionY = 0;
            break;
        case 1:
            tetrominoPositionX = 3;
            tetrominoPositionY = 1;
            break;
        default:
            tetrominoPositionX = 3;
            tetrominoPositionY = 0;
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
        mapTetris[i][22] = -2;
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
    if(tetrominoType == 0){
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 2; j++){
                mapTetris[i + tetrominoPositionX][j + tetrominoPositionY] = tetrominoStart0[i][j];
            }
        }
    }else if(tetrominoType == 1){
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                mapTetris[i + tetrominoPositionX][j + tetrominoPositionY - 1] = tetrominoStart1[i][j];
            }
        }
    }else if(tetrominoType == 2){
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                mapTetris[i + tetrominoPositionX][j + tetrominoPositionY ] = tetrominoStart2[i][j];
            }
        }
    }else if(tetrominoType == 3){
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                mapTetris[i + tetrominoPositionX][j + tetrominoPositionY] = tetrominoStart3[i][j];
            }
        }
    }else if(tetrominoType == 4){
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                mapTetris[i + tetrominoPositionX][j + tetrominoPositionY] = tetrominoStart4[i][j];
            }
        }
    }else if(tetrominoType == 5){
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                mapTetris[i + tetrominoPositionX][j + tetrominoPositionY] = tetrominoStart5[i][j];
            }
        }
    }else if(tetrominoType == 6){
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                mapTetris[i + tetrominoPositionX][j + tetrominoPositionY] = tetrominoStart6[i][j];
            }
        }
    }

    printf(" \n\n ");
    for(int i = 0; i < 10; i++){
        for(int j = 2; j < 22; j++){
            int clip = mapTetris[i][j];
            if(clip<10) textureTetromino.renderSprite(i * 20 + 40, j * 20, &textureTetrominoClip[clip], gameRenderer);
            else textureTetromino.renderSprite(i * 20 + 40, j * 20, &textureTetrominoClip[clip-10], gameRenderer);
            printf(" %d ", mapTetris[i][j]);
        }
        printf(" \n ");
    }
    SDL_RenderPresent(gameRenderer);
}

void refreshPosition(){
    if(tetrominoType == 0){
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 2; j++){
                mapTetris[i + tetrominoPositionX][j + tetrominoPositionY] = -1;
            }
        }
    }else if(tetrominoType == 1){
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                mapTetris[i + tetrominoPositionX][j + tetrominoPositionY] = -1;
            }
        }
    }else{
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 2; j++){
                mapTetris[i + tetrominoPositionX][j + tetrominoPositionY] = -1;
            }
        }
    }
}

void moveDown(){
    if(mapTetris[tetrominoPositionX][tetrominoPositionY + 1] == -1 || mapTetris[tetrominoPositionX][tetrominoPositionY + 1] == tetrominoType){
        refreshPosition();
        tetrominoPositionY += 1;
    }else{
        generateTetromino();
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

