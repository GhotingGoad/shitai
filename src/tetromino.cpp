#include "global.h"


//individual collision block for Player controlled Tetromino
bool collisionFlag1;
bool collisionFlag2;
bool collisionFlag3;
bool collisionFlag4;

//00 = block1x, 01 = block1y, 10 = block2x, 11 = block2y etc etc
int tetrominoPosition[4][2];
int tetrominoPreviousPosition[4][2];

//offset and step for Tetromino I SRS
int tetrominoRotationStep = 0;
int tetrominoRotationOffset[16] = {1, 0, 0, -1, -1, 0, 0, 1, 1, 0, 0, -1, -1, 0, 0, 1};

int rowEmptyCount[22];
int rowEmptyNumber[4];
int rowEmptyNumberCount;
int rowEmptyNumberLoop;

void generateTetromino(){
    for(int i = 0; i < 5; i++) tetrominoType[i] = tetrominoType[i + 1];
    tetrominoType[5] = rand()%7;

    for(int i = 0; i <10; i++){
        for(int j = 0; j < 2; j++) mapTetris[i][j] = -1;
    }

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
    for(int i = 0; i < 22; i++) rowEmptyCount[i] = 0;
    for(int i = 0; i < 4; i++) rowEmptyNumber[i] = 0;
    rowEmptyNumberCount = 0;
    rowEmptyNumberLoop = 0;

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
        if(!moveDown()) break;
    }
}

bool moveDown(){
    if(checkDownCollision()){
        mapTetris[tetrominoPosition[0][0]][tetrominoPosition[0][1]] = tetrominoType[0] + 10;
        mapTetris[tetrominoPosition[1][0]][tetrominoPosition[1][1]] = tetrominoType[0] + 10;
        mapTetris[tetrominoPosition[2][0]][tetrominoPosition[2][1]] = tetrominoType[0] + 10;
        mapTetris[tetrominoPosition[3][0]][tetrominoPosition[3][1]] = tetrominoType[0] + 10;

        checkClearRows();

        generateTetromino();
        return false;

    }else{
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
    }
    return true;
}

bool moveLeft(){
    if(checkLeftCollision()) return false;
    else{
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
        refreshWindow();
        return true;
    }
}

bool moveRight(){
    if(checkRightCollision()) return false;
    else{
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
        refreshWindow();
        return true;
    }
}

