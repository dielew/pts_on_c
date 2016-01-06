#include <stdio.h>
#include <stdlib.h>
#include "Node_p11.h"



void prototype_linkedlist( Node *root_pointer ){

	Node *previous_ptr = root_pointer;		//initializing 'previous_ptr' as root(head) pointer. 
	Node *new_alloc_ptr;
	Node *last_node_alloc_ptr;
	Node *to_free_new_alloc;
	Node *to_free_last_alloc;
	static unsigned int allocated_in_heap_size = 0;


	while( previous_ptr->link != NULL ){
		
		new_alloc_ptr = malloc(sizeof(Node));
		to_free_new_alloc = new_alloc_ptr;
		allocated_in_heap_size += sizeof(Node);
		printf("+: In heap we had allocated(+) or freed(-) %u byte(s)...\n", allocated_in_heap_size);

		if( new_alloc_ptr != NULL ){	
			new_alloc_ptr->value = previous_ptr->value;
			new_alloc_ptr->link = previous_ptr->link;
			previous_ptr = new_alloc_ptr->link;
			printf("The value of this node is: %d.\n", new_alloc_ptr->value);

			if( previous_ptr->link == NULL ){
				last_node_alloc_ptr = malloc(sizeof(Node));
				to_free_last_alloc = last_node_alloc_ptr;
				allocated_in_heap_size += sizeof(Node);
				printf("+: In heap we had allocated(+) or freed(-) %u byte(s)...\n", allocated_in_heap_size);

				if( last_node_alloc_ptr != NULL ){
					last_node_alloc_ptr->value = previous_ptr->value;
					last_node_alloc_ptr->link = previous_ptr->link;
				}
				else{
					printf("Out of Memory!");
					exit(1);		
				}	
				printf("The value of last node is: %d.\n", last_node_alloc_ptr->value);
				free(to_free_last_alloc);
				allocated_in_heap_size -= sizeof(Node);
				printf("-: In heap we had allocated(+) or freed(-) %u byte(s)...\n", allocated_in_heap_size);
			}

			else{
				;
			}
		}

		else{
			printf("Out of Memory!");
			exit(1);		
		}

		free(to_free_new_alloc);
		allocated_in_heap_size -= sizeof(Node);
		printf("-: In heap we had allocated(+) or freed(-) %u byte(s)...\n", allocated_in_heap_size);

	}
	
}


int main( void ){

	Node node0;
	Node node1;
	Node node2;
	Node node3;

	node0.value = 5;
	node0.link = &node1;

	node1.value = 10;
	node1.link = &node2;
	
	node2.value = 15;
	node2.link = &node3;

	node3.value = 20;
	node3.link = NULL;

	Node *root_pointer = &node0;

	prototype_linkedlist(root_pointer);

	return 0;
}

