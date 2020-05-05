#include "include/global.h"


const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int playerPositionX = 240;
int playerPositionY = 190;

bool flagError = false;
bool flagQuit = false;


int main(int argc, char *argv[])
{
    //initialize SDL interface and create basic window.
    initializeGame(SCREEN_WIDTH, SCREEN_HEIGHT);
    //create an event handler
    SDL_Event event;

    startTimer();

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
                    moveUp();
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
                    rotateCounterClockwise();
                    break;
                case SDLK_x:
                    rotateClockwise();
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
        loadMedia();
        refreshWindow();
    }
    quit();
    return 0;
}
