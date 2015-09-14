#include <stdio.h>



int hermite( int n, int x ){
	int ret_val;         //identifier 'ret_val' stands for return value.
	if( n <= 0 ){
		ret_val = 1;
	}

	if( n == 1 ){
		ret_val = 2 * x;
	}		

	if( n >= 2 ){
		ret_val = (2 * x * hermite(n - 1, x)) - (2 * (n - 1) * hermite(n - 2, x));
	}

	return ret_val;
}


int main(void){
	int n, x;

	printf("Please enter the arg value of sub n in hermite function:");
	scanf("%d", &n);
	printf("Please enter the arg value of x in hermite function:");
	scanf("%d", &x);

	printf("The result of hermite function H sub %d of %d is: %d\n", n, x, hermite(n, x));

	return 0;
}
