#include <stdio.h>


char *my_strrchr( char const *str, int ch ){

	char *end_pt;
	char *start_pt = str;
	char *return_val = NULL;
	unsigned int counter = 1;
	unsigned int str_len;

	for( end_pt = str; *end_pt != '\0'; end_pt++, counter += 1 ){
		;
	}
	
	str_len = counter - 1;
	
	while( end_pt >= start_pt ){
		if( *end_pt == ch ){
			return_val = end_pt;
			break;
		}
		else{
			;
		}
		end_pt--;
		counter -= 1;
	}

	printf("last position is: %u/%u\n", counter, str_len);

	return return_val;
}

int main( void ){
	
	char str1[] = "Hello,World!";
	char str2[] = "1234567890";
	char str3[] = "0987654321";

	printf("the char is %c(to find chr reversely) in str %s\n", *my_strrchr(str1, 'o'), str1);
	printf("the char is %c(to find chr reversely) in str %s\n", *my_strrchr(str2, '1'), str2);
	printf("the char is %c(to find chr reversely) in str %s\n", *my_strrchr(str3, '1'), str3);
	
	return 0;

}


