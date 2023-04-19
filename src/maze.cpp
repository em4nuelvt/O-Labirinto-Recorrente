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

unsigned int getMovementCase(unsigned int currentX, unsigned int currentY, unsigned int nRows, unsigned int nCols){
    /* 
    Legenda de movimentos: 
    1- Vertice superior esquerdo
    2- Vertice superior direito
    3- Vertice inferior esquerdo
    4- Vertice inferior direito
    5- Primeira Linha 
    6- Primeira Coluna
    7- Ultima linha 
    8- Ultima coluna
    9- Meio da matriz
     */
    if(currentX==0 && currentY==0){
        return 1;
    } else if((currentX==0) && (currentY==(nCols-1))){
        return 2;
    }else if( (currentX==(nRows-1)) && (currentY==0) ){
        return 3;
    }else if((currentX==(nRows-1))&& ( currentY==(nCols-1) ) ){
        return 4;
    }else if(currentX==0){
        return 5;
    }else if(currentY==0){
        return 6;
    }else if(currentX==(nRows-1)){
        return 7;
    }else if(currentY==(nCols-1)){
        return 8;
    }else{
        return 9;
    }
}

void generateNextMove(unsigned int movementCase, unsigned int* currentX, unsigned int* currentY){
    mt19937 rng(std::random_device{}());
    uniform_int_distribution<int> dist1(1, 3);
    uniform_int_distribution<int> dist2(1, 5);
    uniform_int_distribution<int> dist3(1, 8);

    unsigned int random1=dist1(rng);
    unsigned int random2=dist2(rng);
    unsigned int random3=dist3(rng);

    switch (movementCase)
    {
    case 1:
        if(random1==1){
            cout<<"Movimenta Direita"<<endl;
        }else if(random1==2){
            cout<<"Movimenta Baixo"<<endl;
        }else{
            cout<<"Movimenta Diagonal Inferior Direita"<<endl;
        }
        break;
    case 2:
        if(random1==1){
            cout<<"Movimenta Esquerda"<<endl;
        }else if(random1==2){
            cout<<"Movimenta Baixo"<<endl;
        }else{
            cout<<"Movimenta Diagonal inferior esquerda"<<endl;
        }
        break;
    case 3:
        if(random1==1){
            cout<<"Movimenta Direita"<<endl;
        }else if(random1==2){
            cout<<"Movimenta Cima"<<endl;
        }else{
            cout<<"Movimenta Diagonal Superior Direita"<<endl;
        }
        break;
    case 4:
        if(random1==1){
            cout<<"Movimenta Esquerda"<<endl;
        }else if(random1==2){
            cout<<"Movimenta Cima"<<endl;
        }else{
            cout<<"Movimenta Diagonal Superior Esquerda"<<endl;
        }
        break;
    case 5:
        if(random2==1){
            cout<<"Movimenta Esquerda"<<endl;
        }else if(random2==2){
            cout<<"Movimenta Diagonal Inferior Esquerda"<<endl;
        }else if(random2==3){
            cout<<"Movimenta Baixo"<<endl;
        }else if(random2==4){
            cout<<"Movimenta Diagonal Inferior Direita"<<endl;
        }else{
            cout<<"Movimenta Direita"<<endl;
        }
        break;
    case 6:
        if(random2==1){
            cout<<"Movimenta cima "<<endl;
        }else if(random2==2){
            cout<<"Movimenta diagonal superior direita"<<endl;
        }else if(random2==3){
            cout<<"Movimenta direita"<<endl;
        }else if(random2==4){
            cout<<"Movimenta diagonal inferior direita"<<endl;
        }else{
            cout<<"Movimenta baixo"<<endl;
        }
        break;
    case 7:
        if(random2==1){
            cout<<"Movimenta esquerda"<<endl;
        }else if(random2==2){
            cout<<"Movimenta diagonal superior esquerda"<<endl;
        }else if(random2==3){
            cout<<"Movimenta cima"<<endl;
        }else if(random2==4){
            cout<<"Movimenta diagonal superior direita"<<endl;
        }else{
            cout<<"Movimenta direita"<<endl;
        }
        break;
    case 8:
        if(random2==1){
            cout<<"Movimenta cima"<<endl;
        }else if(random2==2){
            cout<<"Movimenta diagonal superior esquerda"<<endl;
        }else if(random2==3){
            cout<<"Movimenta esquerda"<<endl;
        }else if(random2==4){
            cout<<"Movimenta diagonal inferior esquerda"<<endl;
        }else{
            cout<<"Movimenta baixo"<<endl;
        }
        break;
    case 9:
        if(random3==1){
            cout<<"Movimenta diagonal superior esquerda"<<endl;
        }else if(random3==2){
            cout<<"Movimenta cima"<<endl;
        }else if(random3==3){
            cout<<"Movimenta diagonal superior direita"<<endl;
        }else if(random3==4){
            cout<<"Movimenta direita"<<endl;
        }else if(random3==5){
            cout<<"Movimenta diagonal inferior direita"<<endl;
        }else if(random3==6){
            cout<<"Movimenta baixo"<<endl;
        }else if(random3==7){
            cout<<"Movimenta diagonal inferior esquerda"<<endl;
        }else{
            cout<<"Movimenta esquerda"<<endl;
        }
        break;
    }

}
