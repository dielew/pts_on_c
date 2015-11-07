#include <stdio.h>


int count_chars( char const *str, char const *chars ){

	int ch_counter = 0;
	char const *str_pt = str;
	char const *chars_pt = chars;
	
	while( *str_pt != '\0' ){
		while( *chars_pt != '\0' ){
			if( *str_pt == *chars_pt ){
				ch_counter += 1;
				break;
			}
			else{
				chars_pt++;
			}
		}
		chars_pt = chars;
		str_pt++;
	}

	return  ch_counter;
}


int main( void ){

	char str1[] = "Hello,World!";
	char chars1[] = "lo";
	printf("%d char(s) in '%s' match(es) element(s) of char array '%s'\n", count_chars(str1, chars1), str1, chars1);

	char str2[] = "1234567890";
	char chars2[] = "abcdefghijklm";
	printf("%d char(s) in '%s' match(es) element(s) of char array '%s'\n", count_chars(str2, chars2), str2, chars2);

	char str3[] = "First of All";
	char chars3[] = "FA";
	printf("%d char(s) in '%s' match(es) element(s) of char array '%s'\n", count_chars(str3, chars3), str3, chars3);

	return 0;
}
