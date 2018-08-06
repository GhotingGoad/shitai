#include "libraries.h"


//individual collision block for Player controlled Tetromino
bool collisionFlag1;
bool collisionFlag2;
bool collisionFlag3;
bool collisionFlag4;

//00 = block1x, 01 = block1y, 10 = block2x, 11 = block2y etc etc
int tetrominoPosition[4][2];
int tetrominoPreviousPosition[4][2];
//offset and step for Tetromino I SRS
int tetrominoRotationStep;
int tetrominoRotationOffset[8] = {0, 1, 1, 0, 0, -1, -1, 0};


void generateTetromino(){
    for(int i = 0; i < 5; i++) tetrominoType[i] = tetrominoType[i + 1];
    tetrominoType[5] = rand()%7;

    switch(tetrominoType[0]){
        case 0:
            mapTetris[4][0] = 0;
            mapTetris[5][0] = 0;
            mapTetris[4][1] = 0;
            mapTetris[5][1] = 0;

            tetrominoPosition[0][0] = 4;
            tetrominoPosition[0][1] = 0;
            tetrominoPosition[1][0] = 5;
            tetrominoPosition[1][1] = 0;
            tetrominoPosition[2][0] = 4;
            tetrominoPosition[2][1] = 1;
            tetrominoPosition[3][0] = 5;
            tetrominoPosition[3][1] = 1;
            break;
        case 1:
            mapTetris[3][1] = 1;
            mapTetris[4][1] = 1;
            mapTetris[5][1] = 1;
            mapTetris[6][1] = 1;

            tetrominoPosition[0][0] = 4;
            tetrominoPosition[0][1] = 1;
            tetrominoPosition[1][0] = 3;
            tetrominoPosition[1][1] = 1;
            tetrominoPosition[2][0] = 5;
            tetrominoPosition[2][1] = 1;
            tetrominoPosition[3][0] = 6;
            tetrominoPosition[3][1] = 1;

            tetrominoRotationStep = 0;
            break;
        case 2:
            mapTetris[3][0] = 2;
            mapTetris[4][0] = 2;
            mapTetris[4][1] = 2;
            mapTetris[5][1] = 2;

            tetrominoPosition[0][0] = 4;
            tetrominoPosition[0][1] = 1;
            tetrominoPosition[1][0] = 3;
            tetrominoPosition[1][1] = 0;
            tetrominoPosition[2][0] = 4;
            tetrominoPosition[2][1] = 0;
            tetrominoPosition[3][0] = 5;
            tetrominoPosition[3][1] = 1;
            break;
        case 3:
            mapTetris[3][0] = 3;
            mapTetris[3][1] = 3;
            mapTetris[4][1] = 3;
            mapTetris[5][1] = 3;

            tetrominoPosition[0][0] = 4;
            tetrominoPosition[0][1] = 1;
            tetrominoPosition[1][0] = 3;
            tetrominoPosition[1][1] = 0;
            tetrominoPosition[2][0] = 3;
            tetrominoPosition[2][1] = 1;
            tetrominoPosition[3][0] = 5;
            tetrominoPosition[3][1] = 1;
            break;
        case 4:
            mapTetris[4][0] = 4;
            mapTetris[3][1] = 4;
            mapTetris[4][1] = 4;
            mapTetris[5][1] = 4;

            tetrominoPosition[0][0] = 4;
            tetrominoPosition[0][1] = 1;
            tetrominoPosition[1][0] = 3;
            tetrominoPosition[1][1] = 1;
            tetrominoPosition[2][0] = 4;
            tetrominoPosition[2][1] = 0;
            tetrominoPosition[3][0] = 5;
            tetrominoPosition[3][1] = 1;
            break;
        case 5:
            mapTetris[4][0] = 5;
            mapTetris[5][0] = 5;
            mapTetris[3][1] = 5;
            mapTetris[4][1] = 5;

            tetrominoPosition[0][0] = 4;
            tetrominoPosition[0][1] = 1;
            tetrominoPosition[1][0] = 4;
            tetrominoPosition[1][1] = 0;
            tetrominoPosition[2][0] = 5;
            tetrominoPosition[2][1] = 0;
            tetrominoPosition[3][0] = 3;
            tetrominoPosition[3][1] = 1;
            break;
        case 6:
            mapTetris[5][0] = 6;
            mapTetris[3][1] = 6;
            mapTetris[4][1] = 6;
            mapTetris[5][1] = 6;

            tetrominoPosition[0][0] = 4;
            tetrominoPosition[0][1] = 1;
            tetrominoPosition[1][0] = 3;
            tetrominoPosition[1][1] = 1;
            tetrominoPosition[2][0] = 5;
            tetrominoPosition[2][1] = 0;
            tetrominoPosition[3][0] = 5;
            tetrominoPosition[3][1] = 1;
            break;
    };
}

