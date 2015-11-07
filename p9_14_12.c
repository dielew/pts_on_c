#include <stdio.h>


int prepare_key( char *key ){

	char *key_pt = key;
	char *key_repe_pt;
	char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
	char key_res[] = "abcdefghijklmnopqrstuvwxyz";
	char *alpha_pt;
	char *key_res_pt;
	int isalpha_flag = 1;


	//IS string 'key' empty? 
	if( *key_pt == '\0' ){
		isalpha_flag = 0;
	}

	//IS 'key' only has alphabet elements or NOT? Go for check.
	for( key_pt = key; *key_pt != '\0'; key_pt++ ){	
		if( ( (!isalpha_flag) || *key_pt < 65 || *key_pt > 122) || (*key_pt > 90 && *key_pt < 97) ){
			isalpha_flag = 0;	
		}
	}

	// Unification of letters in 'key': Upper or Lowercase? Here we choose lowercase.
	if( isalpha_flag ){	
		for( key_pt = key; *key_pt != '\0'; key_pt++ ){
			if( *key_pt > 64 && *key_pt < 91 ){
				*key_pt += 32;
			}
		}
	
	// Omitting repetition of letters in string 'key': Only one copy in alphabetic remains.
	// Details: two pointers go for two loops(outter and inner) in target string, if two pointed to the same, then... 
		for( key_pt = key; *key_pt != '\0'; key_pt++ ){
			for( key_repe_pt = key; key_repe_pt < key_pt; key_repe_pt++ ){
				if( *key_repe_pt == *key_pt ){
					*key_pt = '0';
				}
			}
		}

	// After last step, we have all unique chars in 'key', repetitional chars are replaced with '0', as mark.	
	// printf("key is:%s\n", key);
	
	// Marking: make 'alphabet' have all letters in the alphabet but letters in 'key'.
		for( alpha_pt = alphabet; *alpha_pt != '\0'; alpha_pt++ ){
			for( key_pt = key; *key_pt != '\0'; key_pt++ ){
				if( *alpha_pt == *key_pt ){
					*alpha_pt = '0';
				}
			}
		}	
	
	// To copy valid letters of 'key' to 'key_res'(result key) from start, in accordance with the squence.
		for( key_res_pt = key_res, key_pt = key; *key_pt != '\0'; key_pt++ ){
			if( *key_pt != '0' ){
				*key_res_pt = *key_pt;
				key_res_pt++;
			}
		}
			
	// printf("alphabet is:%s\n", alphabet);		
	// printf("*key_res_pt is:%c\n", *key_res_pt);		
	// printf("*key_pt is:%c\n", *key_pt);		
	// To copy valid letters of 'alphabet' to 'key_res' from last position, in order.
		for( alpha_pt = alphabet;  *key_res_pt != '\0'; alpha_pt++ ){
			if( *alpha_pt != '0' ){
				*key_res_pt = *alpha_pt;
				key_res_pt++;
			}
		}
		printf("the final generated key is:%s\n", key_res);	
	}	

	return isalpha_flag;
}


int main( void ){

	char key1[] = "TRAILBLAzERS";
	char key2[] = "trailblazers";
	char key3[] = "TrailBlazers";
	char key4[] = "$#!#TrailB123123";
	char key5[] = "TrailBlazer";
	char key6[] = "";
	char key7[] = "dielew";
	char key8[] = "abcdefghijklmnopqurstuvwxyz";
	char key9[] = "mnopqrstuvwxy";
	

	printf("%d\n", prepare_key(key1));
	printf("%d\n", prepare_key(key2));
	printf("%d\n", prepare_key(key3));
	printf("%d\n", prepare_key(key4));
	printf("%d\n", prepare_key(key5));
	printf("%d\n", prepare_key(key6));
	printf("%d\n", prepare_key(key7));
	printf("%d\n", prepare_key(key8));
	printf("%d\n", prepare_key(key9));
	
	return 0;
}
