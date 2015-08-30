#include <stdio.h>


int del_substr(char *str, char const *sub ){
	int ret_val = 0;
	char *st;
	char const *su;
	char *str_ori = str;
	
	while(*str != '\0'){
		if( *str == *sub ){
			su = sub;
			st = str;

			while( *su != '\0' ){
				if( *su == *st ){
					su++;
					st++;
					ret_val = 1;
				}
				else{
					ret_val = 0;
					break;
				}
			}

			if( ret_val == 1 ){
				while( *sub != '\0' ){
					*str = *st;
					str++;
					st++;
					sub++;
				}
				printf("The after deletion arg str is:%s\n", str_ori);
			}
			else{
				str++;
			}
		}

		else{
			str++;
		}
	}
	return ret_val;
}

int main(void){
	char str[100];
	char sub[100];
	printf("Enter the source string:");
	scanf("%s", str);
	printf("Enter the sub string:");
	scanf("%s", sub);
	printf("substr exists? return = %d\n", del_substr(str, (char const *)sub));
	return 0;
}
