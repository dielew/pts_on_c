#include <stdio.h>
#include <stdarg.h>


int max_list( int n_num, ... ){

	va_list num_var_list;
	int sub = 0;
	int max_value = -1; 
	int test_value, ret_value;

	va_start(num_var_list, n_num);
	
	while( sub < n_num ){
		test_value = va_arg(num_var_list, int);

		if( test_value < 0 ){
			ret_value = max_value;
			break;
		}
		else{
			if( max_value >= test_value ){
				;
			}
			else{
				max_value = test_value;
			}
		}	
		ret_value = max_value;
		sub++;
	}

	va_end(num_var_list);

	return ret_value;
}


int main(void){

	int result1 = max_list(5, 9, 8, 7, 1, -1);
	int result2 = max_list(10, 9, 8, 7, 1, 189, 78, 999, 21, 8, -1);
	int result3 = max_list(10, 9, 8888, 7, 1, 189, 78, 999, 21, 8, -1);
	int result4 = max_list(10, 9, 8, 7, 31, 1891231, 78, 999, 21, 8, -1);
	int result5 = max_list(5, -9, 8, 7, 1, -1);

	printf("max1:%d\nmax2:%d\nmax3:%d\nmax4:%d\nmax5:%d\n", result1, result2, result3, result4, result5);
	
	return 0;
}
