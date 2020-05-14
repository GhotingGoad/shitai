#include "../global.h"


SDL_TimerID timerID;

void startTimer(){
    timerID = SDL_AddTimer((800/10)*10, moveDown, NULL);
}

void restartTimer(){
    SDL_RemoveTimer(timerID);
    timerID = SDL_AddTimer((800/10)*10, restartTimer, NULL);
}

void stopTimer(){
    SDL_RemoveTimer(timerID);
}

Uint32 restartTimer(Uint32 interval, void* param){
    SDL_RemoveTimer(timerID);
    timerID = SDL_AddTimer((800/10)*10, moveDown, NULL);
    return 0;
}

Uint32 moveDown(Uint32 interval, void* param){
    SDL_RemoveTimer(timerID);
    moveDown();
    timerID = SDL_AddTimer((800/10)*10 , moveDown, NULL);
    return 0;
}
