#include "maze.hpp"


char** read_Maze(char** matrixMaze, unsigned int nRows, unsigned int nCols, ifstream &inFile){
    for(unsigned int i=0;i<nRows;i++){
        matrixMaze[i]=(char*)malloc(sizeof(char)*nCols);
    }
    for(unsigned int i=0; i<nRows;i++){
        for(unsigned int j=0;j<nCols;j++){
            inFile>>matrixMaze[i][j];
        }
    }
    return matrixMaze;
}

void printMaze(char** matrixMaze,unsigned int nRows, unsigned int nCols){
    for(unsigned int i=0;i<nRows;i++){
        for(unsigned int j=0;j<nCols;j++){
            cout<<matrixMaze[i][j]<<"\t";
        }
        cout<<endl;
    }
}