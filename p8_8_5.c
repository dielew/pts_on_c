#include <stdio.h>

#define  M  3 
#define  P  2
#define  N  4


/*
Matrix Multiplication Formula: MxP times PxN is MxN  

M_C(sub i, j) = ZIGMA (as k from 1 to y): M_A(sub i, k)  *  M_B(sub k, j) 
*/

void matrix_multiply( int *m1, int *m2, int x, int y, int z ){
	int product[x][z];
	int i, j, k;

	for( i = 0; i < x; i++ ){
		for( j = 0; j < z; j++ ){
			for( k = 0; k < y; k++ ){
				product[i][j] += (*(m1 + y * i + k)) * (*(m2 + k * z + j));
			}
		}
	}	
		
	for( i = 0; i < x; i++ ){
		for( j = 0; j < z; j++ ){
			printf("%d ", product[i][j]);
		}
		printf("\n");
	}
	
}

int main(void){
	int x = M;
	int y = P;
	int z = N;

	int matrix1[M][P] = {
			{2, -6},
			{3,  5},
			{1, -1}	
	};

	int matrix2[P][N] = {
			{4,  -2, -4, -5},
			{-7, -3,  6,  7}
	};
	
	int *m1 = &matrix1[0][0];
	int *m2 = &matrix2[0][0];
	matrix_multiply(m1, m2, x, y, z);
	
	return 0;
}
