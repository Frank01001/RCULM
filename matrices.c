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
            if(mat->data[x][y] < -10)
                printf(" %d ", mat->data[x][y]);
            else if(mat->data[x][y] < 0)
                printf("  %d ", mat->data[x][y]);
            else if(mat->data[x][y] < 10)
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
void gaussElimination_f(Matrix_f *mat, bool intermediateSteps)
{
    double valueBuffer;

    for(int x = 0; x < mat->x_n; x++)
    {
        if(mat->data[x][x] == 0)
            for(int y_i = x + 1; y_i < mat->y_n; y_i++)
            {
                //Swap Rows if necessary
                if(mat->data[x][y_i] != 0)
                {
                    swapRows_f(mat, x, y_i);
                    break;
                }
            }

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

            if(intermediateSteps)
                drawMatrix_f(mat);
        }
    }
}

//Determinant calculation ! MUST BE SQUARE MATRIX
double determinant_f(Matrix_f *mat)
{
    /** Uses Laplace's First Theorem on first row */

    //being a square matrix, x_n = y_n
    if(mat->x_n == 2)
        return mat->data[0][0] * mat->data[1][1] - mat->data[1][0] * mat->data[0][1];

    int curr_x = 0;
    double det = 0;
    int sign;

    //-1 if curr_x + curr_y is odd, +1 otherwise
    for(; curr_x < mat->x_n; curr_x++)
    {
        int sign = (curr_x) % 2 == 1 ? -1 : 1;

        det += (double)sign * mat->data[curr_x][0] * determinant_minor_f(mat, curr_x);
    }

    return det;
}

int determinant(Matrix *mat)
{
    /** Uses Laplace's First Theorem on first row */

    //being a square matrix, x_n = y_n
    if(mat->x_n == 2)
        return mat->data[0][0] * mat->data[1][1] - mat->data[1][0] * mat->data[0][1];

    int curr_x = 0;
    int det = 0;
    int sign;

    //-1 if curr_x + curr_y is odd, +1 otherwise
    for(; curr_x < mat->x_n; curr_x++)
    {
        int sign = (curr_x) % 2 == 1 ? -1 : 1;

        det += sign * mat->data[curr_x][0] * determinant_minor(mat, curr_x);
    }

    return det;
}

double determinant_minor_f(Matrix_f *mat, int min_x)
{
    Matrix_f compl_min;
    initMatrix_f(&compl_min);
    int curr_x;

    compl_min.x_n = mat->x_n - 1;
    compl_min.y_n = mat->y_n - 1;

    //Skips the first row (The minors all belong to the first row)
    for(int y = 1; y < mat->y_n; y++)
    {
        for(int x = 0; x < mat->x_n; x++)
        {
            if(x == min_x)
                continue;

            if(x > min_x)
                compl_min.data[x - 1][y - 1] = mat->data[x][y];
            else
                compl_min.data[x][y - 1] = mat->data[x][y];

        }
    }

    return determinant_f(&compl_min);
}

int determinant_minor(Matrix *mat, int min_x)
{
    Matrix compl_min;
    initMatrix(&compl_min);
    int curr_x;

    compl_min.x_n = mat->x_n - 1;
    compl_min.y_n = mat->y_n - 1;

    //Skips the first row (The minors all belong to the first row)
    for(int y = 1; y < mat->y_n; y++)
    {
        for(int x = 0; x < mat->x_n; x++)
        {
            if(x == min_x)
                continue;

            if(x > min_x)
                compl_min.data[x - 1][y - 1] = mat->data[x][y];
            else
                compl_min.data[x][y - 1] = mat->data[x][y];

        }
    }

    return determinant(&compl_min);
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

void swapRows_f(Matrix_f *mat, int row_a, int row_b)
{
    double row_buffer;

    for(int x_i = 0; x_i < mat->x_n; x_i++)
    {
        //Copy [x_i, y_a] in buffer
        row_buffer = mat->data[x_i][row_a];
        //copy [x_i][y_b] in [x_i, y_a]
        mat->data[x_i][row_a] = mat->data[x_i][row_b];
        //Copy old [x_i][y_a] (row_buffer) in [x_i][y_b]
        mat->data[x_i][row_b] = row_buffer;
    }

}

void swapRows(Matrix *mat, int row_a, int row_b)
{
    int row_buffer;

    for(int x_i = 0; x_i < mat->x_n; x_i++)
    {
        //Copy [x_i, y_a] in buffer
        row_buffer = mat->data[x_i][row_a];
        //copy [x_i][y_b] in [x_i, y_a]
        mat->data[x_i][row_a] = mat->data[x_i][row_b];
        //Copy old [x_i][y_a] (row_buffer) in [x_i][y_b]
        mat->data[x_i][row_b] = row_buffer;
    }
}