void drawNextTetromino(int loop){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 2; j++){
            mapNext[i][j] = -1;
        }
    }

    switch(tetrominoType[loop]){
        case 0:
            mapNext[1][0] = 0;
            mapNext[2][0] = 0;
            mapNext[1][1] = 0;
            mapNext[2][1] = 0;
            break;
        case 1:
            mapNext[0][0] = 1;
            mapNext[1][0] = 1;
            mapNext[2][0] = 1;
            mapNext[3][0] = 1;
            break;
        case 2:
            mapNext[0][0] = 2;
            mapNext[1][0] = 2;
            mapNext[1][1] = 2;
            mapNext[2][1] = 2;
            break;
        case 3:
            mapNext[0][0] = 3;
            mapNext[0][1] = 3;
            mapNext[1][1] = 3;
            mapNext[2][1] = 3;
            break;
        case 4:
            mapNext[1][0] = 4;
            mapNext[0][1] = 4;
            mapNext[1][1] = 4;
            mapNext[2][1] = 4;
            break;
        case 5:
            mapNext[1][0] = 5;
            mapNext[2][0] = 5;
            mapNext[0][1] = 5;
            mapNext[1][1] = 5;
            break;
        case 6:
            mapNext[0][1] = 6;
            mapNext[1][1] = 6;
            mapNext[2][1] = 6;
            mapNext[2][0] = 6;
            break;
    };
}

void checkClearRows(){

    int rowEmptyCount[22] = {};
    int rowEmptyNumber[4] = {};
    int rowEmptyNumberCount = 0;
    int rowEmptyNumberLoop = 0;

    for(int i = 21; i != 0; i--){
        for(int j = 0; j <10; j++){
            if(mapTetris[j][i] == -1) rowEmptyCount[i]++;
        }
        if(rowEmptyCount[i] == 0){
            for(int j = 0; j <10; j++){
                mapTetris[j][i] = -1;
                rowEmptyNumber[rowEmptyNumberCount] = i;
            }
            rowEmptyNumberCount++;
            rowEmptyCount[i] = 0;
        }
    }
    rowEmptyNumberLoop = rowEmptyNumberCount;
    for(int k = 0; k < rowEmptyNumberLoop; k++){
        //find place to put rowEmptyNumberCount = 0;
        rowEmptyNumberCount = 0;
        for(int i = rowEmptyNumber[rowEmptyNumberCount]; i != 0; i--){
            for(int j = 0; j <10; j++){
                mapTetris[j][i] = mapTetris[j][i - 1];
            }
        }
        rowEmptyNumberCount++;
    }
}

void moveUp(){
    for(int i = 0; i < 22; i ++){
        if(moveDown()) break;
    }
}

