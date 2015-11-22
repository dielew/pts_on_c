#include <stdio.h>
#include <stdlib.h>


int *ma_arr( void ){
	
	int ch;
	int num = 0;
	int *space_alloc_ptr = malloc(sizeof(int));

	while( (ch = getchar()) != '\n' ){
		num += 1;
		space_alloc_ptr = realloc(space_alloc_ptr, sizeof(int));
		*(space_alloc_ptr + num) = ch - '0';
		printf("until now allocated mem size(bytes):%lu\n", (num + 1) * sizeof(int));
	}

	*space_alloc_ptr = num;

	space_alloc_ptr = realloc(space_alloc_ptr, sizeof(int));
	*(space_alloc_ptr + num + 1) = -1;

	return space_alloc_ptr;
}


int main( void ){
	
	int *start_ptr = ma_arr();
	int *tofree_ptr = start_ptr;
	
	for( ; *start_ptr != -1; start_ptr++ ){
		printf("%d\n", *start_ptr);
	}
	
	free(tofree_ptr);

	return 0;
}
