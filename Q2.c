#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// ref:
// https://www.geeksforgeeks.org/check-for-balanced-parentheses-in-an-expression/

typedef struct node
{
    struct node *next;
    char value;
} Node;

Node *head = NULL;

Node *push(int value)
{
    Node *newHead = malloc(sizeof(Node));
    newHead->value = value;
    newHead->next = head;
    head = newHead;
}

char pop(void)
{
}

void print_stack()
{
    Node *tempNode = head;
    while (tempNode != NULL)
    {
        printf("%c -> ", tempNode->value);
        tempNode = tempNode->next;
    }
}

// Returns whether or not a given string is balanced
bool is_balanced(char str[])
{
    // Traverse the string
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == '{' || str[i] == '[' || str[i] == '(')
        {
            // Open bracket, push to the stack
            push(str[i]);
        }
        else if (str[i] == '}' || str[i] == ']' || str[i] == ')')
        {
            // Closed bracket, pop from the top of the stack and and compare
            char poppedChar = pop();
        }
    }
}

int main()
{
    char to_balance[100] = "{}{}[]]]";
    printf(is_balanced(to_balance) ? "true" : "false");
    return 0;
}