bool moveDown(){
    if(tetrominoPosition[0][1] + 1 != 22 && tetrominoPosition[1][1] + 1 != 22 && tetrominoPosition[2][1] + 1 != 22 && tetrominoPosition[3][1] + 1 != 22){
        if(mapTetris[tetrominoPosition[0][0]][tetrominoPosition[0][1] + 1] == -1 || mapTetris[tetrominoPosition[0][0]][tetrominoPosition[0][1] + 1] == tetrominoType[0]){
            collisionFlag1 = true;
        }else{
            collisionFlag1 = false;
        }
        if(mapTetris[tetrominoPosition[1][0]][tetrominoPosition[1][1] + 1] == -1 || mapTetris[tetrominoPosition[1][0]][tetrominoPosition[1][1] + 1] == tetrominoType[0]){
            collisionFlag2 = true;
        }else{
            collisionFlag2 = false;
        }
        if(mapTetris[tetrominoPosition[2][0]][tetrominoPosition[2][1] + 1] == -1 || mapTetris[tetrominoPosition[2][0]][tetrominoPosition[2][1] + 1] == tetrominoType[0]){
            collisionFlag3 = true;
        }else{
            collisionFlag3 = false;
        }
        if(mapTetris[tetrominoPosition[3][0]][tetrominoPosition[3][1] + 1] == -1 || mapTetris[tetrominoPosition[3][0]][tetrominoPosition[3][1] + 1] == tetrominoType[0]){
            collisionFlag4 = true;
        }else{
            collisionFlag4 = false;
        }

        if(collisionFlag1 && collisionFlag2 && collisionFlag3 && collisionFlag4){
            mapTetris[tetrominoPosition[0][0]][tetrominoPosition[0][1]] = -1;
            mapTetris[tetrominoPosition[1][0]][tetrominoPosition[1][1]] = -1;
            mapTetris[tetrominoPosition[2][0]][tetrominoPosition[2][1]] = -1;
            mapTetris[tetrominoPosition[3][0]][tetrominoPosition[3][1]] = -1;

            mapTetris[tetrominoPosition[0][0]][tetrominoPosition[0][1] + 1] = tetrominoType[0];
            mapTetris[tetrominoPosition[1][0]][tetrominoPosition[1][1] + 1] = tetrominoType[0];
            mapTetris[tetrominoPosition[2][0]][tetrominoPosition[2][1] + 1] = tetrominoType[0];
            mapTetris[tetrominoPosition[3][0]][tetrominoPosition[3][1] + 1] = tetrominoType[0];

            tetrominoPosition[0][1] += 1;
            tetrominoPosition[1][1] += 1;
            tetrominoPosition[2][1] += 1;
            tetrominoPosition[3][1] += 1;
        }else{
            mapTetris[tetrominoPosition[0][0]][tetrominoPosition[0][1]] = tetrominoType[0] + 10;
            mapTetris[tetrominoPosition[1][0]][tetrominoPosition[1][1]] = tetrominoType[0] + 10;
            mapTetris[tetrominoPosition[2][0]][tetrominoPosition[2][1]] = tetrominoType[0] + 10;
            mapTetris[tetrominoPosition[3][0]][tetrominoPosition[3][1]] = tetrominoType[0] + 10;

            checkClearRows();

            generateTetromino();
            return true;
        }
    }else{
        mapTetris[tetrominoPosition[0][0]][tetrominoPosition[0][1]] = tetrominoType[0] + 10;
        mapTetris[tetrominoPosition[1][0]][tetrominoPosition[1][1]] = tetrominoType[0] + 10;
        mapTetris[tetrominoPosition[2][0]][tetrominoPosition[2][1]] = tetrominoType[0] + 10;
        mapTetris[tetrominoPosition[3][0]][tetrominoPosition[3][1]] = tetrominoType[0] + 10;

        checkClearRows();

        generateTetromino();
        return true;
    }
    return false;
}

