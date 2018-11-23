#ifndef MATRICES_H_
#define MATRICES_H_

#include "utils.h"

#define MAX_ROW 32
#define MAX_COL 32
#define MAX_VAL_M 99

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
void gaussElimination_f(Matrix_f *mat, bool intermediateSteps);

//Determinant calculation ! MUST BE SQUARE MATRIX
double determinant_f(Matrix_f *mat);
int determinant(Matrix *mat);
double determinant_minor_f(Matrix_f *mat, int min_x);
int determinant_minor(Matrix *mat, int min_x);

//Returns whether or not the matrix is square
bool isMatrixSquare_f(Matrix_f *mat);
bool isMatrixSquare(Matrix *mat);

//Swaps two rows (ROWs are counted from 0 to n - 1)
void swapRows_f(Matrix_f *mat, int row_a, int row_b);
void swapRows(Matrix *mat, int row_a, int row_b);

#endif // MATRICES_H_
