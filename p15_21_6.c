#include <stdio.h>



int numeric_palindrome( int value )
{
	int ret_flag;
	int num = value;
	int least_digit;
	int rev = 0;

	while( num > 0 ){
		least_digit = num % 10;
		rev = rev * 10 + least_digit;
		num = num / 10;
	}

	if( value == rev ){
		ret_flag = 1;
	}
	else{
		ret_flag = 0;
	}

	return ret_flag;
}


int main( void )
{
	printf("Ture or False? Is '1538351' palindrome? %d\n", numeric_palindrome(1538351));
	printf("Ture or False? Is '158351' palindrome? %d\n", numeric_palindrome(158351));
	printf("Ture or False? Is '101' palindrome? %d\n", numeric_palindrome(101));
	printf("Ture or False? Is '1' palindrome? %d\n", numeric_palindrome(1));
	

	return 0;
}

