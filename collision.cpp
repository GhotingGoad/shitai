#include "include/global.h"


//change the way collision works

bool checkDownCollision(){
    if(mapTetris[tetrominoPosition[0][0]][tetrominoPosition[0][1] + 1] == -1 || mapTetris[tetrominoPosition[0][0]][tetrominoPosition[0][1] + 1] == tetrominoType[0]) collisionFlag1 = false;
    else collisionFlag1 = true;
    if(mapTetris[tetrominoPosition[1][0]][tetrominoPosition[1][1] + 1] == -1 || mapTetris[tetrominoPosition[1][0]][tetrominoPosition[1][1] + 1] == tetrominoType[0]) collisionFlag2 = false;
    else collisionFlag2 = true;
    if(mapTetris[tetrominoPosition[2][0]][tetrominoPosition[2][1] + 1] == -1 || mapTetris[tetrominoPosition[2][0]][tetrominoPosition[2][1] + 1] == tetrominoType[0]) collisionFlag3 = false;
    else collisionFlag3 = true;
    if(mapTetris[tetrominoPosition[3][0]][tetrominoPosition[3][1] + 1] == -1 || mapTetris[tetrominoPosition[3][0]][tetrominoPosition[3][1] + 1] == tetrominoType[0]) collisionFlag4 = false;
    else collisionFlag4 = true;

    return (collisionFlag1 || collisionFlag2 || collisionFlag3 || collisionFlag4);
}

bool checkLeftCollision(){
    if(mapTetris[tetrominoPosition[0][0] - 1][tetrominoPosition[0][1]] == -1 || mapTetris[tetrominoPosition[0][0] - 1][tetrominoPosition[0][1]] == tetrominoType[0]) collisionFlag1 = false;
    else collisionFlag1 = true;
    if(mapTetris[tetrominoPosition[1][0] - 1][tetrominoPosition[1][1]] == -1 || mapTetris[tetrominoPosition[1][0] - 1][tetrominoPosition[1][1]] == tetrominoType[0]) collisionFlag2 = false;
    else collisionFlag2 = true;
    if(mapTetris[tetrominoPosition[2][0] - 1][tetrominoPosition[2][1]] == -1 || mapTetris[tetrominoPosition[2][0] - 1][tetrominoPosition[2][1]] == tetrominoType[0]) collisionFlag3 = false;
    else collisionFlag3 = true;
    if(mapTetris[tetrominoPosition[3][0] - 1][tetrominoPosition[3][1]] == -1 || mapTetris[tetrominoPosition[3][0] - 1][tetrominoPosition[3][1]] == tetrominoType[0]) collisionFlag4 = false;
    else collisionFlag4 = true;

    return (collisionFlag1 || collisionFlag2 || collisionFlag3 || collisionFlag4);
}

bool checkRightCollision(){
    if(mapTetris[tetrominoPosition[0][0] + 1][tetrominoPosition[0][1]] == -1 || mapTetris[tetrominoPosition[0][0] + 1][tetrominoPosition[0][1]] == tetrominoType[0]) collisionFlag1 = false;
    else collisionFlag1 = true;
    if(mapTetris[tetrominoPosition[1][0] + 1][tetrominoPosition[1][1]] == -1 || mapTetris[tetrominoPosition[1][0] + 1][tetrominoPosition[1][1]] == tetrominoType[0]) collisionFlag2 = false;
    else collisionFlag2 = true;
    if(mapTetris[tetrominoPosition[2][0] + 1][tetrominoPosition[2][1]] == -1 || mapTetris[tetrominoPosition[2][0] + 1][tetrominoPosition[2][1]] == tetrominoType[0]) collisionFlag3 = false;
    else collisionFlag3 = true;
    if(mapTetris[tetrominoPosition[3][0] + 1][tetrominoPosition[3][1]] == -1 || mapTetris[tetrominoPosition[3][0] + 1][tetrominoPosition[3][1]] == tetrominoType[0]) collisionFlag4 = false;
    else collisionFlag4 = true;

    return (collisionFlag1 || collisionFlag2 || collisionFlag3 || collisionFlag4);
}


bool checkAxisLeftCollision(){
    if(mapTetris[tetrominoPosition[0][0] - 1][tetrominoPosition[0][1]] == -1 || mapTetris[tetrominoPosition[0][0] - 1][tetrominoPosition[0][1]] == tetrominoType[0]) collisionFlag1 = false;
    else collisionFlag1 = true;

    return collisionFlag1;
}

