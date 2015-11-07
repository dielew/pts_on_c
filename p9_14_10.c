#include <stdio.h>
#include <ctype.h>


int palindrome( char *string ){

	char *head = string;
	char *tail = string;
	int flag = 0;

	for( ; *head != '\0'; head++ ){
		;
	}
	tail = head - 1;
	head = string;

	for( ; tail >= head; head++, tail-- ){
		while( isalpha(*head) == 0 ){
			head++;
		}
		
		while( isalpha(*tail) == 0 ){
			tail--;
		}	

		if( *tail == *head || *tail + 32 == *head || *tail - 32 == *head ){
			flag = 1;
		}
		else{
			flag = 0;
		}
	}	

	return flag;
}

int main( void ){

	char str1[] = "madamimadam";
	char str2[] = "Madam, i' m Adam";
	char str3[] = "Madam,  i'   m  12313 Adam";
	char str4[] = "Madam, i' am Adam";
	char str5[] = "Maadam, i' m Adam";
	char str6[] = "ada";
	char str7[] = "ee";

	printf("the string is '%s', is it a palindrome? : %d\n", str1, palindrome(str1));
	printf("the string is '%s', is it a palindrome? : %d\n", str2, palindrome(str2));
	printf("the string is '%s', is it a palindrome? : %d\n", str3, palindrome(str3));
	printf("the string is '%s', is it a palindrome? : %d\n", str4, palindrome(str4));
	printf("the string is '%s', is it a palindrome? : %d\n", str5, palindrome(str5));
	printf("the string is '%s', is it a palindrome? : %d\n", str6, palindrome(str6));
	printf("the string is '%s', is it a palindrome? : %d\n", str7, palindrome(str7));

	return 0;
}
