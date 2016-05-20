#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define Omega_NUM 200000000


double stat_pai( void )
{
	double qua_pai;
	double x; 
	double y;
	unsigned long long omega;
	double hit_count = 0;

	for( omega = 0; omega < Omega_NUM; omega++ ){
		x = rand() / (double)RAND_MAX;
		y = rand() / (double)RAND_MAX;
		
		if( (x * x) + (y * y) <= 1 ){
			hit_count += 1;
		}
		else{
			;
		}
	}

	qua_pai = (double)hit_count / (double)Omega_NUM;
	return qua_pai * 4.0f;
}	


int main( void )
{
	srand((unsigned int)time(0));
	
	double pai = stat_pai();

	printf("the value of pai = %lf\n", pai);

	return 0;
}







