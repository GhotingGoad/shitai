#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED


void initializeGame(int SCREEN_WIDTH, int SCREEN_HEIGHT);
void loadMedia();
SDL_Surface* loadSurface();
void refreshWindow();
void quit();

#endif // GAME_H_INCLUDED
