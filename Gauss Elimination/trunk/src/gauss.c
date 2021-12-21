#include "gauss.h"

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b){
    if(mat->columns != mat->rows || b->columns != 1) {
        return 2;
    }
    //dla latwosci obliczen zostanie utworzona nowa macierz *tmp, ktora bedzie polaczeniem macierzy *mat i *b
    int i, j, k;
    Matrix *tmp = createMatrix(mat->rows, mat->columns+1);
    for(i = 0; i < mat->rows; i++) {
        for(j = 0; j < mat->columns; j++) {
            tmp->data[i][j] = mat->data[i][j];
        }
        tmp->data[i][mat->columns] = b->data[i][0];
    }

    //wykorzystanie elementu maksymalnego oraz sklaujacego
    double c;
    for(i = mat->rows-1;i>0;i--) {
        if(tmp->data[i-1][0]<tmp->data[i][0]) {
            for(j = 0; j <= mat->rows; j++) {
                c = tmp->data[i][j];
                tmp->data[i][j] = tmp->data[i-1][j];
                tmp->data[i-1][j]=c;
            }
        }
    }

    //funkcja odpowiadajaca za utworzenie macierzy schodkowej gornej
    double ratio;
    for(i=0;i<mat->rows;i++)
    {
        //return 1 w przypadku dzielenia przez 0
        if(tmp->data[i][i] == 0.0) {
            return 1;
        }
        for(j=i+1;j<mat->rows;j++)
        {
            ratio = (tmp->data[j][i])/(tmp->data[i][i]);
            for(k=i;k<=mat->rows;k++)
            {
                tmp->data[j][k] = tmp->data[j][k] - ratio*tmp->data[i][k];
            }
        }
    }

    //przepisanie macierzy *tmp do *mat i *b
    for(i = 0; i < mat->rows; i++) {
        for(j = 0; j < mat->rows+1; j++) {
            if(j == mat->rows) {
                b->data[i][0] = tmp->data[i][j];
            }
            else {
                mat->data[i][j] = tmp->data[i][j];
            }
        }
    }

    return 0;
}

