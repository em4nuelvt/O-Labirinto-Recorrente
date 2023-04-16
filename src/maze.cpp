#include "maze.hpp"

char** allocateMatrix( unsigned int nRows,  unsigned int nCols){
    char** matrixMaze;
    matrixMaze= (char**)malloc(sizeof(char*)*nRows);
    for(unsigned int i=0;i<nRows;i++){
        matrixMaze[i]=(char*) malloc(sizeof(char)*nCols);
    }
    return matrixMaze;
}

void freeMatrix(char**matrixMaze, unsigned int nRows){
    for(unsigned int i=0;i<nRows;i++){
        free(matrixMaze[i]);
    }
    free(matrixMaze);
}

char** read_Maze(char** matrixMaze, unsigned int nRows, unsigned int nCols, ifstream &inFile){
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

void writeOutputSave(char**matrixMaze, unsigned int nRows, unsigned int nCols, unsigned int n){
    ofstream outFile("outputFiles/Save"+to_string(n)+".dat");
    if(!outFile){
        cerr<<"Erro na criação do arquivo"<<endl;
        return;
    }
    for(unsigned int i=0; i<nRows;i++){
        for(unsigned int j=0;j<nCols;j++){
            outFile<<matrixMaze[i][j]<<" ";
        }
        outFile<<endl;
    }

    outFile.close();
    return;
}
