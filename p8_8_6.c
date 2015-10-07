#include <stdio.h>
#include <stdarg.h>

#define INVALID -1


int array_offset( int arrayinfo[], ... ){
	int ret_value = 0;
	va_list nd_coordinate;
	unsigned int num_dimension = arrayinfo[0];
	int *sub_val_pt = arrayinfo + 1;
	int coor_arg[num_dimension];
	int lo_hi_list[num_dimension * 2];
	int i, j;

	//coordinate sub arg list:
	va_start(nd_coordinate, arrayinfo);
	for(i = 0; i < num_dimension; i++){
		coor_arg[i] = va_arg(nd_coordinate, int);
	}
	va_end(nd_coordinate);
	

	//low and high bound list:
	for(j = 0; j < (num_dimension * 2); j++, sub_val_pt++){
		lo_hi_list[j] = *sub_val_pt;
	}

	//valid value checking:
	int coor_sub = 0;
	int low = 0;
	if( num_dimension >= 1 && num_dimension <= 10 ){
		while( coor_sub < num_dimension ){
			if( coor_arg[coor_sub] >= lo_hi_list[low] && lo_hi_list[low + 1] >= lo_hi_list[low] ){
				;
			}
			else{
				ret_value = INVALID;
				break;
			}
			coor_sub++;
			low += 2;
		}
	}	
	else{
		ret_value = INVALID;
	}


	// offset calculation:
	int loc = coor_arg[0] - lo_hi_list[0];
	if( ret_value != INVALID ){
		for( int d = 1, low = 2; d < num_dimension; d++, low += 2 ){
			loc *= (lo_hi_list[low + 1] - lo_hi_list[low] + 1);
			loc += coor_arg[d] - lo_hi_list[low];		
		}
		ret_value = loc;
	}
	else{
		;
	}

	return ret_value;
}


int main(void){
	int arrayinfo[10] = {3, 4, 6, 1, 5, -3, 3};

	printf("%d\n", array_offset(arrayinfo, 4, 1, -3));
	printf("%d\n", array_offset(arrayinfo, 4, 1, -2));
	printf("%d\n", array_offset(arrayinfo, 4, 1, 3));
	printf("%d\n", array_offset(arrayinfo, 4, 2, -3));
	printf("%d\n", array_offset(arrayinfo, 5, 1, -3));
	printf("%d\n", array_offset(arrayinfo, 6, 3, 1));

	return 0;
}
