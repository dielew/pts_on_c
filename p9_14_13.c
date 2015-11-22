#include <stdio.h>


void encrypt( char *data, char const *key ){

	char *data_ptr = data;
	char const *key_ptr = key;
	char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
	char *alpha_ptr = alphabet;
	int offset = 0;	

	printf("the original text is '%s'.\n", data);

	for( ; *data_ptr != '\0'; data_ptr++ ){
		if( (*data_ptr > 64 && *data_ptr < 91) || (*data_ptr > 96 && *data_ptr < 123) ){
			if( *data_ptr > 64 && *data_ptr < 91 ){		
				for( alpha_ptr = alphabet, offset = 0; *data_ptr != *alpha_ptr - 32; alpha_ptr++ ){
					offset += 1;		
				}
				*data_ptr = (*(key_ptr + offset) - 32);
			}

			else{
				for( alpha_ptr = alphabet, offset = 0; *data_ptr != *alpha_ptr; alpha_ptr++ ){
					offset += 1;		
				}
				*data_ptr = *(key_ptr + offset);
			}
		}
	}
	printf("the encrypted string is '%s'.\nthe encryption key is '%s'\n", data, key);
}


int main( void ){
	char const key[] = "trailbzescdfghjkmnopquvwxy";
	char data1[] = "ATTACK at Dawn";
	
	encrypt(data1, key);
	
	return 0;
}
