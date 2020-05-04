#ifndef TETROMINO_H
#define TETROMINO_H


void generateTetromino();
void drawNextTetromino(int loop);
void checkClearRows();

//hard drop
void moveUp();
//soft drop, return true if block can move further down
bool moveDown();
//as name implies. return true if block can move further left
bool moveLeft();
//as name implies, return true if block can move further right
bool moveRight();
void rotateClockwise();
void rotateCounterClockwise();

#endif // TETROMINO_H
