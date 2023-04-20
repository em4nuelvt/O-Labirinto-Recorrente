#include "maze.hpp"

 int main(){
    unsigned int nRows,nCols,n;
    int choice;
    choice=generateIndividualMazeFiles(&nRows,&nCols, &n);
    if(choice== 1){
        return 0;
    }
    
    start(nRows,nCols,n);
    return 0;   
}