#include <stdio.h>
#define INI_SIZE 20



char *my_strcat( char *dst, unsigned int array_space, char const *src ){
	
	char *dst_pt;
	char *src_pt;
	char *src_len_counter;
	int used_space;
	int src_space;
	int free_space;

	for( dst_pt = dst, used_space = 0; *dst_pt != '\0'; dst_pt++ ){
		used_space += 1;
	}
	
	for( src_len_counter = src, src_space = 1; *src_len_counter != '\0'; src_len_counter++, src_space += 1 ){
		;
	}
	
	//printf("%d\n", src_space);	
	free_space = array_space - used_space;
	//printf("%d\n", free_space);

	if( src_space <= free_space ){

		for( src_pt = src; *src_pt != '\0'; src_pt++, dst_pt++ ){
			*dst_pt = *src_pt;
		}
		*dst_pt = '\0';

	}
	else{
		return "Error: NOT enough array sapce!";
	}

	return dst;
}


int main( void ){

	char dst[INI_SIZE];
	char *dst_init = dst;
	*dst_init = '\0';

	printf("%s\n", my_strcat(dst, INI_SIZE, "1234567890"));
	printf("%s\n", my_strcat(dst, INI_SIZE, "12345"));
	printf("%s\n", my_strcat(dst, INI_SIZE, "1234"));
	
	return 0;
}
