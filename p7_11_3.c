#include <stdio.h>
#include <limits.h>

#define STR_VOL 25


long ascii_to_integer( char *string ){
	char *digit_pt = string;
	char digit;
	long d_value = 0; 
	long ret_value = 0;
	
	if( NULL != digit_pt ){	
		while( *digit_pt != '\0' ){
			digit = *digit_pt;
			d_value = digit - '0';

			if( d_value >= 0 && d_value <= 9 ){
				;
			}
			else{
				ret_value = 0;
				break;
			}

			ret_value *= 10;
			ret_value += d_value;
				//old value times 10 simulating the carry action, and plus new value which repr by new digit
				//to simulate the sequence of input order of digit string.
			if( ret_value < 0 || ret_value > LONG_MAX ){
				ret_value = 0;
				break;  
			}	//when return value reaches upper bound, say greater than 2^63 - 1 , return value sets to 0.
			
			else{
				;
			}

			digit_pt++;
		}
	}
	else{
		ret_value = 0;
	}

	return ret_value;
		
}


int main(void){
	char string[STR_VOL];

	printf("Please enter a string consisting of digit number characters(<20 digit chars):");
	scanf("%s", string);
	printf("The String you entered is:%s\n", string);
	printf("The value of the atoi function call is:%ld\n", ascii_to_integer(string));
	
	return 0;
}
