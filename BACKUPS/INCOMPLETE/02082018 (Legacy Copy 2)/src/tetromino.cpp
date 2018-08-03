#include "tetromino.h"

tetromino::tetromino(){
}

tetromino::~tetromino(){
    tetrominoType = -1;
    tetrominoPosition[0] = 0;
    tetrominoPosition[1] = 0;
    tetrominoPosition[2] = 0;
    tetrominoPosition[3] = 0;
    tetrominoPosition[4] = 0;
    tetrominoPosition[5] = 0;
    tetrominoPosition[6] = 0;
    tetrominoPosition[7] = 0;
}

tetromino::tetrominoDown(){
    tetrominoPosition[1] +=1;
    tetrominoPosition[3] +=1;
    tetrominoPosition[5] +=1;
    tetrominoPosition[7] +=1;
}
tetromino::tetrominoUp(){
    tetrominoPosition[1] +=1;
    tetrominoPosition[3] +=1;
    tetrominoPosition[5] +=1;
    tetrominoPosition[7] +=1;
}
tetromino::tetrominoLeft(){
    tetrominoPosition[0] -=1;
    tetrominoPosition[2] -=1;
    tetrominoPosition[4] -=1;
    tetrominoPosition[6] -=1;
}
tetromino::tetrominoRight(){
    tetrominoPosition[0] +=1;
    tetrominoPosition[2] +=1;
    tetrominoPosition[4] +=1;
    tetrominoPosition[6] +=1;
}

tetromino::getTetrominoType(){
    return tetrominoType;
}
tetromino::getBlock1X(){
    return tetrominoPosition[0];
}
tetromino::getBlock1Y(){
    return tetrominoPosition[1];
}
tetromino::getBlock2X(){
    return tetrominoPosition[2];
}
tetromino::getBlock2Y(){
    return tetrominoPosition[3];
}
tetromino::getBlock3X(){
    return tetrominoPosition[4];
}
tetromino::getBlock3Y(){
    return tetrominoPosition[5];
}
tetromino::getBlock4X(){
    return tetrominoPosition[6];
}
tetromino::getBlock4Y(){
    return tetrominoPosition[7];
}
