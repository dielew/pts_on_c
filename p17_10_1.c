#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define STACK_TYPE int

static STACK_TYPE* stack;
static size_t stack_size;
static int top_element = -1;


void create_stack( size_t size ){
	assert(stack_size == 0 );
	stack_size = size;
	stack = malloc( stack_size * sizeof(STACK_TYPE) );
	assert(stack != NULL);

}

void stack_resize(size_t new_size){
	
	assert(stack_size > 0 );
	realloc(stack, new_size);
	assert(stack != NULL);
}




int main( void ){

	STACK_TYPE* init_ptr;
	STACK_TYPE  test_val;
	size_t res_val = 20;

	create_stack(10);
	for( init_ptr = stack, test_val = 0; init_ptr < stack + 10; init_ptr++, test_val += 1 ){
		*init_ptr = test_val;
	}

	stack_resize(res_val);

	for( init_ptr = stack; init_ptr < stack + res_val; init_ptr++ ){
		printf("%d\n", *init_ptr);
	}
	
	return 0;

}

