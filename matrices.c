#include "matrices.h"
#include <stdio.h>
#include <math.h>

//Matrix initialization
void initMatrix_f(Matrix_f *mat)
{
    mat->x_n = 0;
    mat->y_n = 0;
}

void initMatrix(Matrix *mat)
{
    mat->x_n = 0;
    mat->y_n = 0;
}

//Matrix representation in terminal
void drawMatrix_f(Matrix_f *mat)
{
    if(mat->x_n <= 0 || mat->y_n <= 0)
        return;

    if(mat->x_n <= 0 || mat->y_n <= 0)
        return;

    //First char
    printf("%c", (char) 218);

    //spaces
    for(int i = 0; i < mat->x_n; i++)
        printf("        ");

    printf("%c\n", (char) 191);

    for(int y = 0; y < mat->y_n; y++)
    {
        printf("%c", (char) 179);

        for(int x = 0; x < mat->x_n; x++)
        {
            if(mat->data[x][y] < 10 && mat->data[x][y] >= 0)
                printf("  %.2lf  ", mat->data[x][y]);
            else
                printf("  %.2lf ", mat->data[x][y]);
        }

        printf("%c\n", (char) 179);

        if(y + 1 == mat->y_n)
            break;

        printf("%c", (char) 179);

        for(int i = 0; i < mat->x_n; i++)
            printf("        ");

        printf("%c\n", (char) 179);
    }

    printf("%c", (char) 192);

    //spaces
    for(int i = 0; i < mat->x_n; i++)
        printf("        ");

    printf("%c\n\n", (char) 217);

}

void drawMatrix(Matrix *mat)
{
    if(mat->x_n <= 0 || mat->y_n <= 0)
        return;

    //First char
    printf("%c", (char) 218);

    //spaces
    for(int i = 0; i < mat->x_n; i++)
        printf("     ");

    printf("%c\n", (char) 191);

    for(int y = 0; y < mat->y_n; y++)
    {
        printf("%c", (char) 179);

        for(int x = 0; x < mat->x_n; x++)
        {
            if(mat->data[x][y] < 10)
                printf("  %d  ", mat->data[x][y]);
            else
                printf("  %d ", mat->data[x][y]);
        }

        printf("%c\n", (char) 179);

        if(y + 1 == mat->y_n)
            break;

        printf("%c", (char) 179);

        for(int i = 0; i < mat->x_n; i++)
            printf("     ");

        printf("%c\n", (char) 179);

    }

    printf("%c", (char) 192);

    //spaces
    for(int i = 0; i < mat->x_n; i++)
        printf("     ");

    printf("%c\n\n", (char) 217);
}

//Gaussian elimination algorithm
void gaussElimination_f(Matrix_f *mat)
{
    double valueBuffer, factorBuffer;
    for(int x = 0; x < mat->x_n; x++)
    {
        for(int y = x + 1; y < mat->y_n; y++)
        {
            valueBuffer = mat->data[x][y];

            if(valueBuffer == 0)
                continue;

            for(int x_i = 0; x_i < mat->x_n; x_i++)
            {
                mat->data[x_i][y] = ((double) mat->data[x_i][y] / (double) valueBuffer * (double) mat->data[x][x]) - (double) mat->data[x_i][x];
                if(fabs(mat->data[x_i][y]) < 0.01)
                {
                    mat->data[x_i][y] = 0;
                }
            }

            drawMatrix_f(mat);
        }
    }
}

//Determinant calculation ! MUST BE SQUARE MATRIX
double determinant_f(Matrix_f *mat)
{

}

int determinant(Matrix *mat)
{

}

//Returns whether or not the matrix is square
bool isMatrixSquare_f(Matrix_f *mat)
{
    return mat->x_n == mat->y_n;
}

bool isMatrixSquare(Matrix *mat)
{
    return mat->x_n == mat->y_n;
}
