#include <stdio.h>


int main(void){
	char ch[100][100];
	
	int i;
	for (i = 0; i<3; i++){
		scanf("%s", ch[i]);

			
	}
	for (i = 0; i<3; i++){
		printf("%d  %s\n", i + 1, ch[i]);
	}

	return 0;
}
