#ifndef TETROMINO_H
#define TETROMINO_H

#include <stdlib.h>
#include <time.h>


class tetromino
{
    public:
        tetromino();
        virtual ~tetromino();

        int tetrominoType;
        //array0 = block 1 X, array1 = block 1 Y, array2 = block 2 X ...
        int tetrominoPosition[8];
        int tetrominoUp();
        int tetrominoDown();
        int tetrominoLeft();
        int tetrominoRight();
        int getTetrominoType();
        int getBlock1X();
        int getBlock1Y();
        int getBlock2X();
        int getBlock2Y();
        int getBlock3X();
        int getBlock3Y();
        int getBlock4X();
        int getBlock4Y();

        void random(){
            srand(time(NULL));
            this->tetrominoType = 1; //rand()%7;
            switch(tetrominoType){
                case 0:
                    tetrominoPosition[0] = 4;
                    tetrominoPosition[1] = 0;
                    tetrominoPosition[2] = 5;
                    tetrominoPosition[3] = 0;
                    tetrominoPosition[4] = 4;
                    tetrominoPosition[5] = 1;
                    tetrominoPosition[6] = 5;
                    tetrominoPosition[7] = 1;
                    break;
                case 1:
                    tetrominoPosition[0] = 3;
                    tetrominoPosition[1] = 1;
                    tetrominoPosition[2] = 4;
                    tetrominoPosition[3] = 1;
                    tetrominoPosition[4] = 5;
                    tetrominoPosition[5] = 1;
                    tetrominoPosition[6] = 6;
                    tetrominoPosition[7] = 1;
                    break;
                case 2:
                    tetrominoPosition[0] = 3;
                    tetrominoPosition[1] = 0;
                    tetrominoPosition[2] = 4;
                    tetrominoPosition[3] = 0;
                    tetrominoPosition[4] = 4;
                    tetrominoPosition[5] = 1;
                    tetrominoPosition[6] = 5;
                    tetrominoPosition[7] = 1;
                    break;
                case 3:
                    tetrominoPosition[0] = 3;
                    tetrominoPosition[1] = 0;
                    tetrominoPosition[2] = 3;
                    tetrominoPosition[3] = 1;
                    tetrominoPosition[4] = 4;
                    tetrominoPosition[5] = 1;
                    tetrominoPosition[6] = 5;
                    tetrominoPosition[7] = 1;
                    break;
                case 4:
                    tetrominoPosition[0] = 4;
                    tetrominoPosition[1] = 0;
                    tetrominoPosition[2] = 3;
                    tetrominoPosition[3] = 1;
                    tetrominoPosition[4] = 4;
                    tetrominoPosition[5] = 1;
                    tetrominoPosition[6] = 5;
                    tetrominoPosition[7] = 1;
                    break;
                case 5:
                    tetrominoPosition[0] = 4;
                    tetrominoPosition[1] = 0;
                    tetrominoPosition[2] = 5;
                    tetrominoPosition[3] = 0;
                    tetrominoPosition[4] = 3;
                    tetrominoPosition[5] = 1;
                    tetrominoPosition[6] = 4;
                    tetrominoPosition[7] = 1;
                    break;
                case 6:
                    tetrominoPosition[0] = 3;
                    tetrominoPosition[1] = 0;
                    tetrominoPosition[2] = 3;
                    tetrominoPosition[3] = 1;
                    tetrominoPosition[4] = 4;
                    tetrominoPosition[5] = 1;
                    tetrominoPosition[6] = 5;
                    tetrominoPosition[7] = 1;
                    break;
            }
        };

        void tetrominoDelete(){
            delete this;
        }

    protected:

    private:
};

#endif // TETROMINO_H
