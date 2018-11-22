#ifndef MATRICES_H_
#define MATRICES_H_

#include "utils.h"

#define MAX_ROW 32
#define MAX_COL 32
#define MAX_VAL 99

typedef struct
{
    double data[MAX_COL][MAX_ROW];
    int x_n, y_n;
} Matrix_f;

typedef struct
{
    int data[MAX_COL][MAX_ROW];
    int x_n, y_n;
} Matrix;

//Matrix initialization
void initMatrix_f(Matrix_f *mat);
void initMatrix(Matrix *mat);

//Matrix representation in terminal
void drawMatrix_f(Matrix_f *mat);
void drawMatrix(Matrix *mat);

//Gaussian elimination algorithm
void gaussElimination_f(Matrix_f *mat);

//Determinant calculation ! MUST BE SQUARE MATRIX
double determinant_f(Matrix_f *mat);
int determinant(Matrix *mat);

//Returns whether or not the matrix is square
bool isMatrixSquare_f(Matrix_f *mat);
bool isMatrixSquare(Matrix *mat);

#endif // MATRICES_H_
