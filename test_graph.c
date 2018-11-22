#include "lists.h"
#include "matrices.h"

int main()
{
    Matrix_f mat;
    initMatrix_f(&mat);

    mat.x_n = 3;
    mat.y_n = 3;

    mat.data[0][0] = 1; mat.data[1][0] = 1; mat.data[2][0] = 2;
    mat.data[0][1] = 2; mat.data[1][1] = 1; mat.data[2][1] = 1;
    mat.data[0][2] = 4; mat.data[1][2] = 3; mat.data[2][2] = 5;

    drawMatrix_f(&mat);

    gaussElimination_f(&mat);

    return 0;
}
