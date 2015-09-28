#include <stdio.h>

#define SIZE 5


int identity_matrix( int matrix[][SIZE] ){
	int ret_boolean_val;
	int r = 0, c = 0;

	while( r < SIZE ){
		while( c < SIZE ){
			if( c == r ){
				if( matrix[r][c] ){
					ret_boolean_val = 1;
				}
				else{
					ret_boolean_val = 0;
					break;
				}
			}
			else{
				if( !matrix[r][c] ){
					ret_boolean_val = 1;
				}
				else{
					ret_boolean_val = 0;
					break;
				}
			}
			c += 1;
		}

		if( !ret_boolean_val ){
			break;
		}
		else{
			;
		}

		r += 1;
		c = 0;
	}

	return ret_boolean_val;
}


int main(void){
	int m1[SIZE][SIZE] = {
		{1, 0, 0, 0, 0},
		{0, 1, 0, 0, 0},
		{0, 0, 1, 0, 0},
		{0, 0, 0, 1, 0},
		{0, 0, 0, 0, 1},
	};
	int m2[SIZE][SIZE] = {
		{1, 0, 0, 0, 0},
		{0, 1, 0, 0, 0},
		{0, 0, 1, 0, 0},
		{0, 0, 0, 1, 0},
		{0, 0, 0, 0, 0},
	};
	int m3[SIZE][SIZE] = {
		{1, 0, 0, 0, 0},
		{0, 1, 0, 0, 0},
		{0, 0, 1, 0, 0},
		{0, 0, 0, 1, 0},
		{0, 0, 0, 1, 1},
	};
	
	int ret_bool1 = identity_matrix(m1);
	int ret_bool2 = identity_matrix(m2);
	int ret_bool3 = identity_matrix(m3);

	printf("m1 identity?(1/0): %d\nm2 identity?(1/0): %d\nm3 identity?(1/0): %d\n", ret_bool1, ret_bool2, ret_bool3);
	
	return 0;
}
