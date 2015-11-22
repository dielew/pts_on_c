#include <stdio.h>




void dollars( char *dst, char const *src ){

	char *dst_ptr;
	char const *src_ptr;
	int src_len; 
	int order;

	for( src_ptr = src, src_len = 0; *src_ptr != '\0'; src_ptr++ ){
		src_len += 1;
	}
	
	if( src_len >= 3 ){
		for( src_ptr = src, order = 1, dst_ptr = dst; *src_ptr != '\0'; src_ptr++, dst_ptr++, order += 1 ){
			*dst_ptr = *src_ptr;
			if( (src_len - order) % 3 == 2 ){
				if( src_len - order > 2){
					dst_ptr++;
					*dst_ptr = ',';
				}	
				else{	
					dst_ptr++;
					*dst_ptr = '.';
				}
			}
		}
	}

	else{ 
		dst_ptr = dst;
		*dst_ptr = '0';
		dst_ptr++;
		*dst_ptr = '.';
		dst_ptr++;

		if( src_len == 0 ){
			*dst_ptr = '0';
			dst_ptr++;
			*dst_ptr = '0';
			dst_ptr++;
		}

		if( src_len == 1 ){
			*dst_ptr = '0';
			dst_ptr++;
			src_ptr = src;
			*dst_ptr = *src_ptr;
			dst_ptr++;
		}

		if( src_len == 2 ){
			for( src_ptr = src; *src_ptr != '\0'; src_ptr++, dst_ptr++ ){
				*dst_ptr = *src_ptr;	
			}
		}
	}
	
	*dst_ptr = '\0';
	printf("$ %s\n", dst);

}



int main( void ){
	
	char src[32];
	char dst[32];

	scanf("%s", src);
	dollars(dst, src);

	return 0;
}
