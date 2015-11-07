#include <stdio.h>



char *my_strnchr( char const *str, int ch, int which ){
	
	char *retu_val = NULL;   //no match (which) char at all
	char const *ch_pt = str;
	char const *which_num_pt;
	int which_max;
	int which_iterator;
	int s_len = 0;
	int ch_num = 0;


	for( which_num_pt = str, which_max = 0; *which_num_pt != '\0'; which_num_pt++ ){
		if( *which_num_pt == ch ){
			which_max += 1;
		}
		s_len += 1;
	}
	
	printf("which_max_value is: %d\n", which_max);

	if( which > which_max || which < 1 ){
		;
	}		
		// return NULL when value of arg'which'is out of valid range, we do nothing here becuz initialzing default	
		// value of variable'retu_val' is set to NULL in the first place.
		// furthermore, we can alter this control flow into an alternative structure, 
		// say, by exchanging the expressions and related statements of this if-else control.
	
	else{
		for( which_iterator = 1; which_iterator <= which; which_iterator++ ){
			while( *ch_pt != '\0' ){
				ch_num += 1;
				if( *ch_pt == ch ){
					retu_val = ch_pt;
					ch_pt++;
					break;
				}
				else{
					ch_pt++;
				}
			}
		}
	}
	
	printf("%dth %c in string %s, position is %d/%d\n", which, ch, str, ch_num, s_len);

	return retu_val;
}


int main( void ){

	char str1[] = "Hello,World!";
	char str2[]	= "madamimadam";
	char str3[] = "12345678900987654321";
	
	printf("%s\n", my_strnchr(str1, 'l', 3));
	printf("%s\n", my_strnchr(str2, 'm', 4));
	printf("%s\n", my_strnchr(str3, '0', 1));
	printf("%s\n", my_strnchr(str3, '0', 3));
	printf("%s\n", my_strnchr(str3, '0', 0));

	return 0;
}
