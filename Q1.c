#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    struct node *next;
    struct node *prev;
    int value;
} Node;

Node *phead = NULL;
Node *ptail = NULL;

// 1. Write a function void create() to create a doubly linked list, LList A, and
// display the LList A.

Node *create_node(int value)
{
    Node *new_node = (Node *)malloc(sizeof(Node));

    if (new_node != NULL)
    {
        new_node->value = value;
        new_node->next = NULL;
        new_node->prev = NULL;
    }
    return new_node;
}

// Insert new node at the front of the list
int insertfirst(int d)
{
    Node *pn = create_node(d);

    // Make sure node creation worked
    if (pn == NULL)
        return -1;

    // New node goes at the head of the list.
    pn->next = phead;
    phead = pn;
    // check if this was the very first node added - if so, we have to update the end pointer as well
    if (ptail == NULL)
        ptail = pn;
    return 0;
}

// Delete the first node in the list
int deletefirst(void)
{
    phead = phead->next;
    phead->prev = NULL;
}

// Insert new node at end of the list
int insertlast(int d)
{
    Node *pn = create_node(d);

    // make sure node creation worked
    if (pn == NULL)
        return -1;

    // New node goes at back of list. If the list is currently empty,
    // then both the head and back pointers need to be updated.
    if (ptail == NULL)
    {
        ptail = pn;
        phead = pn;
    }
    else
    {
        // there are already nodes in the list. Add the new one after
        // the existing last one.
        ptail->next = pn;
        // make the back pointer point to the new one
        ptail = pn;
    }
    return 0;
}

// Insert a given node into the list such that
// the list remains sorted in ascending order
void insertpos(Node node)
{
}

void create()
{
    insertfirst(50);
    insertfirst(20);
    insertfirst(10);
    insertfirst(5);
    deletefirst();
}

void display(void)
{
    Node *temp; // temporary pointer used to traverse list
    int count;  // count how many printed on one line
    if (phead == NULL)
    {
        printf("<EMPTY LIST>\n");
        return;
    }
    // List has some real data to be printed. We will point temp at
    // the first node in the list, print the data, and if there is
    // more list, move temp to point to the next node. We'll keep
    // doing this until there are no more nodes to look at.
    temp = phead;
    count = 0; // 0 on line so far
    while (temp != NULL)
    {
        printf("%4d", temp->value);
        if (temp->next != NULL)
        {
            printf("->");
            count++; // one more on the line
            // check if getting close to right edge - if so, move to start of
            // next line and reset count.
            if (count > 12)
            {
                putchar('\n');
                count = 0;
            }
        }
        else
        {
            putchar('\n');
        }
        temp = temp->next;
    }
    return;
}

int main()
{
    create();
    display();
}