#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


#define Q_TYPE int



typedef struct NODE_QUEUE{
	struct NODE_QUEUE* link;
	Q_TYPE value;
}NodeQ;



int is_empty( NodeQ* front )
{
	return ( (front->link)->link == NULL );
}




void insert( Q_TYPE value, NodeQ** rear_ptr )
{
	NodeQ* new_node = (NodeQ*)malloc(sizeof(NodeQ));
	assert( new_node != NULL ); 

	(*rear_ptr)->value = value;
	(*rear_ptr)->link = new_node;
	new_node->link = NULL;
	*rear_ptr = new_node;
}


void delete( NodeQ** front_ptr )
{
	assert(!is_empty(*front_ptr));
	
	NodeQ* temp = *front_ptr;

	*front_ptr = (*front_ptr)->link;
	
	free(temp);
}



Q_TYPE first( NodeQ* front )
{
	assert(!is_empty(front));
	return (front->value);
}






int main( void )
{
	NodeQ** front_ptr;
	NodeQ** rear_ptr;
	NodeQ* new_node;
	NodeQ* pre_node;
	NodeQ* test;
	Q_TYPE i;


	pre_node = (NodeQ*)malloc(sizeof(NodeQ));
	assert(pre_node != NULL);
	*front_ptr = pre_node;


	for( i = 0; i < 10; i++ ){
		pre_node->value = i;
		new_node = (NodeQ*)malloc(sizeof(NodeQ));
		assert(new_node != NULL);
		pre_node->link = new_node;
		pre_node = new_node;
	}
	pre_node->link = NULL;
	rear_ptr = &pre_node;

	insert(88, rear_ptr);
	insert(8888, rear_ptr);
	insert(88888, rear_ptr);
	insert(888888, rear_ptr);
	

	delete(front_ptr);
	delete(front_ptr);
	delete(front_ptr);
	delete(front_ptr);
	delete(front_ptr);
	delete(front_ptr);
	delete(front_ptr);
	delete(front_ptr);
	delete(front_ptr);
	delete(front_ptr);
	delete(front_ptr);
	delete(front_ptr);
	delete(front_ptr);
	


	insert(99999, rear_ptr);
	insert(999999, rear_ptr);
	insert(9999999, rear_ptr);
	insert(99999999, rear_ptr);

	while( (test = ((*front_ptr)->link)->link) != NULL ){
		printf("%d\n", ((*front_ptr)->link)->value);
		*front_ptr = (*front_ptr)->link;
	}





	return 0;

}
