#include <stdio.h>
#include <stdlib.h>


int joke_29( int literal_value )
{
	int base = (literal_value - 9) / 2;
	
	if( base < 2 || base > 36 ){
		base = -1;
	}
	else{
		;
	}
	
	return base;
}


int main( int argc, char** argv )
{
	int base;
	if( argc != 2 ){
		printf("Incorrect argument number!\n");
		exit(0);
	}
	else{
		if( *++argv == NULL ){
			printf("Invalid Argument!\n");
			exit(0);
		}
		else{
			base = joke_29(atoi(*argv));
		}
	}
	if( base == -1 ){
		printf("Out of base(2~36) range or invalid chars!\n");
	}
	else{
		printf("Literal Year %s is 29 of base %d.\n", *argv, base);
	}

	return 0;
}


