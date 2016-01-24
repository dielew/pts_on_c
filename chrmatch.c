#include <stdio.h>



int match_count( char const *str, char const *pos ){
	
	char const *str_ptr = str;
	char const *pos_ptr = pos;
	static int count  = 0;

	for( ; *str_ptr != '\0' && *str_ptr == *pos_ptr; str_ptr++, pos_ptr++ ){
		;
	}

	if( *str_ptr == '\0' ){
		count += 1;
	}
	else{
		;
	}

	return count;
}


void str_search( char const *str, char const *obj ){

	char const *obj_ptr = obj;
	int count;

	for( ; *obj_ptr != '\0'; obj_ptr++ ){
		count = match_count(str, obj_ptr);
	}
	printf("Number of matching strings: %d\n", count);
}


int main( void ){

	char str[] = "o";
	char obj[] = "good morning, sir, o, my god!";

	
	str_search(str, obj);

	return 0;
}