void moveLeft(){
    if(mapTetris[tetrominoPosition[0][0] - 1][tetrominoPosition[0][1]] == -1 || mapTetris[tetrominoPosition[0][0] - 1][tetrominoPosition[0][1]] == tetrominoType[0]){
        if(tetrominoPosition[0][0]  != 0) collisionFlag1 = false;
        else collisionFlag1 = true;
    }else{
        collisionFlag1 = true;
    }
    if(mapTetris[tetrominoPosition[1][0] - 1][tetrominoPosition[1][1]] == -1 || mapTetris[tetrominoPosition[1][0] - 1][tetrominoPosition[1][1]] == tetrominoType[0]){
        if(tetrominoPosition[1][0] != 0) collisionFlag2 = false;
        else collisionFlag2 = true;
    }else{
        collisionFlag2 = true;
    }
    if(mapTetris[tetrominoPosition[2][0] - 1][tetrominoPosition[2][1]] == -1 || mapTetris[tetrominoPosition[2][0] - 1][tetrominoPosition[2][1]] == tetrominoType[0]){
        if(tetrominoPosition[2][0] != 0) collisionFlag3 = false;
        else collisionFlag3 = true;
    }else{
        collisionFlag3 = true;
    }
    if(mapTetris[tetrominoPosition[3][0] - 1][tetrominoPosition[3][1]] == -1 || mapTetris[tetrominoPosition[3][0] - 1][tetrominoPosition[3][1]] == tetrominoType[0]){
        if(tetrominoPosition[3][0] != 0) collisionFlag4 = false;
        else collisionFlag4 = true;
    }else{
        collisionFlag4 = true;
    }

    if(!collisionFlag1 && !collisionFlag2 && !collisionFlag3 && !collisionFlag4){
        mapTetris[tetrominoPosition[0][0]][tetrominoPosition[0][1]] = -1;
        mapTetris[tetrominoPosition[1][0]][tetrominoPosition[1][1]] = -1;
        mapTetris[tetrominoPosition[2][0]][tetrominoPosition[2][1]] = -1;
        mapTetris[tetrominoPosition[3][0]][tetrominoPosition[3][1]] = -1;

        mapTetris[tetrominoPosition[0][0] - 1][tetrominoPosition[0][1]] = tetrominoType[0];
        mapTetris[tetrominoPosition[1][0] - 1][tetrominoPosition[1][1]] = tetrominoType[0];
        mapTetris[tetrominoPosition[2][0] - 1][tetrominoPosition[2][1]] = tetrominoType[0];
        mapTetris[tetrominoPosition[3][0] - 1][tetrominoPosition[3][1]] = tetrominoType[0];

        tetrominoPosition[0][0] -= 1;
        tetrominoPosition[1][0] -= 1;
        tetrominoPosition[2][0] -= 1;
        tetrominoPosition[3][0] -= 1;
    }
    refreshWindow();
}

void moveRight(){
    if(mapTetris[tetrominoPosition[0][0] + 1][tetrominoPosition[0][1]] == -1 || mapTetris[tetrominoPosition[0][0] + 1][tetrominoPosition[0][1]] == tetrominoType[0]){
        if(tetrominoPosition[0][0]  != 9) collisionFlag1 = false;
        else collisionFlag1 = true;
    }else{
        collisionFlag1 = true;
    }
    if(mapTetris[tetrominoPosition[1][0] + 1][tetrominoPosition[1][1]] == -1 || mapTetris[tetrominoPosition[1][0] + 1][tetrominoPosition[1][1]] == tetrominoType[0]){
        if(tetrominoPosition[1][0] != 9) collisionFlag2 = false;
        else collisionFlag2 = true;
    }else{
        collisionFlag2 = true;
    }
    if(mapTetris[tetrominoPosition[2][0] + 1][tetrominoPosition[2][1]] == -1 || mapTetris[tetrominoPosition[2][0] + 1][tetrominoPosition[2][1]] == tetrominoType[0]){
        if(tetrominoPosition[2][0] != 9) collisionFlag3 = false;
        else collisionFlag3 = true;
    }else{
        collisionFlag3 = true;
    }
    if(mapTetris[tetrominoPosition[3][0] + 1][tetrominoPosition[3][1]] == -1 || mapTetris[tetrominoPosition[3][0] + 1][tetrominoPosition[3][1]] == tetrominoType[0]){
        if(tetrominoPosition[3][0] != 9) collisionFlag4 = false;
        else collisionFlag4 = true;
    }else{
        collisionFlag4 = true;
    }

    if(!collisionFlag1 && !collisionFlag2 && !collisionFlag3 && !collisionFlag4){
        mapTetris[tetrominoPosition[0][0]][tetrominoPosition[0][1]] = -1;
        mapTetris[tetrominoPosition[1][0]][tetrominoPosition[1][1]] = -1;
        mapTetris[tetrominoPosition[2][0]][tetrominoPosition[2][1]] = -1;
        mapTetris[tetrominoPosition[3][0]][tetrominoPosition[3][1]] = -1;

        mapTetris[tetrominoPosition[0][0] + 1][tetrominoPosition[0][1]] = tetrominoType[0];
        mapTetris[tetrominoPosition[1][0] + 1][tetrominoPosition[1][1]] = tetrominoType[0];
        mapTetris[tetrominoPosition[2][0] + 1][tetrominoPosition[2][1]] = tetrominoType[0];
        mapTetris[tetrominoPosition[3][0] + 1][tetrominoPosition[3][1]] = tetrominoType[0];

        tetrominoPosition[0][0] += 1;
        tetrominoPosition[1][0] += 1;
        tetrominoPosition[2][0] += 1;
        tetrominoPosition[3][0] += 1;
    }
    refreshWindow();
}

