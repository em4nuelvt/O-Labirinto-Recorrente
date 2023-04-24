#include "maze.hpp"
#include <chrono>   

 int main(){
    auto start_time = chrono::high_resolution_clock::now();
    unsigned int nRows,nCols,n;
    int choice;

    choice=generateIndividualMazeFiles(&nRows,&nCols, &n);
    if(choice== 1){
        return 0;
    }
    start(nRows,nCols,n);
    auto end_time = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time);
    cout << "Tempo de execução: " << duration.count() << " microssegundos\n";
    return 0;   
}