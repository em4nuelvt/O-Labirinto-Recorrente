#include "maze.hpp"

 int main(){
    ifstream inFile;
    unsigned int n, nRows, nCols;
    char** matrixMaze;

    cout<<endl;
    inFile.open("dataset/input.data",std::ios::in);
    if(!inFile){
        cerr<<"Não foi possível abrir o arquivo!"<<endl;
        return 0;
    }
    //lendo a primeira liha do dataset
    inFile>>nRows>>nCols>>n;

    //alocando a matriz auxiliar a ser trabalhada
    matrixMaze=allocateMatrix( nRows, nCols);

    for(unsigned int i=0;i<n;i++){
        read_Maze(matrixMaze,nRows, nCols, inFile);
        printMaze(matrixMaze, nRows,nCols);
        cout<<endl;
    }
    // liberando a matriz alocada
    freeMatrix(matrixMaze,nRows);
    return 0;   
}