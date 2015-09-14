#include <stdio.h>


int gcd( int m, int n ){
	int ret_val;   //indentifier 'ret_val' = return value
	int r_val;     //indentifier 'r_val' = remain value
	
	if( m <= 0 || n <= 0 ){
		ret_val = 0;
	}

	else{
		if( m % n == 0 ){
			ret_val = n;
		}
		else{
			r_val = m % n;
			ret_val = gcd(n, r_val);
		}
	
	}

	return ret_val;
}


int main(void){
	int m, n;
	
	printf("Enter one integer num:");
	scanf("%d", &m);
	printf("Enter anthoer integer num:");
	scanf("%d", &n);

	printf("The greatest common divisor of %d and %d is: %d\n", m, n, gcd(m, n));

	return 0;
}