bool checkAxisRightCollision(){
    if(mapTetris[tetrominoPosition[0][0] + 1][tetrominoPosition[0][1]] == -1 || mapTetris[tetrominoPosition[0][0] + 1][tetrominoPosition[0][1]] == tetrominoType[0]) collisionFlag1 = false;
    else collisionFlag1 = true;

    return collisionFlag1;
}


//implement spins here, return 0 for stuck, 1 for rotate, 2 for left border, 3 for right border
bool checkClockwiseCollision(){
    switch(tetrominoType[0]){
        case 0:
            break;
        case 1:
            if(mapTetris[-(tetrominoPosition[0][1] - tetrominoPosition[0][1]) + tetrominoPosition[0][0] + tetrominoRotationOffset[tetrominoRotationStep]]
            [(tetrominoPosition[0][0] - tetrominoPosition[0][0]) + tetrominoPosition[0][1] + tetrominoRotationOffset[tetrominoRotationStep + 1]] == -1
            || mapTetris[-(tetrominoPosition[0][1] - tetrominoPosition[0][1]) + tetrominoPosition[0][0] + tetrominoRotationOffset[tetrominoRotationStep]]
            [(tetrominoPosition[0][0] - tetrominoPosition[0][0]) + tetrominoPosition[0][1] + tetrominoRotationOffset[tetrominoRotationStep + 1]] == tetrominoType[0]) collisionFlag1 = false;
            else collisionFlag1 = true;
            if(mapTetris[-(tetrominoPosition[1][1] - tetrominoPosition[0][1]) + tetrominoPosition[0][0] + tetrominoRotationOffset[tetrominoRotationStep]]
            [(tetrominoPosition[1][0] - tetrominoPosition[0][0]) + tetrominoPosition[0][1] + tetrominoRotationOffset[tetrominoRotationStep + 1]] == -1
            ||mapTetris[-(tetrominoPosition[1][1] - tetrominoPosition[0][1]) + tetrominoPosition[0][0] + tetrominoRotationOffset[tetrominoRotationStep]]
            [(tetrominoPosition[1][0] - tetrominoPosition[0][0]) + tetrominoPosition[0][1] + tetrominoRotationOffset[tetrominoRotationStep + 1]] == tetrominoType[0]) collisionFlag2 = false;
            else collisionFlag2 = true;
            if(mapTetris[-(tetrominoPosition[2][1] - tetrominoPosition[0][1]) + tetrominoPosition[0][0] + tetrominoRotationOffset[tetrominoRotationStep]]
            [(tetrominoPosition[2][0] - tetrominoPosition[0][0]) + tetrominoPosition[0][1] + tetrominoRotationOffset[tetrominoRotationStep + 1]] == -1
            || mapTetris[-(tetrominoPosition[2][1] - tetrominoPosition[0][1]) + tetrominoPosition[0][0] + tetrominoRotationOffset[tetrominoRotationStep]]
            [(tetrominoPosition[2][0] - tetrominoPosition[0][0]) + tetrominoPosition[0][1] + tetrominoRotationOffset[tetrominoRotationStep + 1]] == tetrominoType[0]) collisionFlag3 = false;
            else collisionFlag3 = true;
            if(mapTetris[-(tetrominoPosition[3][1] - tetrominoPosition[0][1]) + tetrominoPosition[0][0] + tetrominoRotationOffset[tetrominoRotationStep]]
            [(tetrominoPosition[3][0] - tetrominoPosition[0][0]) + tetrominoPosition[0][1] + tetrominoRotationOffset[tetrominoRotationStep + 1]] == -1
            || mapTetris[-(tetrominoPosition[3][1] - tetrominoPosition[0][1]) + tetrominoPosition[0][0] + tetrominoRotationOffset[tetrominoRotationStep]]
            [(tetrominoPosition[3][0] - tetrominoPosition[0][0]) + tetrominoPosition[0][1] + tetrominoRotationOffset[tetrominoRotationStep + 1]] ==  tetrominoType[0]) collisionFlag4 = false;
            else collisionFlag4 = true;
            break;
        default:
            if(mapTetris[-(tetrominoPosition[0][1] - tetrominoPosition[0][1]) + tetrominoPosition[0][0]][(tetrominoPosition[0][0] - tetrominoPosition[0][0]) + tetrominoPosition[0][1]] == -1
            || mapTetris[-(tetrominoPosition[0][1] - tetrominoPosition[0][1]) + tetrominoPosition[0][0]][(tetrominoPosition[0][0] - tetrominoPosition[0][0]) + tetrominoPosition[0][1]] == tetrominoType[0]) collisionFlag1 = false;
            else collisionFlag1 = true;
            if(mapTetris[-(tetrominoPosition[1][1] - tetrominoPosition[0][1]) + tetrominoPosition[0][0]][(tetrominoPosition[1][0] - tetrominoPosition[0][0]) + tetrominoPosition[0][1]] == -1
            || mapTetris[-(tetrominoPosition[1][1] - tetrominoPosition[0][1]) + tetrominoPosition[0][0]][(tetrominoPosition[1][0] - tetrominoPosition[0][0]) + tetrominoPosition[0][1]] == tetrominoType[0]) collisionFlag2 = false;
            else collisionFlag2 = true;
            if(mapTetris[-(tetrominoPosition[2][1] - tetrominoPosition[0][1]) + tetrominoPosition[0][0]][(tetrominoPosition[2][0] - tetrominoPosition[0][0]) + tetrominoPosition[0][1]] == -1
            || mapTetris[-(tetrominoPosition[2][1] - tetrominoPosition[0][1]) + tetrominoPosition[0][0]][(tetrominoPosition[2][0] - tetrominoPosition[0][0]) + tetrominoPosition[0][1]] == tetrominoType[0]) collisionFlag3 = false;
            else collisionFlag3 = true;
            if(mapTetris[-(tetrominoPosition[3][1] - tetrominoPosition[0][1]) + tetrominoPosition[0][0]][(tetrominoPosition[3][0] - tetrominoPosition[0][0]) + tetrominoPosition[0][1]] == -1
            || mapTetris[-(tetrominoPosition[3][1] - tetrominoPosition[0][1]) + tetrominoPosition[0][0]][(tetrominoPosition[3][0] - tetrominoPosition[0][0]) + tetrominoPosition[0][1]] == tetrominoType[0]) collisionFlag4 = false;
            else collisionFlag4 = true;
            break;
    }
    return (collisionFlag1 || collisionFlag2 || collisionFlag3 || collisionFlag4);
}

