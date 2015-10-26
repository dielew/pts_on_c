#include <stdio.h>


char *my_strcpy_end( char *dst, char const *src ){

	char *src_pt;
	char *dst_pt;
	char *end;

	for( src_pt = src, dst_pt = dst; *src_pt != '\0'; src_pt++, dst_pt++ ){
		*dst_pt = *src_pt;
	}
	*dst_pt = '\0';
	end = dst_pt;

	return end;
}



int main( void ){

	char dst[] = "1234567890987654321";
	char src[] = "Hello World!";
	printf("%s\n%s\n", dst, my_strcpy_end(dst, src));


	return 0;
}