void rotateClockwise(){
    if(tetrominoType[0] != 0){
        if(tetrominoPosition[0][0] == 0) moveRight();
        if(tetrominoPosition[0][0] == 9) moveLeft();

         tetrominoPreviousPosition[0][0] = tetrominoPosition[0][0];
        tetrominoPreviousPosition[0][1] = tetrominoPosition[0][1];
        tetrominoPreviousPosition[1][0] = tetrominoPosition[1][0];
        tetrominoPreviousPosition[1][1] = tetrominoPosition[1][1];
        tetrominoPreviousPosition[2][0] = tetrominoPosition[2][0];
        tetrominoPreviousPosition[2][1] = tetrominoPosition[2][1];
        tetrominoPreviousPosition[3][0] = tetrominoPosition[3][0];
        tetrominoPreviousPosition[3][1] = tetrominoPosition[3][1];

        mapTetris[tetrominoPosition[0][0]][tetrominoPosition[0][1]] = -1;
        mapTetris[tetrominoPosition[1][0]][tetrominoPosition[1][1]] = -1;
        mapTetris[tetrominoPosition[2][0]][tetrominoPosition[2][1]] = -1;
        mapTetris[tetrominoPosition[3][0]][tetrominoPosition[3][1]] = -1;

        // {0, -1, -1, 0, 0, 1, 1, 0};

        if(tetrominoType[0] == 1){
            tetrominoPosition[0][0] = (tetrominoPreviousPosition[0][1] - tetrominoPreviousPosition[0][1]) + tetrominoPreviousPosition[0][0] + tetrominoRotationOffset[tetrominoRotationStep];
            tetrominoPosition[0][1] = -(tetrominoPreviousPosition[0][0] - tetrominoPreviousPosition[0][0]) + tetrominoPreviousPosition[0][1] + tetrominoRotationOffset[tetrominoRotationStep + 1];
            tetrominoPosition[1][0] = (tetrominoPreviousPosition[1][1] - tetrominoPreviousPosition[0][1]) + tetrominoPreviousPosition[0][0] + tetrominoRotationOffset[tetrominoRotationStep];
            tetrominoPosition[1][1] = -(tetrominoPreviousPosition[1][0] - tetrominoPreviousPosition[0][0]) + tetrominoPreviousPosition[0][1] + tetrominoRotationOffset[tetrominoRotationStep + 1];
            tetrominoPosition[2][0] = (tetrominoPreviousPosition[2][1] - tetrominoPreviousPosition[0][1]) + tetrominoPreviousPosition[0][0] + tetrominoRotationOffset[tetrominoRotationStep];
            tetrominoPosition[2][1] = -(tetrominoPreviousPosition[2][0] - tetrominoPreviousPosition[0][0]) + tetrominoPreviousPosition[0][1] + tetrominoRotationOffset[tetrominoRotationStep + 1];
            tetrominoPosition[3][0] = (tetrominoPreviousPosition[3][1] - tetrominoPreviousPosition[0][1]) + tetrominoPreviousPosition[0][0] + tetrominoRotationOffset[tetrominoRotationStep];
            tetrominoPosition[3][1] = -(tetrominoPreviousPosition[3][0] - tetrominoPreviousPosition[0][0]) + tetrominoPreviousPosition[0][1] + tetrominoRotationOffset[tetrominoRotationStep + 1];

            if(tetrominoPosition[0][0] == 0 && tetrominoRotationStep == 6) moveRight();
            if(tetrominoPosition[0][0] == 9 && tetrominoRotationStep == 2) moveLeft();

            if(tetrominoRotationStep == 6) tetrominoRotationStep = 0;
            else tetrominoRotationStep += 2;
        }else{
            tetrominoPosition[0][0] = (tetrominoPreviousPosition[0][1] - tetrominoPreviousPosition[0][1]) + tetrominoPreviousPosition[0][0];
            tetrominoPosition[0][1] = -(tetrominoPreviousPosition[0][0] - tetrominoPreviousPosition[0][0]) + tetrominoPreviousPosition[0][1];
            tetrominoPosition[1][0] = (tetrominoPreviousPosition[1][1] - tetrominoPreviousPosition[0][1]) + tetrominoPreviousPosition[0][0];
            tetrominoPosition[1][1] = -(tetrominoPreviousPosition[1][0] - tetrominoPreviousPosition[0][0]) + tetrominoPreviousPosition[0][1];
            tetrominoPosition[2][0] = (tetrominoPreviousPosition[2][1] - tetrominoPreviousPosition[0][1]) + tetrominoPreviousPosition[0][0];
            tetrominoPosition[2][1] = -(tetrominoPreviousPosition[2][0] - tetrominoPreviousPosition[0][0]) + tetrominoPreviousPosition[0][1];
            tetrominoPosition[3][0] = (tetrominoPreviousPosition[3][1] - tetrominoPreviousPosition[0][1]) + tetrominoPreviousPosition[0][0];
            tetrominoPosition[3][1] = -(tetrominoPreviousPosition[3][0] - tetrominoPreviousPosition[0][0]) + tetrominoPreviousPosition[0][1];
        }
        mapTetris[tetrominoPosition[0][0]][tetrominoPosition[0][1]] = tetrominoType[0];
        mapTetris[tetrominoPosition[1][0]][tetrominoPosition[1][1]] = tetrominoType[0];
        mapTetris[tetrominoPosition[2][0]][tetrominoPosition[2][1]] = tetrominoType[0];
        mapTetris[tetrominoPosition[3][0]][tetrominoPosition[3][1]] = tetrominoType[0];
        refreshWindow();
    }
}

