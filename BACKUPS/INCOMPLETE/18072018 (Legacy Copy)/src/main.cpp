#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include "game.h"


const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int playerPositionX = 240;
int playerPositionY = 190;

bool flagQuit = false;
bool flagError = false;



int main(int argc, char *argv[]){
    //initialize SDL interface and create basic window.
    flagError = createWindow(SCREEN_WIDTH, SCREEN_HEIGHT, flagError);
    //create an event handler
    SDL_Event event;
    //loop

    //Scene textures

    while(!flagQuit){
        //event queue **requires more research and study
        while(SDL_PollEvent(&event) != 0){
            //User requests quit
            if(event.type == SDL_QUIT){
                flagQuit = true;
            }
            //User presses a button
            else if(event.type == SDL_KEYDOWN){
                switch(event.key.keysym.sym){
                case SDLK_UP:
                    printf("Up");
                    playerPositionY-=4;
                    break;
                case SDLK_DOWN:
                    printf("Down");
                    playerPositionY+=4;
                    break;
                case SDLK_LEFT:
                    printf("Left");
                    playerPositionX-=4;
                    break;
                case SDLK_RIGHT:
                    printf("Right");
                    playerPositionX+=4;
                    break;
                case SDLK_z:
                    printf("Button Z");
                    break;
                case SDLK_x:
                    printf("Button X");
                    break;
                case SDLK_ESCAPE:
                    flagQuit = true;
                    break;
                default:
                    printf("Default");
                    break;
                }
            }
        }
        //display a texture onto the screen
        refreshWindow(playerPositionX, playerPositionY);
        //60 FPS timer
        //SDL_Delay(16.667);
    }
    quit();
    return 0;
}

