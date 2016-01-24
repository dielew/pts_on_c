#include <stdio.h>





int compare_ints_gt( void *ints_1, void *ints_2 ){

	if( *((int *)ints_1) > *((int *)ints_2) ){
		return 1;
	}
	else{
		return 0;
	}	
}



void sort( void *array_head_ptr, int element_num, int size, int (*compare)(void *, void *)){
	
	void *start_ptr = array_head_ptr;
	void *end_ptr = array_head_ptr + size * (element_num - 1);
	void *comp_ptr;
	char tmp;
	int byte_offset;

	for( ; start_ptr <= end_ptr - size; start_ptr += size ){
		//printf("i = %d\n", *(int *)start_ptr);
		for(comp_ptr = start_ptr + size; comp_ptr <= end_ptr; comp_ptr += size ){
			//printf("j = %d\n", *(int *)comp_ptr);
			//printf("comp_res = %d\n", compare(start_ptr, comp_ptr));
			if( compare(start_ptr, comp_ptr) ){
				for( byte_offset = 0; byte_offset < size; byte_offset += 1 ){
					tmp = *((char *)(start_ptr + byte_offset));						
					*((char *)(start_ptr + byte_offset)) = *((char *)(comp_ptr + byte_offset));
					*((char *)(comp_ptr + byte_offset)) = tmp;
				}	
			}
			else{
				;
			}
		}
	}

}


int main( void ){

	int len1;
	int i1;
	int exp_1[] = {1, 212, 3213, 2, 4, 0, 65, 99999, 121};
	len1 = sizeof(exp_1) / sizeof(int);

	for( i1 = 0; i1 < len1; i1 += 1){
		printf("unsorted elements of the array is %d\n", exp_1[i1]);
	}

	sort((int *)exp_1, len1, sizeof(int), compare_ints_gt);

	for( i1 = 0; i1 < len1; i1 += 1){
		printf("sorted elements of the array is %d\n", exp_1[i1]);
	}
		
	return 0;
}





