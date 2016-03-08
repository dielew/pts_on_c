#include <stdio.h>

#define BUF_SIZE 82
#define EXIT_SUCC 0
#define EXIT_FAIL 1


int main( int argc, char **argv )
{
	char buffer[BUF_SIZE];
	FILE *fd;
	int exit_status = EXIT_SUCC;

	if( argc != 2 ){
		printf("2nd argument(file_name) expected...\n");
		exit_status = EXIT_FAIL;
	}

	else{
		if( *++argv == NULL ){
			printf("Invalid 2nd argument...!\n");
			exit_status = EXIT_FAIL;
		}
		else{
			fd = fopen(*argv,"r");
			if( fd == NULL ){
				perror(*argv);
				exit_status = EXIT_FAIL;
			}
			else{
				while( fgets(buffer, 81, fd) != NULL ){
					puts(buffer);
				}
				if( fclose(fd) != 0 ){
					perror("fclose");	
					exit_status = EXIT_FAIL;
				}
				else{		
					exit_status = EXIT_SUCC;
				}
			}
		}
	}

	return exit_status;

}	