void rotateCounterClockwise(){
    if(tetrominoType[0] != 0){
        if(tetrominoPosition[0][0] == 0) moveRight();
        if(tetrominoPosition[0][0] == 9) moveLeft();

        tetrominoPreviousPosition[0][0] = tetrominoPosition[0][0];
        tetrominoPreviousPosition[0][1] = tetrominoPosition[0][1];
        tetrominoPreviousPosition[1][0] = tetrominoPosition[1][0];
        tetrominoPreviousPosition[1][1] = tetrominoPosition[1][1];
        tetrominoPreviousPosition[2][0] = tetrominoPosition[2][0];
        tetrominoPreviousPosition[2][1] = tetrominoPosition[2][1];
        tetrominoPreviousPosition[3][0] = tetrominoPosition[3][0];
        tetrominoPreviousPosition[3][1] = tetrominoPosition[3][1];

        mapTetris[tetrominoPosition[0][0]][tetrominoPosition[0][1]] = -1;
        mapTetris[tetrominoPosition[1][0]][tetrominoPosition[1][1]] = -1;
        mapTetris[tetrominoPosition[2][0]][tetrominoPosition[2][1]] = -1;
        mapTetris[tetrominoPosition[3][0]][tetrominoPosition[3][1]] = -1;

        if(tetrominoType[0] == 1){
            tetrominoPosition[0][0] = -(tetrominoPreviousPosition[0][1] - tetrominoPreviousPosition[0][1]) + tetrominoPreviousPosition[0][0] - tetrominoRotationOffset[tetrominoRotationStep];
            tetrominoPosition[0][1] = (tetrominoPreviousPosition[0][0] - tetrominoPreviousPosition[0][0]) + tetrominoPreviousPosition[0][1] - tetrominoRotationOffset[tetrominoRotationStep + 1];
            tetrominoPosition[1][0] = -(tetrominoPreviousPosition[1][1] - tetrominoPreviousPosition[0][1]) + tetrominoPreviousPosition[0][0] - tetrominoRotationOffset[tetrominoRotationStep];
            tetrominoPosition[1][1] = (tetrominoPreviousPosition[1][0] - tetrominoPreviousPosition[0][0]) + tetrominoPreviousPosition[0][1] - tetrominoRotationOffset[tetrominoRotationStep + 1];
            tetrominoPosition[2][0] = -(tetrominoPreviousPosition[2][1] - tetrominoPreviousPosition[0][1]) + tetrominoPreviousPosition[0][0] - tetrominoRotationOffset[tetrominoRotationStep];
            tetrominoPosition[2][1] = (tetrominoPreviousPosition[2][0] - tetrominoPreviousPosition[0][0]) + tetrominoPreviousPosition[0][1] - tetrominoRotationOffset[tetrominoRotationStep + 1];
            tetrominoPosition[3][0] = -(tetrominoPreviousPosition[3][1] - tetrominoPreviousPosition[0][1]) + tetrominoPreviousPosition[0][0] - tetrominoRotationOffset[tetrominoRotationStep];
            tetrominoPosition[3][1] = (tetrominoPreviousPosition[3][0] - tetrominoPreviousPosition[0][0]) + tetrominoPreviousPosition[0][1] - tetrominoRotationOffset[tetrominoRotationStep + 1];

            if(tetrominoPosition[0][0] == 0 && tetrominoRotationStep == 2) moveRight();
            if(tetrominoPosition[0][0] == 9 && tetrominoRotationStep == 6) moveLeft();

            if(tetrominoRotationStep == 0) tetrominoRotationStep = 6;
            else tetrominoRotationStep -= 2;
        }else{
            tetrominoPosition[0][0] = -(tetrominoPreviousPosition[0][1] - tetrominoPreviousPosition[0][1]) + tetrominoPreviousPosition[0][0];
            tetrominoPosition[0][1] = (tetrominoPreviousPosition[0][0] - tetrominoPreviousPosition[0][0]) + tetrominoPreviousPosition[0][1];
            tetrominoPosition[1][0] = -(tetrominoPreviousPosition[1][1] - tetrominoPreviousPosition[0][1]) + tetrominoPreviousPosition[0][0];
            tetrominoPosition[1][1] = (tetrominoPreviousPosition[1][0] - tetrominoPreviousPosition[0][0]) + tetrominoPreviousPosition[0][1];
            tetrominoPosition[2][0] = -(tetrominoPreviousPosition[2][1] - tetrominoPreviousPosition[0][1]) + tetrominoPreviousPosition[0][0];
            tetrominoPosition[2][1] = (tetrominoPreviousPosition[2][0] - tetrominoPreviousPosition[0][0]) + tetrominoPreviousPosition[0][1];
            tetrominoPosition[3][0] = -(tetrominoPreviousPosition[3][1] - tetrominoPreviousPosition[0][1]) + tetrominoPreviousPosition[0][0];
            tetrominoPosition[3][1] = (tetrominoPreviousPosition[3][0] - tetrominoPreviousPosition[0][0]) + tetrominoPreviousPosition[0][1];
        }
        mapTetris[tetrominoPosition[0][0]][tetrominoPosition[0][1]] = tetrominoType[0];
        mapTetris[tetrominoPosition[1][0]][tetrominoPosition[1][1]] = tetrominoType[0];
        mapTetris[tetrominoPosition[2][0]][tetrominoPosition[2][1]] = tetrominoType[0];
        mapTetris[tetrominoPosition[3][0]][tetrominoPosition[3][1]] = tetrominoType[0];
        refreshWindow();
    }
}
