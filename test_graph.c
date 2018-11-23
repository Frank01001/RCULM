#include "lists.h"
#include "matrices.h"

int main()
{
    Matrix_f mat;
    initMatrix_f(&mat);

    mat.x_n = 4;
    mat.y_n = 4;

    mat.data[0][0] = 2; mat.data[1][0] = 3; mat.data[2][0] = 4; mat.data[3][0] = -2;
    mat.data[0][1] = 1; mat.data[1][1] = -2; mat.data[2][1] = 4; mat.data[3][1] = -3;
    mat.data[0][2] = 4; mat.data[1][2] = 3; mat.data[2][2] = -1; mat.data[3][2] = 1;
    mat.data[0][3] = 3; mat.data[1][3] = -4; mat.data[2][3] = 2; mat.data[3][3] = -2;

    drawMatrix_f(&mat);

    if(isMatrixSquare_f(&mat))
        printf("The matrix is SQUARE -> DET: %lf\n\n", determinant_f(&mat));

    gaussElimination_f(&mat, false);

    drawMatrix_f(&mat);

    return 0;
}
