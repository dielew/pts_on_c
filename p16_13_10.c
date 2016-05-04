#include <stdio.h>
#include <stdlib.h>


int int_compare( void const* a, void const* b )
{
	int ret_val = 0;
	if( *((int*)a) - *((int*)b) < 0 ){
		ret_val = 1;
	}
	else{
		ret_val = 0;
	}
	return ret_val;
}




void ins_sort( void *base, size_t n_elements, size_t el_size, int (*compare)( void const *, void const *) )
{
	
	char* tmp_ptr = (char*)malloc(sizeof(el_size));
	int tmp_offset;
	void* k;
	int byte_offset;

	void *i = base + el_size;
	void *j = i - el_size;
	for( ; i < (base + el_size * n_elements); i += el_size, j = i - el_size ){
		if( int_compare(i, j) ){
			for( byte_offset = 0, tmp_offset = 0; byte_offset < el_size; byte_offset += 1, tmp_offset += 1 ){
				*(tmp_ptr + tmp_offset) = *(char*)(i + byte_offset);
			}
			for( k = i;  int_compare(tmp_ptr, k - el_size) && k > base; k-= el_size){
				for( byte_offset = 0; byte_offset < el_size; byte_offset += 1 ){
					*(char*)(k + byte_offset)  = *(char*)(k - el_size + byte_offset);
				}
			}
			for( byte_offset = 0; byte_offset < el_size; byte_offset += 1 ){
				*(char*)(k + byte_offset) = *(tmp_ptr + byte_offset);
			}
		}

		else{
			;
		}

	}
	free(tmp_ptr);
}



int main( void )
{

	int list1[10] = {89,234,123,5634,76,78,35,45,1,23};
	int list2[10] = {89,12,187,535,235,34,5634,345,5,7};
	int list3[10] = {89,234,123,5634,123,732,31,3,4,2};
	int i;

	for( i = 0; i <10; i++ ){
		printf("%d ", list1[i]);
	}	
	printf("\n");
	ins_sort((void*)list1, 10, sizeof(int), int_compare);
	for( i = 0; i <10; i++ ){
		printf("%d ", list1[i]);
	}
	printf("\n");


	for( i = 0; i <10; i++ ){
		printf("%d ", list2[i]);
	}	
	printf("\n");
	ins_sort((void*)list2, 10, sizeof(int), int_compare);
	for( i = 0; i <10; i++ ){
		printf("%d ", list2[i]);
	}
	printf("\n");


	for( i = 0; i <10; i++ ){
		printf("%d ", list3[i]);
	}	
	printf("\n");
	ins_sort((void*)list3, 10, sizeof(int), int_compare);
	for( i = 0; i <10; i++ ){
		printf("%d ", list3[i]);
	}
	printf("\n");

	return 0;

}
