#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

bool createWindow(int SCREEN_WIDTH, int SCREEN_HEIGHT, bool flagQuit);
SDL_Surface* loadSurface();
void refreshWindow(int playerPositionX, int playerPositionY);
void quit();

#endif // GAME_H_INCLUDED
