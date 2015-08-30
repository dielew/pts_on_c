#include <stdio.h>
#define V_MAX 1000


void *find_char( char const *source, char const *chars ){
	void *r_val = NULL;
	char const *c_orig = chars;
	if( source == NULL || chars == NULL || *source == '\0' || *chars == '\0' ){
		r_val = NULL;
	}
	else{
		while( *source != '\0' ){
			while( *chars != '\0' ){
				if( *source == *chars ){
					r_val = (void *)source;
					break;
				}
				else{
					chars++;
				}
				
			}
			if( NULL != r_val ){
				break;
			}
			else{
				chars = c_orig;
				source++;
			}
		}
	}
	return r_val;
}


int main(void){
	char source[V_MAX];
	char chars[V_MAX];
	void *res;

	printf("Please input the source string:");
	scanf("%s", source);
	printf("Please input the target string:");
	scanf("%s", chars);

	res = find_char((char const *)source, (char const *)chars);

	if( NULL == res )
		printf("Source string: %s\nTarget string: %s\nChar pointed: matchable char unfound!\n", source, chars);
	else
		printf("Source string: %s\nTarget string: %s\nChar pointed: %c\n", source, chars, *((char const *)res));
	return 0;
}
