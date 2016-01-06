#include <stdio.h>
#include <ctype.h>



void chr_percent( char const *str ){

	int count[7] = {0, 0, 0, 0, 0, 0, 0};
	
	int i;
	float sum;

	int (*chr_classify[])(int) = {
		iscntrl, isspace, isdigit, islower, isupper, ispunct, isprint
	};

	char const *str_ptr = str;

	for( sum = 0; *str_ptr != '\0'; str_ptr++, sum += 1.0 ){
		for( i = 0; i < 7; i++ ){
			if( chr_classify[i]( (int)(*str_ptr) ) == 1 ){
				count[i] += 1;
			}
			else{
				;
			}
		}
	}

	printf("number of total char is = %f\n", sum);
	printf("percentage of control char = %f\n", count[0]/sum);
	printf("percentage of space char = %f\n", count[1]/sum);
	printf("percentage of digit char = %f\n", count[2]/sum);
	printf("percentage of lowercase char = %f\n", count[3]/sum);
	printf("percentage of uppercase char = %f\n", count[4]/sum);
	printf("percentage of punctuation char = %f\n", count[5]/sum);
	printf("percentage of unprintable char = %f\n", (sum -count[6])/sum);

}

int main( void ){

	char str[200];

	fgets(str, 199, stdin);
	chr_percent(str);
	
	return 0;
}
