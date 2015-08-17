#include <stdio.h>


int isprime(int num){
	int ispr = 0;
	int divisor;
	if (num == 2)
		ispr = 1;
	else{
		if (num % 2 == 0)
			ispr = 0;
		else{
			for (divisor = num / 2 + 1; divisor > 1; divisor--){
				if (num % divisor != 0)
					ispr = 1;
				else{
					ispr = 0;
					break;
				}
			}
		}
	}
	return ispr;
}

int main(void){
	int i;

	for (i = 1; i <= 100; i++){
		if (isprime(i) == 1)
			printf("%d is prime number.\n", i);
		else
			;
	}

}






