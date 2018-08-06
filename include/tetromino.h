#ifndef TETROMINO_H
#define TETROMINO_H


void generateTetromino();
void drawNextTetromino(int loop);
void checkClearRows();
void moveUp();
bool moveDown();
void moveLeft();
void moveRight();
void rotateClockwise();
void rotateCounterClockwise();

#endif // TETROMINO_H
