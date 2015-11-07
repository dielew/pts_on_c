#include <stdio.h>



unsigned int len_w( char *word ){
	
	unsigned int len_w = 0;
	char *w_pt;
	for( w_pt = word; *w_pt != '\0'; w_pt++ ){
		len_w += 1;
	}
	return len_w;
}


int word_count( char const *string, char const *word ){

	char *str_pt;
	char *str_pt_cmp;
	char *str_pt_len;
	char *word_pt;

	int flag = 0;
	int counter = 0;
	unsigned int len_str;
	unsigned int len_word = len_w(word);


	for( str_pt = string, word_pt = word; *str_pt != '\0'; str_pt++, word_pt = word ){
		
		if( (*str_pt != ' ' ) && ((*(str_pt - 1) == ' ') || str_pt == string) ){
			for( len_str = 0, str_pt_len = str_pt; *str_pt_len != ' '; str_pt_len++ ){
				len_str += 1;
			}
		}
		
		//printf("%u\n", len_word);
		//printf("%u\n", len_str);
		
		if( len_str == len_word ){		

			if( *str_pt == *word_pt ){
				str_pt_cmp = str_pt;

				while( *word_pt != '\0' ){
					if( *str_pt_cmp == *word_pt ){
						flag = 1;
					}
					else{
						flag = 0;
						break;
					}
				
					word_pt++;
					str_pt_cmp++;
				}

				if( flag ){
					counter += 1;
				}
			}
		}

	}

	return counter;
}	

int main( void ){

	char word[] = "the";
	char string[101];
	fgets(string, 101, stdin);
	printf("There is %u of word '%s' in input string: %s", word_count(string, word), word, string);

	return 0;
}
