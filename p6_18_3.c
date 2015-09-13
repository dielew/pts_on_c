#include <stdio.h>


char *reverse_string(char *string){

	char *len_str = string;
	char *left_pt;  
	char *right_pt;
	char temp;
	int len = 0;
	
	while( *len_str != '\0' ){  
		len_str++;
		len++;
	}	//fetching length of the char array to calculate the very position of right pointer
	
	for( left_pt = string, right_pt = string + len - 1; right_pt - left_pt > 0; left_pt++, right_pt-- ){
		temp = *left_pt;
		*left_pt = *right_pt;
		*right_pt = temp; 
	}  // exchanging values derefered by left_pt(move to right) and right_pt(move to left) until two pointers move to the same position or just move across in the char array	 
	return string;
}


int main(void){
	char string[500];
	printf("Enter a string:");
	fgets(string, 499, stdin);
	printf("The reversed string is:%s\n", reverse_string(string));
	return 0;
}
