#include "maze.hpp"

 int main(){
    //declaração de variáveis
    ifstream inFile;
    unsigned int n, nRows, nCols,currentX=4, currentY=4, currentN;
    char** matrixMaze;

    cout<<endl;

    //abertura do arquivo
    inFile.open("dataset/input.data",std::ios::in);
    if(!inFile){
        cerr<<"Não foi possível abrir o arquivo!"<<endl;
        return 0;
    }
    //lendo a primeira liha do dataset
    inFile>>nRows>>nCols>>n;

    //alocando a matriz auxiliar a ser trabalhada
    matrixMaze=allocateMatrix( nRows, nCols);

    //lendo as matrizes e separando-as em arquivos individuais
/*     for(unsigned int i=0;i<n;i++){
        read_Maze(matrixMaze,nRows, nCols, inFile);
        printMaze(matrixMaze, nRows,nCols);
        writeOutputSave(matrixMaze, nRows, nCols, i);
        cout<<endl;
    } */

    read_Maze(matrixMaze,nRows,nCols, inFile);
    printMaze(matrixMaze, nRows,nCols);
    //getMovementCase(currentX, currentY, nRows, nCols);

    generateNextMove(9, &currentX, &currentY);

    // liberando a matriz alocada
    freeMatrix(matrixMaze,nRows);

    //fechando o arquivo aberto
    inFile.close();
    return 0;   
}