void rotateClockwise(){
    if(tetrominoType[0] == 0) return;
    else if(tetrominoType[0] == 1){
        if(checkAxisRightCollision() && tetrominoRotationStep == 6){
            if(moveLeft()){

            }


            if(checkClockwiseCollision()) return;
            else moveLeft();
        }else if(checkAxisRightCollision() && tetrominoRotationStep == 2){
            if(checkClockwiseCollision()) return;
            else{
                moveLeft();
                moveLeft();
            }
        }else if(checkClockwiseCollision() && (tetrominoPosition[0][0] + 2 != -1 || tetrominoPosition[0][0] + 2 != tetrominoType[0])){
            if(checkClockwiseCollision()) return;
            else moveLeft();
        }else if(checkAxisLeftCollision() && tetrominoRotationStep == 2){
            if(checkClockwiseCollision()) return;
            else moveRight();
        }else if(checkAxisLeftCollision() && tetrominoRotationStep == 6){
            if(checkClockwiseCollision()) return;
            else{
                moveRight();
                moveRight();
            }
        }else if(checkClockwiseCollision() && (tetrominoPosition[0][0] - 2 != -1 || tetrominoPosition[0][0] - 2 != tetrominoType[0])){
            if(checkClockwiseCollision()) return;
            else moveRight();
        }else if(checkClockwiseCollision()) return;
    }else{
        if(checkAxisLeftCollision()) moveRight();
        else if(checkAxisRightCollision()) moveLeft();
        if(checkClockwiseCollision()){
            if(checkAxisLeftCollision()) moveRight();
            else if(checkAxisRightCollision()) moveLeft();
            return;
        }
    }



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

    // {1, 0, 0, 1, -1, 0, 0, -1};

    switch(tetrominoType[0]){
        case 0:
            break;
        case 1:
            tetrominoPosition[0][0] = -(tetrominoPreviousPosition[0][1] - tetrominoPreviousPosition[0][1]) + tetrominoPreviousPosition[0][0] + tetrominoRotationOffset[tetrominoRotationStep];
            tetrominoPosition[0][1] = (tetrominoPreviousPosition[0][0] - tetrominoPreviousPosition[0][0]) + tetrominoPreviousPosition[0][1] + tetrominoRotationOffset[tetrominoRotationStep + 1];
            tetrominoPosition[1][0] = -(tetrominoPreviousPosition[1][1] - tetrominoPreviousPosition[0][1]) + tetrominoPreviousPosition[0][0] + tetrominoRotationOffset[tetrominoRotationStep];
            tetrominoPosition[1][1] = (tetrominoPreviousPosition[1][0] - tetrominoPreviousPosition[0][0]) + tetrominoPreviousPosition[0][1] + tetrominoRotationOffset[tetrominoRotationStep + 1];
            tetrominoPosition[2][0] = -(tetrominoPreviousPosition[2][1] - tetrominoPreviousPosition[0][1]) + tetrominoPreviousPosition[0][0] + tetrominoRotationOffset[tetrominoRotationStep];
            tetrominoPosition[2][1] = (tetrominoPreviousPosition[2][0] - tetrominoPreviousPosition[0][0]) + tetrominoPreviousPosition[0][1] + tetrominoRotationOffset[tetrominoRotationStep + 1];
            tetrominoPosition[3][0] = -(tetrominoPreviousPosition[3][1] - tetrominoPreviousPosition[0][1]) + tetrominoPreviousPosition[0][0] + tetrominoRotationOffset[tetrominoRotationStep];
            tetrominoPosition[3][1] = (tetrominoPreviousPosition[3][0] - tetrominoPreviousPosition[0][0]) + tetrominoPreviousPosition[0][1] + tetrominoRotationOffset[tetrominoRotationStep + 1];

            if(tetrominoRotationStep == 0) tetrominoRotationStep = 6;
            else tetrominoRotationStep -= 2;
            break;
        default:
            tetrominoPosition[0][0] = -(tetrominoPreviousPosition[0][1] - tetrominoPreviousPosition[0][1]) + tetrominoPreviousPosition[0][0];
            tetrominoPosition[0][1] = (tetrominoPreviousPosition[0][0] - tetrominoPreviousPosition[0][0]) + tetrominoPreviousPosition[0][1];
            tetrominoPosition[1][0] = -(tetrominoPreviousPosition[1][1] - tetrominoPreviousPosition[0][1]) + tetrominoPreviousPosition[0][0];
            tetrominoPosition[1][1] = (tetrominoPreviousPosition[1][0] - tetrominoPreviousPosition[0][0]) + tetrominoPreviousPosition[0][1];
            tetrominoPosition[2][0] = -(tetrominoPreviousPosition[2][1] - tetrominoPreviousPosition[0][1]) + tetrominoPreviousPosition[0][0];
            tetrominoPosition[2][1] = (tetrominoPreviousPosition[2][0] - tetrominoPreviousPosition[0][0]) + tetrominoPreviousPosition[0][1];
            tetrominoPosition[3][0] = -(tetrominoPreviousPosition[3][1] - tetrominoPreviousPosition[0][1]) + tetrominoPreviousPosition[0][0];
            tetrominoPosition[3][1] = (tetrominoPreviousPosition[3][0] - tetrominoPreviousPosition[0][0]) + tetrominoPreviousPosition[0][1];
            break;
    }
    mapTetris[tetrominoPosition[0][0]][tetrominoPosition[0][1]] = tetrominoType[0];
    mapTetris[tetrominoPosition[1][0]][tetrominoPosition[1][1]] = tetrominoType[0];
    mapTetris[tetrominoPosition[2][0]][tetrominoPosition[2][1]] = tetrominoType[0];
    mapTetris[tetrominoPosition[3][0]][tetrominoPosition[3][1]] = tetrominoType[0];
    refreshWindow();
}

