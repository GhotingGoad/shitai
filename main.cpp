#include <SDL.h>
#include <stdio.h>
#include "game.h"


const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int playerPositionX = 240;
int playerPositionY = 190;

bool flagQuit = false;
bool flagError = false;




int main(int argc, char *argv[])
{
    //initialize SDL interface and create basic window.
    flagError = initializeGame(SCREEN_WIDTH, SCREEN_HEIGHT, flagError);
    //create an event handler
    SDL_Event event;

    while(!flagQuit && !flagError)
    {
        //event queue **requires more research and study
        while(SDL_PollEvent(&event) != 0)
        {
            //User requests quit
            if(event.type == SDL_QUIT)
            {
                flagQuit = true;
            }
            //User presses a button
            else if(event.type == SDL_KEYDOWN)
            {
                switch(event.key.keysym.sym)
                {
                case SDLK_UP:
                    break;
                case SDLK_DOWN:
                    moveDown();
                    break;
                case SDLK_LEFT:
                    moveLeft();
                    break;
                case SDLK_RIGHT:
                    moveRight();
                    break;
                case SDLK_z:
                    rotateClockwise();
                    break;
                case SDLK_x:
                    rotateCounterClockwise();
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
        loadMedia(flagError);
        refreshWindow();
        //120 FPS timer delay (change to event driven timer after this)
        SDL_Delay(8.333333);
    }
    quit();
    return 0;
}

