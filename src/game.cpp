#include "libraries.h"


SDL_Window* gameWindow = NULL;
SDL_Renderer* gameRenderer = NULL;

cTexture textureBackground;
SDL_Rect textureBackgroundClip;
cTexture textureTetromino;
SDL_Rect textureTetrominoClip[7];

int mapTetris[10][22];
int mapNext[4][2];
int tetrominoType[6];


void initializeGame(int SCREEN_WIDTH, int SCREEN_HEIGHT){
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
            if(SDL_Init(SDL_INIT_TIMER) < 0){
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
        srand(time(NULL));
        for(int i = 0; i < 5; i++){
            generateTetromino();
        }
    }
}

void loadMedia(){
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
}

void refreshWindow(){
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

    for(int i = 0; i < 5; i++){
        drawNextTetromino(i + 1);
        for(int j = 0; j < 4; j++){
            for(int k = 0; k < 2; k++){
                int clip = mapNext[j][k];
                if(clip == 0) textureTetromino.renderSprite(j * 20 + 262,  k * 20 + i * 72 + 84, &textureTetrominoClip[clip], gameRenderer);
                else if(clip == 1) textureTetromino.renderSprite(j * 20 + 262,  k * 20 + i * 72 + 94, &textureTetrominoClip[clip], gameRenderer);
                else textureTetromino.renderSprite(j * 20 + 272,  k * 20 + i * 72 + 84, &textureTetrominoClip[clip], gameRenderer);
            }
        }
    }

    SDL_RenderPresent(gameRenderer);
}

void quit(){
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

