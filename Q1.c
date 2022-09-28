#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    struct node *next;
    struct node *prev;
    int value;
} Node;

Node *create_node(int value);
void deletefirst(void);
void insertfirst(int d);
void insertlast(int d);
void insertpos(Node *node, int pos);
void merge(Node *phead1, Node *phead2);
void create();
void display(Node *head);

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
void insertfirst(int d)
{
    Node *pn = create_node(d);

    // Make sure node creation worked
    if (pn == NULL)
        return;

    // New node goes at the head of the list.
    pn->next = phead;
    phead = pn;
    // check if this was the very first node added - if so, we have to update the end pointer as well
    if (ptail == NULL)
        ptail = pn;
}

// Delete the first node in the list
void deletefirst(void)
{
    phead = phead->next;
    phead->prev = NULL;
}

// Insert new node at end of the list
void insertlast(int d)
{
    Node *pn = create_node(d);

    // make sure node creation worked
    if (pn == NULL)
        return;

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
    return;
}

// Insert a given node into the list such that
// the list remains sorted in ascending order
void insertpos(Node *node, int pos)
{
    Node *temp = phead;
    // Traverse list up to insert position
    for (int i = 0; i < pos - 1; i++)
    {
        temp = temp->next;
    }
    if (temp != NULL)
    {
        // Found position, insert the new node
        node->next = temp->next;
        temp->next = node;
    }
}

// Merge two linked lists into a new list in ascending data order
void merge(Node *phead1, Node *phead2)
{
    Node *temp1 = phead1;
    Node *temp2 = phead2;

    // Go until we run out of nodes to merge from list 2
    while (temp2 != NULL)
    {
        // Traverse list 1 to find where to insert nodes
        while (temp1->next != NULL)
        {
            if (temp2->value >= temp1->value && temp2->value <= temp1->next->value)
            {
                Node *insertnode = create_node(temp2->value);
                insertnode->next = temp1->next;
                temp1->next = insertnode;

                // increment list2 to it's next node for next check
                temp2 = temp2->next;
                break;
            }
            display(phead1);
            temp1 = temp1->next;
        }
    }
}

void create()
{
    insertfirst(50);
    insertfirst(20);
    insertfirst(10);
    insertfirst(5);
    deletefirst();
    Node *new_node = create_node(30);
    insertpos(new_node, 2);

    Node *new_head = create_node(24);
    new_head->next = create_node(25);
    new_head->next->next = create_node(36);

    merge(phead, new_head);
}

// Print any passed linked list
void display(Node *head)
{
    Node *temp; // temporary pointer used to traverse list
    int count;  // count how many printed on one line
    if (head == NULL)
    {
        printf("<EMPTY LIST>\n");
        return;
    }
    // List has some real data to be printed. We will point temp at
    // the first node in the list, print the data, and if there is
    // more list, move temp to point to the next node. We'll keep
    // doing this until there are no more nodes to look at.
    temp = head;
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
    display(phead);
}