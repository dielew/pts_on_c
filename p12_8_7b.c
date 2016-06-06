#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "conclist_Node1.h"


#define MAX_LINE_LEN 1024
#define MAX_WORD_LEN 64



extern Node *prime_ll_init(void);
extern int word_count(char *, Node *); 



char *word_wash( char *origin_word )
{
	char *oriw_ptr = origin_word;
	char *clearw_ptr = origin_word;
	char *retw_ptr = origin_word;

	if( *oriw_ptr != '"' && *oriw_ptr != '\'' ){

		for( ; *oriw_ptr != '\0' && ((isalpha(*oriw_ptr) || *oriw_ptr == '-' )); oriw_ptr++, clearw_ptr++  ){
			*clearw_ptr = *oriw_ptr;
		}
	}

	else{
		for( oriw_ptr++; *oriw_ptr != '\0' && ((isalpha(*oriw_ptr) || *oriw_ptr == '-' )); oriw_ptr++, clearw_ptr++  ){
			*clearw_ptr = *oriw_ptr;
		}

	}

	*clearw_ptr = '\0';

	return retw_ptr; 
}


unsigned words_counter( void )
{
	static unsigned words_counter = 0;
	words_counter += 1;
	return words_counter;
}


void word_split( char *buffer_arg, Node *start_ptr )
{
	char word[MAX_WORD_LEN];
	char *word_ptr;
	char *buffer_ptr = buffer_arg;
	
	if( !(*buffer_arg == '\n') ){
		for( ; *buffer_ptr != '\n' && *buffer_ptr != '\0' && *buffer_ptr != EOF; buffer_ptr++ ){
			for( word_ptr = word; *buffer_ptr != ' ' && *buffer_ptr != '\n'; buffer_ptr++, word_ptr++ ){
				*word_ptr = *buffer_ptr;
			}	
			*word_ptr = '\0';
			words_counter();
//			printf("%s\n", word_wash(word));
			word_count(word_wash(word), start_ptr);
		}
	}
	else{
		;	
	}
}


void data_index_print( Node *start_node_ptr )
{
	Node *start = start_node_ptr;

	for( ; start != NULL; start = start->link ){
		for( start = start->ext; start != NULL; start = start->ext ){
			printf("word '%s' freq: %u\n", start->the_word, start->times);
		}
	}	
}


void data_stream_test( FILE *input )
{
	
	char buffer[MAX_LINE_LEN];
	char w_buffer[MAX_WORD_LEN];
	unsigned total_word_num;
	Node *start_ptr;

	start_ptr = prime_ll_init();

	while( fgets(buffer, MAX_LINE_LEN, input ) != NULL ){
		word_split(buffer, start_ptr);		
	}
	
	total_word_num = words_counter() - 1;
//	data_index_print(start_ptr);	
	printf("Number of total words in the text file: %u\n", total_word_num);
	
}





int main( int argc, char **argv )
{

	FILE *input;
	int exit_status = EXIT_SUCCESS;
	Node *start_ptr;

	if( *++argv != NULL ){
		input = fopen(*argv, "r");
		if( input == NULL ){
			perror(*argv);
			exit_status = EXIT_FAILURE;	

		}

		else{
			data_stream_test(input);
		}

		if( fclose(input) != 0 ){
			perror("fclose");
			exit(EXIT_FAILURE);
		}
		else{
			;
		}
	}

	else{
		printf("NO such file(s) or directory\n");
	}


	return exit_status;

}