bool checkCounterClockwiseCollision(){
    switch(tetrominoType[0]){
        case 0:
            break;
        case 1:
            if(mapTetris[(tetrominoPosition[0][1] - tetrominoPosition[0][1]) + tetrominoPosition[0][0] + tetrominoRotationOffset[tetrominoRotationStep + 6]]
            [-(tetrominoPosition[0][0] - tetrominoPosition[0][0]) + tetrominoPosition[0][1] + tetrominoRotationOffset[tetrominoRotationStep + 7]] == -1
            || mapTetris[(tetrominoPosition[0][1] - tetrominoPosition[0][1]) + tetrominoPosition[0][0] + tetrominoRotationOffset[tetrominoRotationStep + 6]]
            [-(tetrominoPosition[0][0] - tetrominoPosition[0][0]) + tetrominoPosition[0][1] + tetrominoRotationOffset[tetrominoRotationStep + 7]] == tetrominoType[0]) collisionFlag1 = false;
            else collisionFlag1 = true;
            if(mapTetris[(tetrominoPosition[1][1] - tetrominoPosition[0][1]) + tetrominoPosition[0][0] + tetrominoRotationOffset[tetrominoRotationStep + 6]]
            [-(tetrominoPosition[1][0] - tetrominoPosition[0][0]) + tetrominoPosition[0][1] + tetrominoRotationOffset[tetrominoRotationStep + 7]] == -1
            || mapTetris[(tetrominoPosition[1][1] - tetrominoPosition[0][1]) + tetrominoPosition[0][0] + tetrominoRotationOffset[tetrominoRotationStep + 6]]
            [-(tetrominoPosition[1][0] - tetrominoPosition[0][0]) + tetrominoPosition[0][1] + tetrominoRotationOffset[tetrominoRotationStep + 7]] == tetrominoType[0]) collisionFlag2 = false;
            else collisionFlag2 = true;
            if(mapTetris[(tetrominoPosition[2][1] - tetrominoPosition[0][1]) + tetrominoPosition[0][0] + tetrominoRotationOffset[tetrominoRotationStep + 6]]
            [-(tetrominoPosition[2][0] - tetrominoPosition[0][0]) + tetrominoPosition[0][1] + tetrominoRotationOffset[tetrominoRotationStep + 7]] == -1
            || mapTetris[(tetrominoPosition[2][1] - tetrominoPosition[0][1]) + tetrominoPosition[0][0] + tetrominoRotationOffset[tetrominoRotationStep + 6]]
            [-(tetrominoPosition[2][0] - tetrominoPosition[0][0]) + tetrominoPosition[0][1] + tetrominoRotationOffset[tetrominoRotationStep + 7]] == tetrominoType[0]) collisionFlag3 = false;
            else collisionFlag3 = true;
            if(mapTetris[(tetrominoPosition[3][1] - tetrominoPosition[0][1]) + tetrominoPosition[0][0] + tetrominoRotationOffset[tetrominoRotationStep + 6]]
            [-(tetrominoPosition[3][0] - tetrominoPosition[0][0]) + tetrominoPosition[0][1] + tetrominoRotationOffset[tetrominoRotationStep + 7]] == -1
            || mapTetris[(tetrominoPosition[3][1] - tetrominoPosition[0][1]) + tetrominoPosition[0][0] + tetrominoRotationOffset[tetrominoRotationStep + 6]]
            [-(tetrominoPosition[3][0] - tetrominoPosition[0][0]) + tetrominoPosition[0][1] + tetrominoRotationOffset[tetrominoRotationStep + 7]] == tetrominoType[0]) collisionFlag4 = false;
            else collisionFlag4 = true;
            break;
        default:
            if(mapTetris[(tetrominoPosition[0][1] - tetrominoPosition[0][1]) + tetrominoPosition[0][0]][-(tetrominoPosition[0][0] - tetrominoPosition[0][0]) + tetrominoPosition[0][1]] == -1
            || mapTetris[(tetrominoPosition[0][1] - tetrominoPosition[0][1]) + tetrominoPosition[0][0]][-(tetrominoPosition[0][0] - tetrominoPosition[0][0]) + tetrominoPosition[0][1]] == tetrominoType[0]) collisionFlag1 = false;
            else collisionFlag1 = true;
            if(mapTetris[(tetrominoPosition[1][1] - tetrominoPosition[0][1]) + tetrominoPosition[0][0]][-(tetrominoPosition[1][0] - tetrominoPosition[0][0]) + tetrominoPosition[0][1]] == -1
            || mapTetris[(tetrominoPosition[1][1] - tetrominoPosition[0][1]) + tetrominoPosition[0][0]][-(tetrominoPosition[1][0] - tetrominoPosition[0][0]) + tetrominoPosition[0][1]] == tetrominoType[0]) collisionFlag2 = false;
            else collisionFlag2 = true;
            if(mapTetris[(tetrominoPosition[2][1] - tetrominoPosition[0][1]) + tetrominoPosition[0][0]][-(tetrominoPosition[2][0] - tetrominoPosition[0][0]) + tetrominoPosition[0][1]] == -1
            || mapTetris[(tetrominoPosition[2][1] - tetrominoPosition[0][1]) + tetrominoPosition[0][0]][-(tetrominoPosition[2][0] - tetrominoPosition[0][0]) + tetrominoPosition[0][1]] == tetrominoType[0]) collisionFlag3 = false;
            else collisionFlag3 = true;
            if(mapTetris[(tetrominoPosition[3][1] - tetrominoPosition[0][1]) + tetrominoPosition[0][0]][-(tetrominoPosition[3][0] - tetrominoPosition[0][0]) + tetrominoPosition[0][1]] == -1
            || mapTetris[(tetrominoPosition[3][1] - tetrominoPosition[0][1]) + tetrominoPosition[0][0]][-(tetrominoPosition[3][0] - tetrominoPosition[0][0]) + tetrominoPosition[0][1]] == tetrominoType[0]) collisionFlag4 = false;
            else collisionFlag4 = true;
            break;
    }
    return (collisionFlag1 || collisionFlag2 || collisionFlag3 || collisionFlag4);
}
