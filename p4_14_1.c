#include <stdio.h>


double squrt(int num){
	double prev = 1;
	double next;
	double end_posi = 0;
	while (prev != end_posi){
		end_posi = prev;
		next = (prev + (num / prev)) / 2.0;
		prev = next;
	}
	return prev;
}

int main(void){
	int num;
	printf("Please enter a positive integer :");
	scanf("%d", &num);
	if (num > 0){
		printf("The Squareroot of %d is: %-10.10lf \n", num, squrt(num));
	}
	else{
		printf("Error #1 Invalid Input: Input value should be positive integer!\n");
	}

}
