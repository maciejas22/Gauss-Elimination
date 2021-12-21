#include "gauss.h"
#include "backsubst.h"
#include "mat_io.h"
#include <stdlib.h>
#include <stdio.h>


int main(int argc, char ** argv) {
	int res;
	Matrix * A = readFromFile(argv[1]);
	Matrix * b = readFromFile(argv[2]);
	Matrix * x;

	if (A == NULL) return -1;
	if (b == NULL) return -2;
	printToScreen(A);
    printToScreen(b);

	res = eliminate(A,b);
    if(res == 1) {
        fprintf(stderr,"Błąd! Dzielenie przez 0.\n");
        return 1;
    }

	x = createMatrix(b->rows, 1);
    res = backsubst(x,A,b);
    if(res == 2) {
        fprintf(stderr,"Błąd! Macierz nieprawidlowych rozmiarow.\n");
        return 2;
    }
    
    printToScreen(x);
    freeMatrix(x);
	freeMatrix(A);
	freeMatrix(b);

	return 0;
}
