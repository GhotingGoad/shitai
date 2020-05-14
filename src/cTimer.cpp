#include "../global.h"


SDL_TimerID timerID;
SDL_TimerID refreshTimerID;

void startTimer(){
    timerID = SDL_AddTimer((800/10)*10, moveDown, NULL);
}

void refreshTimer(){
    refreshTimerID = SDL_AddTimer((16/10)*10, refreshTimer, NULL);
}

void restartTimer(){
    SDL_RemoveTimer(timerID);
    timerID = SDL_AddTimer((800/10)*10, restartTimer, NULL);
}

void stopTimer(){
    SDL_RemoveTimer(timerID);
    SDL_RemoveTimer(refreshTimerID);
}

Uint32 restartTimer(Uint32 interval, void* param){
    SDL_RemoveTimer(timerID);
    timerID = SDL_AddTimer((800/10)*10, moveDown, NULL);
    return(interval);
}

Uint32 moveDown(Uint32 interval, void* param){
    SDL_RemoveTimer(timerID);
    moveDown();
    timerID = SDL_AddTimer((800/10)*10 , moveDown, NULL);
    return(interval);
}

Uint32 refreshTimer(Uint32 interval, void* param){
    SDL_UserEvent userEvent;

    userEvent.type = SDL_USEREVENT;
    userEvent.code = 0;
    userEvent.data1 = NULL;
    userEvent.data2 = NULL;

    event.type = SDL_USEREVENT;
    event.user = userEvent;

    SDL_PushEvent(&event);
    return(interval);
}