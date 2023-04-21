#ifndef __MAZE_HPP
#define __MAZE_HPP
#include <iostream>
#include <fstream>
#include <string>
#include <random>
using namespace std;

char** read_Maze(char** matrixMaze, unsigned int nRows, unsigned int nCols, ifstream &inFile);
void printMaze(char** matrixMaze,unsigned int nRows, unsigned int nCols);
char**allocateMatrix(unsigned int nRows,  unsigned int nCols);
void freeMatrix(char**matrixMaze, unsigned int nRows);
void writeOutputSave(char**matrixMaze, unsigned int nRows, unsigned int nCols, unsigned int n);
int generateIndividualMazeFiles(unsigned int* row, unsigned int* col, unsigned int* N);
unsigned int getMovementCase(unsigned int currentX, unsigned int currentY, unsigned int nRows, unsigned int nCols);
void generateNextMove( unsigned int movementCase, unsigned int* currentX, unsigned int* currentY);
void moveLeft(unsigned int* x, unsigned int* y);
void moveRight(unsigned int* x, unsigned int* y);
void moveUp(unsigned int* x, unsigned int* y);
void moveDown(unsigned int* x, unsigned int* y);
void moveLeftTopDiagonal(unsigned int* x, unsigned int* y);
void moveLeftBottomDiagonal(unsigned int* x, unsigned int* y);
void moveRightTopDiagonal(unsigned int* x, unsigned int* y);
void moveRightBottomDiagonal(unsigned int* x, unsigned int* y);
void start(unsigned int nRows, unsigned int nCols, unsigned int n);
void printMatrixWithColor(char** matrixMaze,unsigned int nRows, unsigned int nCols,unsigned int x, unsigned int y);
void generateMovementMatrixSave(char** matrixWithMoves, unsigned int nRows, unsigned int nCols , unsigned int n);
void cleanMatrix(char** matrixWithMoves, unsigned int nRows, unsigned int nCols);

#endif