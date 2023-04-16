#ifndef __MAZE_HPP
#define __MAZE_HPP
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

char** read_Maze(char** matrixMaze, unsigned int nRows, unsigned int nCols, ifstream &inFile);
void printMaze(char** matrixMaze,unsigned int nRows, unsigned int nCols);
char**allocateMatrix(unsigned int nRows,  unsigned int nCols);
void freeMatrix(char**matrixMaze, unsigned int nRows);
void writeOutputSave(char**matrixMaze, unsigned int nRows, unsigned int nCols, unsigned int n);
#endif