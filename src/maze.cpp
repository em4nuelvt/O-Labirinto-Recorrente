#include "maze.hpp"

char** allocateMatrix( unsigned int nRows,  unsigned int nCols){
    char** matrixMaze;
    matrixMaze= (char**)malloc(sizeof(char*)*nRows);
    for(unsigned int i=0;i<nRows;i++){
        matrixMaze[i]=(char*) malloc(sizeof(char)*nCols);
    }
    return matrixMaze;
}

char** allocateMovementSaveMatrix( unsigned int nRows,  unsigned int nCols){
    char** matrixMaze;
    matrixMaze= (char**)malloc(sizeof(char*)*nRows);
    for(unsigned int i=0;i<nRows;i++){
        matrixMaze[i]=(char*) malloc(sizeof(char)*nCols);
    }
    for(unsigned int i=0;i<nRows;i++){
        for(unsigned int j=0; j<nCols;j++){
            matrixMaze[i][j]='0';
        }
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
            cout<<"["<<matrixMaze[i][j]<<"] ";
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
            moveRight(currentX, currentY);
        }else if(random1==2){
            cout<<"Movimenta Baixo"<<endl;
            moveDown(currentX, currentY);
        }else{
            cout<<"Movimenta Diagonal Inferior Direita"<<endl;
            moveRightBottomDiagonal(currentX, currentY);
        }
        break;
    case 2:
        if(random1==1){
            cout<<"Movimenta Esquerda"<<endl;
            moveLeft(currentX, currentY);
        }else if(random1==2){
            cout<<"Movimenta Baixo"<<endl;
            moveDown(currentX, currentY);
        }else{
            cout<<"Movimenta Diagonal inferior esquerda"<<endl;
            moveLeftBottomDiagonal(currentX, currentY);
        }
        break;
    case 3:
        if(random1==1){
            cout<<"Movimenta Direita"<<endl;
            moveRight(currentX, currentY);
        }else if(random1==2){
            cout<<"Movimenta Cima"<<endl;
            moveUp(currentX, currentY);
        }else{
            cout<<"Movimenta Diagonal Superior Direita"<<endl;
            moveRightTopDiagonal(currentX, currentY);
        }
        break;
    case 4:
        if(random1==1){
            cout<<"Movimenta Esquerda"<<endl;
            moveLeft(currentX, currentY);
        }else if(random1==2){
            cout<<"Movimenta Cima"<<endl;
            moveUp(currentX, currentY);
        }else{
            cout<<"Movimenta Diagonal Superior Esquerda"<<endl;
            moveLeftTopDiagonal(currentX, currentY);
        }
        break;
    case 5:
        if(random2==1){
            cout<<"Movimenta Esquerda"<<endl;
            moveLeft(currentX, currentY);
        }else if(random2==2){
            cout<<"Movimenta Diagonal Inferior Esquerda"<<endl;
            moveLeftBottomDiagonal(currentX, currentY);
        }else if(random2==3){
            cout<<"Movimenta Baixo"<<endl;
            moveDown(currentX, currentY);
        }else if(random2==4){
            cout<<"Movimenta Diagonal Inferior Direita"<<endl;
            moveRightBottomDiagonal(currentX, currentY);
        }else{
            cout<<"Movimenta Direita"<<endl;
            moveRight(currentX, currentY);
        }
        break;
    case 6:
        if(random2==1){
            cout<<"Movimenta cima "<<endl;
            moveUp(currentX, currentY);
        }else if(random2==2){
            cout<<"Movimenta diagonal superior direita"<<endl;
            moveRightTopDiagonal(currentX, currentY);
        }else if(random2==3){
            cout<<"Movimenta direita"<<endl;
            moveRight(currentX, currentY);
        }else if(random2==4){
            cout<<"Movimenta diagonal inferior direita"<<endl;
            moveRightBottomDiagonal(currentX, currentY);
        }else{
            cout<<"Movimenta baixo"<<endl;
            moveDown(currentX, currentY);
        }
        break;
    case 7:
        if(random2==1){
            cout<<"Movimenta esquerda"<<endl;
            moveLeft(currentX, currentY);
        }else if(random2==2){
            cout<<"Movimenta diagonal superior esquerda"<<endl;
            moveLeftTopDiagonal(currentX, currentY);
        }else if(random2==3){
            cout<<"Movimenta cima"<<endl;
            moveUp(currentX, currentY);
        }else if(random2==4){
            cout<<"Movimenta diagonal superior direita"<<endl;
            moveRightTopDiagonal(currentX, currentY);
        }else{
            cout<<"Movimenta direita"<<endl;
            moveRight(currentX, currentY);
        }
        break;
    case 8:
        if(random2==1){
            cout<<"Movimenta cima"<<endl;
            moveUp(currentX, currentY);
        }else if(random2==2){
            cout<<"Movimenta diagonal superior esquerda"<<endl;
            moveLeftTopDiagonal(currentX, currentY);
        }else if(random2==3){
            cout<<"Movimenta esquerda"<<endl;
            moveLeft(currentX, currentY);
        }else if(random2==4){
            cout<<"Movimenta diagonal inferior esquerda"<<endl;
            moveLeftBottomDiagonal(currentX,currentY);
        }else{
            cout<<"Movimenta baixo"<<endl;
            moveDown(currentX, currentY);
        }
        break;
    case 9:
        if(random3==1){
            cout<<"Movimenta diagonal superior esquerda"<<endl;
            moveLeftTopDiagonal(currentX, currentY);
        }else if(random3==2){
            cout<<"Movimenta cima"<<endl;
            moveUp(currentX, currentY);
        }else if(random3==3){
            cout<<"Movimenta diagonal superior direita"<<endl;
            moveRightTopDiagonal(currentX, currentY);
        }else if(random3==4){
            cout<<"Movimenta direita"<<endl;
            moveRight(currentX, currentY);
        }else if(random3==5){
            cout<<"Movimenta diagonal inferior direita"<<endl;
            moveRightBottomDiagonal(currentX, currentY);
        }else if(random3==6){
            cout<<"Movimenta baixo"<<endl;
            moveDown(currentX, currentY);
        }else if(random3==7){
            cout<<"Movimenta diagonal inferior esquerda"<<endl;
            moveLeftBottomDiagonal(currentX, currentY);
        }else{
            cout<<"Movimenta esquerda"<<endl;
            moveLeft(currentX, currentY);
        }
        break;
    }

}
void moveLeft(unsigned int* x, unsigned int* y){
    *y=*y-1;
}
void moveRight(unsigned int* x, unsigned int* y){
    *y=*y+1;
}
void moveUp(unsigned int* x, unsigned int* y){
    *x=*x-1;
}
void moveDown(unsigned int* x, unsigned int* y){
    *x=*x+1;
}
void moveLeftTopDiagonal(unsigned int* x, unsigned int* y){
    *x=*x-1;
    *y=*y-1;
}
void moveLeftBottomDiagonal(unsigned int* x, unsigned int* y){
    *x=*x+1;
    *y=*y-1;
}
void moveRightTopDiagonal(unsigned int* x, unsigned int* y){
    *x=*x-1;
    *y=*y+1;
}
void moveRightBottomDiagonal(unsigned int* x, unsigned int* y){
    *x=*x+1;
    *y=*y+1;
}

