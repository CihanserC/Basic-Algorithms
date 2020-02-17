#include <stdio.h>
#include <stdlib.h>

// 2D arrays.

int main() 
{
    int **matrice;
    int row, column;
    int s, k;
    int i;

    printf("Row of matrice ");
    scanf("%d", &row);

    printf("Column of matrice: ");
    scanf("%d", &column);

    matrice = (int *) calloc(row, sizeof(int));
	// calloc m allocate with 0 
	
    for(i = 0; i < row; i++)
	matrice[i] = (int *) calloc(column, sizeof(int));

    for(s = 0; s < row; s++){
    
	for(k = 0; k < column; k++) {
	    printf("Element of matrice: matris[%d][%d] = ", s, k);
	    scanf("%d", &(matrice[s][k]));
        }
    }        
    printf("\n Matrice :\n");

    for(s = 0; s < row; s++) {
	for(k = 0; k < column; k++){	
	    printf("%4d", matrice[s][k]);}
        printf("\n");
    }

    for(i = 0; i < row; i++)
	free((void *) matrice[i]);
	
    free((void *) matrice);



    return(0);
}
