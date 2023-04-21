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
    /*Legenda de movimentos: 
    1- Vertice superior esquerdo
    2- Vertice superior direito
    3- Vertice inferior esquerdo
    4- Vertice inferior direito
    5- Primeira Linha 
    6- Primeira Coluna
    7- Ultima linha 
    8- Ultima coluna
    9- Meio da matriz */
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
bool verifyWin(unsigned int currentX,unsigned int currentY,unsigned int currentN,unsigned int inicialX, unsigned int inicialY, unsigned int inicialN, unsigned int bag, bool catchedItem, unsigned int movements,unsigned int cicles){
    if((currentX==inicialX)&&(currentY==inicialY)&&(currentY==inicialY)&&(bag==0)&&(catchedItem==false)&&(currentN==inicialN)&&(movements>0)&&(cicles>0)){
        return true;
    }else{
        return false;
    }
}
unsigned int getNumberPositionsNotVisited(char** matrix,unsigned int nRows, unsigned int nCols, unsigned int n){
    ifstream inFile;
    unsigned int acm=0;
    for(unsigned int x=0; x<n;x++){
        inFile.open("outputFiles/SaveMovements"+to_string(x)+".dat",std::ios::in);
        if(!inFile){
            cout<<"não abriu o arquivo"<<endl;
            acm=acm + (nRows*nCols);
        }else{
            matrix=read_Maze(matrix,nRows,nCols,inFile);
            for (unsigned int i=0;i<nRows;i++){
                for (unsigned int j=0;j<nCols;j++){
                  if(matrix[i][j]=='0'){
                    acm=acm+1;
                  }  
                }
            }
        }
        inFile.close();
    }
    return acm;
}


/////////////////////////////////////////// start //////////////////////////////////////////////
void start(unsigned int nRows, unsigned int nCols, unsigned int n){
    char** matrixMaze, **currentMovesMatrix;
    bool catchedItem=false;
    unsigned int movementCase,inicialX=0, inicialY=0,currentX=inicialX,currentY=inicialY, currentN=0;
    unsigned int lastX=currentX, lastY=currentY;
    int valorPosicao;
    string aux;

    //contadores
    unsigned int totalMoves=0,currentMatrixMoves=0, HP=8, bag=0, bagTotal=0, dangerCount=0,cicles=0;
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
        ////////////////////////verifica vitoria/////////////////////////////////
        if(verifyWin(currentX,currentY,currentN,inicialX,inicialY,0,bag,catchedItem,totalMoves,cicles)){
            cout << "\033[1;36m" << "Nice, you win!!!" << "\033[0m" << endl<<endl;
            cout<<"Win"<<endl;
            break;
        }
        /////////////////////impressões//////////////////////////////////////////
        cout<<"------------------------------------------"<<endl;
        cout << "\033[1;35m" << "Matrix Information" << "\033[0m" << endl<<endl;
        cout<<"\033[1;32m" <<"Maze "<<currentN<<":"<< "\033[0m" <<endl;
        printMatrixWithColor(matrixMaze,nRows,nCols,currentX,currentY);
        cout<<endl;
        printMatrixWithColor(currentMovesMatrix,nRows,nCols,currentX,currentY);
        //printMaze(currentMovesMatrix,nRows,nCols);
        cout<<endl;
        cout<<"Position: ("<<currentX<< ","<<currentY<<")" <<endl;
        cout<<"Total Moves: "<<totalMoves<<endl;
        cout<<"Current Matrix Moves: "<<currentMatrixMoves<<endl;
        cout<<"------------------------------------------"<<endl;
        cout<<"\033[1;32m" <<"Character information"<< "\033[0m" <<endl;
        cout<<"HP: "<<HP<<endl;
        cout<<"Bag Items: "<<bag<<endl;
        cout<<"Total items catched: "<<bagTotal<<endl;
        cout<<"Total dangers faced: "<<dangerCount<<endl;
        cout<<"------------------------------------------"<<endl;
        //////////////////////////////ações///////////////////////////////////////
        cout<<"\033[1;32m" <<"Battle log: "<< "\033[0m" <<endl;
        valorPosicao=matrixMaze[currentX][currentY]-'0';
        if(matrixMaze[currentX][currentY]=='*'){
            HP--;
            dangerCount++;
            cout<<"Danger, took damage"<<endl;
            catchedItem=false;
            if(HP==0){
                cout << "\033[1;31m" << "Lose, you died." << "\033[0m" << endl<<endl;
                break;
            }
        }else if((valorPosicao>=1)&&(valorPosicao<10)){
            bag++;bagTotal++;
            if(bag==4){
                if(HP<10){
                    HP++;
                    cout<<"4 Items catched! Life increased!!! 1+ HP"<<endl;
                    bag=0;
                }else{
                    bag=0;
                    cout<<"4 Items catched! Max life, emptying bag..."<<endl;
                }
            }
            aux=to_string(valorPosicao-1);
            matrixMaze[currentX][currentY]=aux[0];
        }else{
            catchedItem=false;
        }
        //teletransporte
        if((currentX==0||currentY==0||currentX==nRows-1||currentY==nCols-1)&&(currentMatrixMoves>10)&&(n>1)){
            cout<<"Teletransporta"<<endl;
            currentMatrixMoves=0;
            writeOutputSave(matrixMaze, nRows, nCols,currentN); //salva a matriz trabalhada
            generateMovementMatrixSave(currentMovesMatrix,nRows,nCols,currentN); //salva a matriz de movimentos
            if(currentN==n-1){
                currentN=0;
                cicles++;
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

            //fechanddo o arquivo
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
        std::setbuf(stdin,0);  
    }

    cout<<"------------------------------------------"<<endl;
    
    cout<<"\033[1;35m" <<"Final Stats: "<<"\033[0m" <<endl;
    cout<<"Number Positions not visited:"<<getNumberPositionsNotVisited(currentMovesMatrix,nRows,nCols,n)<<endl;
    cout<<"Total items catched: "<<bagTotal<<endl;
    cout<<"Total dangers faced: "<<dangerCount<<endl;
    cout<<"Total Moves: "<<totalMoves<<endl;

    //liberando matriz
    freeMatrix(matrixMaze, nRows);
    freeMatrix(currentMovesMatrix, nRows);
}