#include <stdio.h>
#include <ctype.h>


void cstat(char string[] ){

	char *str_pt;
	char ch;
	float num_total = 0;
	float num_ctrl = 0;
	float num_space = 0;
	float num_digit = 0;
	float num_lower = 0;
	float num_upper = 0;
	float num_punct = 0;
	float num_print = 0;
	float num_not_print;

	for( str_pt = string; *str_pt != '\0'; str_pt++ ){
		ch = *str_pt;

		if( isprint(ch) ){
			num_print += 1;
		}

		if( iscntrl(ch) ){
			num_ctrl += 1;
		}

		if( isspace(ch) ){
			num_space += 1;
		}

		if( isdigit(ch) ){
			num_digit += 1;
		}

		if( islower(ch) ){
			num_lower += 1;
		}

		if( isupper(ch) ){
			num_upper += 1;
		}

		if( ispunct(ch) ){
			num_punct += 1;
		}		
		
		num_total += 1;

	}

	printf("ctrl char: %f%%\nspace char: %f%%\ndigit char: %f%%\nlower char: %f%%\nupper char: %f%%\npunct char: %f%%\nnot-allowed-to-print char: %f%%\n", num_ctrl/num_total * 100, num_space/num_total * 100, num_digit/num_total * 100, num_lower/num_total * 100, num_upper/num_total * 100, num_punct/num_total * 100, (num_total - num_print)/num_total * 100);

}


int main(void){

	char string[1000];
	fgets(string, 999, stdin);
	//scanf("%s", string);
	cstat(string);
	
	return 0;
}
