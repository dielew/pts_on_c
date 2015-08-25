#include <stdio.h>
#include <string.h>


char *copy_n( char dst[], char src[], int n ){
	int n_len_comp = n - strlen(src);
	int i;
	if( n_len_comp <= 0 ){
		for( i = 0; i < n; i++ )
			dst[i] = src[i];
	}
	else{
		for( i = 0; i < strlen(src); i++ )
			dst[i] = src[i];
		
		for( i = strlen(src); i < n; i++ )
			dst[i] = '\0';
	}
			
	return  dst;
}

int main(void){
	char src[1000], dst[1001];
	int n;	
	printf("Please enter a string: ");
	fgets(src, 1000, stdin);
	printf("How many characters would you like to copy: ");
	scanf("%d", &n);
	printf("The result of copy_n() for %s is: %s\n", src, copy_n(dst, src, n));
	return 0;
}

