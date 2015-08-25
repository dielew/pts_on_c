#include <stdio.h>
#include <string.h>

char *deblank( char string[], char string_out[] ){
	int i = 0, j = 0, strl = strlen(string);
	while( i < strl && string[i] != '\0' ){
		while( string[i] != '\40' ){
			string_out[j] = string[i];
			i++;
			j++;
		}
		while( string[i] == '\40' ){
			i++;
		}			
		string_out[j] = '\40';
		j++;
	}
	return string_out;
}

int main(void){
	char string[1000];
	char string_out[1000];
	printf("Please input a string with blanks:");
	fgets(string, 100, stdin);
	printf("The output string is:%s", deblank(string, string_out));
	return 0;
}
