#include "backsubst.h"
#include <stdio.h>
/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 */
int  backsubst(Matrix *x, Matrix *mat, Matrix *b) {
    //jezeli macierz nie jest kwadratowa return 2
    if(mat->columns != mat->rows || b->columns != 1) {
        return 2;
    }

    //dla latwosci obliczen zostanie utworzona nowa macierz *tmp, ktora bedzie polaczeniem macierzy *mat i *b
    int i, j;
    Matrix *tmp = createMatrix(mat->rows, mat->columns+1);
    for(i = 0; i < mat->rows; i++) {
        for(j = 0; j < mat->columns; j++) {
            tmp->data[i][j] = mat->data[i][j];
        }
        tmp->data[i][mat->columns] = b->data[i][0];
    }

    //funckja odpowiadajaca za podstawienie wsteczne
    double s;
    (*x->data[mat->rows-1]) = tmp->data[mat->rows-1][mat->rows] / tmp->data[mat->rows-1][mat->rows-1];
    for(i=mat->rows-2; i>=0; i--)
    {
        s=0;
        for(j=i+1; j<mat->rows; j++)
        {
            s += (tmp->data[i][j]*(*x->data[j]));
            *x->data[i] = (tmp->data[i][mat->rows]-s)/tmp->data[i][i];
        }
    }

    return 0;
}


