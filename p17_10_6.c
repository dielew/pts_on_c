#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


#define QUEUE_SIZE 100
#define ARRAY_SIZE (QUEUE_SIZE + 1)
#define Q_T Node*


typedef struct NODE_Btree{
	struct NODE_Btree* left;
	struct NODE_Btree* right;
	int value;
}Node;


static Q_T queue[ARRAY_SIZE];
static size_t front = 1;
static size_t rear = 0;


int is_empty( void )
{
	return (rear + 1) % ARRAY_SIZE == front;
}

int is_full( void )
{
	return (rear + 2) % ARRAY_SIZE == front;
}

void insert( Q_T node )
{
	assert(!is_full());
	rear = (rear + 1) % ARRAY_SIZE;
	queue[rear] = node;
}

void delete( void )
{
	assert(!is_empty());
	front = (front + 1) % ARRAY_SIZE;
}

Q_T first( void )
{
	assert(!is_empty());
	return queue[front];
} 




void print_node_value(Q_T node)
{
	printf("%d \n", node->value);
}



void level_traverse( Q_T root, void (*callback)(Q_T) )
{
	Q_T temp_node_ptr;
	insert(root);
	while(!is_empty()){
		temp_node_ptr = first();
		delete();
		callback(temp_node_ptr);
		if( temp_node_ptr->left != NULL ){
			insert(temp_node_ptr->left);
		}
		if( temp_node_ptr->right != NULL ){
			insert(temp_node_ptr->right);
		}
	}
}


Q_T init_instance( void )
{
	Q_T root = (Q_T)malloc(sizeof(Node));
	root->value = 1;

	Q_T first_left = (Q_T)malloc(sizeof(Node));
	first_left->value = 2;
	root->left = first_left;
	Q_T first_right = (Q_T)malloc(sizeof(Node));
	first_right->value = 3;
	root->right = first_right;

	Q_T second_left = (Q_T)malloc(sizeof(Node));
	second_left->value = 4;
	first_left->left = second_left;
	first_left->right = NULL;

	first_right->left = NULL;
	first_right->right = NULL;
	
	second_left->left = NULL;
	second_left->right = NULL;

	return root;
}



int main( void )
{
	Q_T root = init_instance();
	level_traverse(root, print_node_value);
	return 0;
}