int generateIndividualMazeFiles(unsigned int* row, unsigned int* col, unsigned int* N){
        //declaração de variáveis
    ifstream inFile;
    unsigned int n, nRows, nCols;
    char** matrixMaze;
    //abertura do arquivo
    inFile.open("dataset/input.data",std::ios::in);
    if(!inFile){
        cerr<<"Não foi possível abrir o arquivo!"<<endl;
        return 1;
    }
    //lendo a primeira liha do dataset
    inFile>>nRows>>nCols>>n;
    *row=nRows;
    *col=nCols;
    *N=n;

    //alocando a matriz auxiliar a ser trabalhada
    matrixMaze=allocateMatrix( nRows, nCols);

    //lendo as matrizes e separando-as em arquivos individuais
    for(unsigned int i=0;i<n;i++){
        read_Maze(matrixMaze,nRows, nCols, inFile);
        //printMaze(matrixMaze, nRows,nCols);
        writeOutputSave(matrixMaze, nRows, nCols, i);
        //cout<<endl;
    }
    freeMatrix(matrixMaze,nRows);
    //fechando o arquivo aberto
    inFile.close();
    return 0;
}


void generateMovementMatrixSave(char** matrixWithMoves, unsigned int nRows, unsigned int nCols , unsigned int n){
    ofstream outFile;
    outFile.open("outputFiles/SaveMovements"+to_string(n)+".dat");

    for(unsigned int i=0;i<nRows;i++){
        for (unsigned int j=0;j<nCols;j++){
            outFile<<matrixWithMoves[i][j]<<" ";
        }
        outFile<<endl;
    }

}