void rotateCounterClockwise(){
    if(tetrominoType[0] == 0) return;
    else if(tetrominoType[0] == 1){
        if(checkAxisRightCollision() && tetrominoRotationStep == 6){
            if(checkCounterClockwiseCollision()) return;
            else moveLeft();
        }else if(checkAxisRightCollision() && tetrominoRotationStep == 2){
            if(checkCounterClockwiseCollision()) return;
            else{
                moveLeft();
                moveLeft();
            }
        }else if(checkCounterClockwiseCollision() && (tetrominoPosition[0][0] + 2 != -1 || tetrominoPosition[0][0] + 2 != tetrominoType[0])){
             if(checkCounterClockwiseCollision()) return;
            else moveLeft();
        }else if(checkAxisLeftCollision() && tetrominoRotationStep == 2){
            if(checkCounterClockwiseCollision()) return;
            else moveRight();
        }else if(checkAxisLeftCollision() && tetrominoRotationStep == 6){
            if(checkCounterClockwiseCollision()) return;
            else{
                moveRight();
                moveRight();
            }
        }else if(checkCounterClockwiseCollision() && (tetrominoPosition[0][0] - 2 != -1 || tetrominoPosition[0][0] - 2 != tetrominoType[0])){
             if(checkCounterClockwiseCollision()) return;
            else moveRight();
        }else if(checkCounterClockwiseCollision()) return;
    }else{
        if(checkAxisLeftCollision()) moveRight();
        else if(checkAxisRightCollision()) moveLeft();
        if(checkCounterClockwiseCollision()){
            if(checkAxisLeftCollision()) moveRight();
            else if(checkAxisRightCollision()) moveLeft();
            return;
        }
    }

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

    switch(tetrominoType[0]){
        case 0:
            break;
        case 1:
            tetrominoPosition[0][0] = (tetrominoPreviousPosition[0][1] - tetrominoPreviousPosition[0][1]) + tetrominoPreviousPosition[0][0] + tetrominoRotationOffset[tetrominoRotationStep + 6];
            tetrominoPosition[0][1] = -(tetrominoPreviousPosition[0][0] - tetrominoPreviousPosition[0][0]) + tetrominoPreviousPosition[0][1] + tetrominoRotationOffset[tetrominoRotationStep + 7];
            tetrominoPosition[1][0] = (tetrominoPreviousPosition[1][1] - tetrominoPreviousPosition[0][1]) + tetrominoPreviousPosition[0][0] + tetrominoRotationOffset[tetrominoRotationStep + 6];
            tetrominoPosition[1][1] = -(tetrominoPreviousPosition[1][0] - tetrominoPreviousPosition[0][0]) + tetrominoPreviousPosition[0][1] + tetrominoRotationOffset[tetrominoRotationStep + 7];
            tetrominoPosition[2][0] = (tetrominoPreviousPosition[2][1] - tetrominoPreviousPosition[0][1]) + tetrominoPreviousPosition[0][0] + tetrominoRotationOffset[tetrominoRotationStep + 6];
            tetrominoPosition[2][1] = -(tetrominoPreviousPosition[2][0] - tetrominoPreviousPosition[0][0]) + tetrominoPreviousPosition[0][1] + tetrominoRotationOffset[tetrominoRotationStep + 7];
            tetrominoPosition[3][0] = (tetrominoPreviousPosition[3][1] - tetrominoPreviousPosition[0][1]) + tetrominoPreviousPosition[0][0] + tetrominoRotationOffset[tetrominoRotationStep + 6];
            tetrominoPosition[3][1] = -(tetrominoPreviousPosition[3][0] - tetrominoPreviousPosition[0][0]) + tetrominoPreviousPosition[0][1] + tetrominoRotationOffset[tetrominoRotationStep + 7];

            if(tetrominoRotationStep == 6) tetrominoRotationStep = 0;
            else tetrominoRotationStep += 2;
            break;
        default:
             tetrominoPosition[0][0] = (tetrominoPreviousPosition[0][1] - tetrominoPreviousPosition[0][1]) + tetrominoPreviousPosition[0][0];
            tetrominoPosition[0][1] = -(tetrominoPreviousPosition[0][0] - tetrominoPreviousPosition[0][0]) + tetrominoPreviousPosition[0][1];
            tetrominoPosition[1][0] = (tetrominoPreviousPosition[1][1] - tetrominoPreviousPosition[0][1]) + tetrominoPreviousPosition[0][0];
            tetrominoPosition[1][1] = -(tetrominoPreviousPosition[1][0] - tetrominoPreviousPosition[0][0]) + tetrominoPreviousPosition[0][1];
            tetrominoPosition[2][0] = (tetrominoPreviousPosition[2][1] - tetrominoPreviousPosition[0][1]) + tetrominoPreviousPosition[0][0];
            tetrominoPosition[2][1] = -(tetrominoPreviousPosition[2][0] - tetrominoPreviousPosition[0][0]) + tetrominoPreviousPosition[0][1];
            tetrominoPosition[3][0] = (tetrominoPreviousPosition[3][1] - tetrominoPreviousPosition[0][1]) + tetrominoPreviousPosition[0][0];
            tetrominoPosition[3][1] = -(tetrominoPreviousPosition[3][0] - tetrominoPreviousPosition[0][0]) + tetrominoPreviousPosition[0][1];
            break;
    }
    mapTetris[tetrominoPosition[0][0]][tetrominoPosition[0][1]] = tetrominoType[0];
    mapTetris[tetrominoPosition[1][0]][tetrominoPosition[1][1]] = tetrominoType[0];
    mapTetris[tetrominoPosition[2][0]][tetrominoPosition[2][1]] = tetrominoType[0];
    mapTetris[tetrominoPosition[3][0]][tetrominoPosition[3][1]] = tetrominoType[0];
    refreshWindow();
}

