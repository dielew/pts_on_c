#include <stdio.h>

#define Value 500000


char *eratothenes(char *array){
	char *numerator = array + 1;
	char *denominator = array;
	*numerator = '1';
	*denominator = '1';
	int num_value;
	int den_value = 3;
	
	while( *denominator != '\0' ){
		while( *denominator == '1' ){
			numerator = denominator + 1;
			num_value = den_value + 2;
			while( *numerator != '\0' ){
				if( num_value % den_value != 0 && *numerator != '0'){
					*numerator = '1';
					//printf("%c %d\n", *numerator, num_value);
				}
				else{
					*numerator = '0';
					//printf("%c %d\n", *numerator, num_value);
				}
				num_value += 2;
				numerator++;
			}

			den_value += 2;
			denominator++;

		}
		den_value += 2;
		denominator++;
	}
	return array;
}

int main(void){

	char array[Value];
	char *ini_pt;
	char *print_pt;
	char *result;
	unsigned long int count_val = 1;

	for( ini_pt = array; ini_pt < array + Value - 1; ini_pt++ ){
		*ini_pt = '1';

	}
	result = eratothenes(array);
	printf("%s\n2 ", result);	
	for( print_pt = result; print_pt < array + Value - 1; print_pt++ ){
		if( *print_pt == '1' ){
			count_val += 2;
			printf("%lu ", count_val);
		}
		else{
			count_val += 2;
		}
	}
	printf("\n");
	return 0;

}
