#include <stdio.h>
#include <stdarg.h>

//void print_integer();
//void print_float();

void liu_printf(char format[], ... ){
	va_list var_print_arg;
	char *format_str_pt;
	char format_str;
	char *str_arg_pt;

	va_start(var_print_arg, format);
	format_str_pt = format;

	while( *format_str_pt != '\0' ){
		if( *format_str_pt == '%' ){
			format_str_pt++;
			format_str = *format_str_pt;
			break;
		}
		else{
			;
		}
		format_str_pt++;
	}

	switch( format_str ){
	case 'd':
			//print_integer();
			break;
	
	case 'f':
			//print_float();
			break;
	
	case 'c':
			
			putchar(va_arg(var_print_arg, int));
			va_end(var_print_arg);
			break;
	
	case 's':
			str_arg_pt = va_arg(var_print_arg, char *);
			while( *str_arg_pt != '\0' ){
				putchar(*str_arg_pt);
				str_arg_pt++;
			}
			va_end(var_print_arg);
			break;
	}
}


int main(void){

	//instance #1
	char char_arg = 'o';
	liu_printf("%c", char_arg);
	printf("\n");

	//instance #2
	char str_arg[] = "Hello, World!";
	liu_printf("%s", str_arg);
	printf("\n");

	return 0;
}
