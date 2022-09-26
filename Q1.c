#include <stdio.h>
#include <stdlib.h>

struct node
{
	struct node *next;
    struct node *prev;
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
		new_node->next = NULL;
        new_node->prev = NULL;
	}
    return new_node;
}

void create() {

}

int main() {
    struct node *newNode = create_node(10);
    printf("%d", newNode->value);
}