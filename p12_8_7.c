#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "conclist_Node1.h"



Node *prime_ll_init( void )
{
	char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
	char *init_letter_ptr;

	Node *start;
	Node *next_node;
	Node *pre_node;
	Node *new_node = malloc(sizeof(Node));
	start = new_node;

	for( init_letter_ptr = alphabet; *init_letter_ptr != '\0'; init_letter_ptr++ ){
		new_node->letter = *init_letter_ptr;
		new_node->ext = NULL;
		next_node = malloc(sizeof(Node));
		new_node->link = next_node;
		pre_node = new_node;
		new_node = next_node;
	}
	pre_node->link = NULL;
//	n_node->letter = '\0';

	return start;
}



int word_count( char *word_argm, Node *start_argm)
{

	char *word_ptr = word_argm;
	char first_letter = *word_argm;
	Node *node_ptr = start_argm;
	Node *node_ext;
	Node *node_pre;
	
	for( ; first_letter != ((node_ptr->letter) - 32) && first_letter != (node_ptr->letter) && node_ptr->letter != EOF; node_ptr = node_ptr->link ){
	}	
	
	if( (node_ext = node_ptr->ext) == NULL ){

	node_ext = malloc(sizeof(Node));
	if( node_ext == NULL ){
		printf("not any mem to be allocated!");
		return -1;
	}	

	node_ext->the_word = malloc(sizeof(strlen(word_argm) + 2));
	strcpy(node_ext->the_word, word_ptr);
	node_ext->times = 1;
	node_ext->ext = NULL;

	node_ptr->ext = node_ext;

	printf("word: %s   times: %u\n", node_ext->the_word, node_ext->times);

	}

	else{
	//printf("first letter = %c\n", node_ptr->letter);
	for( node_ext = node_ptr->ext;  node_ext != NULL; node_pre = node_ext, node_ext = node_ext->ext ){
		if( strcmp(word_argm, node_ext->the_word) == 0 ){
//		printf("if matching? %d\n", (strcmp(word_ptr, node_ext->the_word) == 0 ));
			node_ext->times += 1;
			printf("word: %s   times: %u\n", node_ext->the_word, node_ext->times);
			return 1;
		}
		else{
		//printf("if not matching? %d\n", (strcmp(word_ptr, node_ext->the_word) != 0 ));
			;
		}

	}


	node_ext = malloc(sizeof(Node));
	if( node_ext == NULL ){
		printf("not any mem to be allocated!");
		return -1;
	}
	node_ext->the_word = malloc(sizeof(strlen(word_argm) + 2));
	strcpy(node_ext->the_word, word_ptr);
	node_ext->times = 1;
	node_ext->ext = NULL;
//	node_ext = node_new;
	printf("word: %s   times: %u\n", node_ext->the_word, node_ext->times);

	node_pre->ext = node_ext;

	}
	return 1;

}




/*
int main( void )
{
	Node *start_ptr;
	unsigned result;
	char ins[60];
	char ins1[60];
	char ins2[60];
	char ins3[60];

	scanf("%s", ins);
	scanf("%s", ins1);
	scanf("%s", ins2);
	scanf("%s", ins3);
	
	start_ptr = prime_ll_init();


	if( word_count(ins, start_ptr) ){
		printf("Insertion done!\n");
	}
	if( word_count(ins1, start_ptr) ){
		printf("Insertion done!\n");
	}
	if( word_count(ins2, start_ptr) ){
		printf("Insertion done!\n");
	}
	if( word_count(ins3, start_ptr) ){
		printf("Insertion done!\n");
	}

	printf("%u\n", word_posi_t1(ins, start_ptr));

	return 0;
	
}
*/
