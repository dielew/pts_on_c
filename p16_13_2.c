#include <stdio.h>
#include <stdlib.h>
#include <time.h>




int randint_six( void )
{
	int rand_int = rand() % 6;
	return rand_int + 1;
}

int main( void )
{
	int i;

	srand( (unsigned int)(time(0)) );
	
	for( i = 0; i < 20; i++ ){
		printf("%d\n", randint_six());
	}

	return 0;
}