void printMatrixWithColor(char** matrixMaze,unsigned int nRows, unsigned int nCols,unsigned int x, unsigned int y){
    for(unsigned int i=0;i<nRows;i++){
        for(unsigned int j=0;j<nCols;j++){
            if((i==x)&&(j==y)){
                std::cout << "\033[31m"; // define a cor vermelha
                std::cout <<"["<<matrixMaze[i][j]<<"] ";
                std::cout << "\033[0m"; // restaura a cor padrão
            }else{
                cout<<"["<<matrixMaze[i][j]<<"] ";
            }
        }
        cout<<endl;
    }
}
void cleanMatrix(char** matrixWithMoves, unsigned int nRows, unsigned int nCols){
    for(unsigned int i=0;i<nRows;i++){
        for(unsigned int j=0;j<nCols;j++){
            matrixWithMoves[i][j]='0';
        }
    }
}


/////////////////////////////////////////// start //////////////////////////////////////////////
void start(unsigned int nRows, unsigned int nCols, unsigned int n){
    char** matrixMaze, **currentMovesMatrix;
    unsigned int movementCase,inicialX=0, inicialY=0,currentX=inicialX,currentY=inicialY, currentN=0;
    unsigned int lastX=currentX, lastY=currentY;

    //contadores
    unsigned int totalMoves=0,currentMatrixMoves=0;
    //alocando matrizes
    matrixMaze=allocateMatrix(nRows,nCols);
    currentMovesMatrix=allocateMovementSaveMatrix(nRows,nCols);


    ifstream inFile;
    inFile.open("outputFiles/Save0.dat",std::ios::in);
    if(!inFile){
        cerr<<"Não foi possível abrir o arquivo!"<<endl;
        return ;
    }

    //ler matriz inicial;
    read_Maze(matrixMaze,nRows,nCols,inFile);

    //fechando o arquivo
    inFile.close();
    currentMovesMatrix[currentX][currentY]='1';
    while(1){
        /////////////////////impressões//////////////////////////////////////////
        printMatrixWithColor(matrixMaze,nRows,nCols,currentX,currentY);
        cout<<endl;
        printMaze(currentMovesMatrix,nRows,nCols);
        cout<<endl;
        cout<<"Position: ("<<currentX<< ","<<currentY<<")" <<endl;
        cout<<"Total Moves: "<<totalMoves<<endl;
        cout<<"Current Matrix Moves: "<<currentMatrixMoves<<endl;
        //////////////////////////////ações///////////////////////////////////////

        //teletransporte
        if((currentX==0||currentY==0||currentX==nRows-1||currentY==nCols-1)&&(currentMatrixMoves>10)){
            cout<<"Teletransporta"<<endl;
            currentMatrixMoves=0;
            generateMovementMatrixSave(currentMovesMatrix,nRows,nCols,currentN);
            if(currentN==n-1){
                currentN=0;
            }else{
                currentN++;
            }
            ifstream inFile;
            ifstream inFile2;
            inFile.open("outputFiles/Save"+to_string(currentN)+".dat",std::ios::in);
            inFile2.open("outputFiles/SaveMovements"+to_string(currentN)+".dat",std::ios::in);
            if(!inFile){
                cerr<<"Não foi possível abrir o arquivo!"<<endl;
                return ;
            }
            if(!inFile2){
                cleanMatrix(currentMovesMatrix,nRows,nCols);
            }else{
                read_Maze(currentMovesMatrix,nRows,nCols,inFile2);
            }
            currentMovesMatrix[currentX][currentY]='1';
            read_Maze(matrixMaze,nRows,nCols,inFile);

            //fechando o arquivo
            inFile.close();
            inFile2.close();            

        }




        ////////////////////////////////movimentação///////////////////////////////
        
        lastX=currentX, lastY=currentY;
        movementCase=getMovementCase(currentX,currentY,nRows,nCols);
        generateNextMove(movementCase,&currentX,&currentY);
        currentMovesMatrix[currentX][currentY]='1';
        totalMoves++;
        currentMatrixMoves++;
        do{
            if(matrixMaze[currentX][currentY]=='#'){
                currentMovesMatrix[currentX][currentY]='1';
                currentX=lastX, currentY=lastY;
                movementCase=getMovementCase(currentX,currentY,nRows,nCols);
                generateNextMove(movementCase,&currentX,&currentY);
                currentMovesMatrix[currentX][currentY]='1';
            }
        }while(matrixMaze[currentX][currentY]=='#');
        //Pausa na execução
        getchar();
        setbuf(stdin,0);
        
    }
    //liberando matriz
    freeMatrix(matrixMaze, nRows);
    freeMatrix(currentMovesMatrix, nRows);

    

}