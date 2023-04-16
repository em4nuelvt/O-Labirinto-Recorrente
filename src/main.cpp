#include "maze.hpp"

 int main(){
    ifstream inFile;
    unsigned int n, nRows, nCols;
    char** matrixMaze;

    inFile.open("dataset/input.data",std::ios::in);
    if(!inFile){
        cerr<<"Não foi possível abrir o arquivo!"<<endl;
        return 0;
    }
    //lendo a primeira liha do dataset
    inFile>>nRows>>nCols>>n;

    //alocando a matriz a ser trabalhada
    matrixMaze=allocateMatrix( nRows, nCols);

    read_Maze(matrixMaze,nRows, nCols, inFile);
    printMaze(matrixMaze, nRows,nCols);
    cout<<endl;

    read_Maze(matrixMaze,nRows, nCols, inFile);
    printMaze(matrixMaze, nRows,nCols);
    cout<<endl;

    read_Maze(matrixMaze,nRows, nCols, inFile);
    printMaze(matrixMaze, nRows,nCols);
    cout<<endl;

    cout<<nRows<<endl;
    cout<<nCols<<endl;
    cout<<n<<endl;

    // liberando a matriz alocada
 /*    free(matrixMaze);
    for(unsigned int i=0;i<nRows;i++){
        free(matrixMaze[i]);
    } */
    return 0;   
}