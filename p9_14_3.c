#include <stdio.h>
#include <string.h>


char *my_strcpy( char *dst, char *src ){

	unsigned int len_dst = strlen(dst);
	unsigned int len_src = strlen(src);
	char *dst_pt;
	char *src_pt;

	printf("str_dst = %u  str_src = %u\n", len_dst, len_src);

	if( len_dst < len_src ){
		return "-1";
	}

	if( len_dst == len_src ){
		for( dst_pt = dst, src_pt = src; *src_pt != '\0'; dst_pt++, src_pt++ ){
			*dst_pt = *src_pt;
		}
	}
	else{
		for( dst_pt = dst, src_pt = src; *src_pt != '\0'; dst_pt++, src_pt++ ){
			*dst_pt = *src_pt;
		}
		*dst_pt = '\0';
	}

	return dst;
}


int main(void){

	char dst0[] = "0123456789";
	char src0[] = "12345";
	printf("%s\n", my_strcpy(dst0, src0));


	char dst1[] = "0123456789";
	char src1[] = "9876543210";
	printf("%s\n", my_strcpy(dst1, src1));


	char dst2[] = "0123456789";
	char src2[] = "123456789098765";
	printf("%s\n", my_strcpy(dst2, src2));

	return 0;
}



