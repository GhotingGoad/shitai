#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED



bool initializeGame(int SCREEN_WIDTH, int SCREEN_HEIGHT, bool flagError);
bool loadMedia(bool flagError);
SDL_Surface* loadSurface();
void refreshWindow();
void quit();

void moveDown();
void moveLeft();
void moveRight();
void rotateClockwise();
void rotateCounterClockwise();

#endif // GAME_H_INCLUDED
