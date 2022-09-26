#include <stdio.h>
#include <stdlib.h>

struct node
{
	struct node *pnextnode;
	int value;
};

struct node *phead = NULL;
struct node *pback = NULL;

// 1. Write a function void create() to create a doubly linked list, LList A, and
// display the LList A. 

struct node *create_node(int value) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));

    if (new_node != NULL)
	{
		new_node->value = value;
		new_node->pnextnode = NULL;
	}
    return new_node;
}

void create() {
    
}

int main() {
    return 0;
}