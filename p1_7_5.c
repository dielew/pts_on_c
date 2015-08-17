#include <stdio.h>
#define MAX_DEPT_Name 100

int main(void){
	int quantity, price;
	char department[MAX_DEPT_Name];

	scanf("%d %d %s", &quantity, &price, department);
	printf("quantity = %d\nprice = %d\ndept_name = %s\n", quantity, price, department);	

}

