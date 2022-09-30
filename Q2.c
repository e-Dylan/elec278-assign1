#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct node
{
    struct node *next;
    char value;
} Node;

Node *top = NULL;

void push(char value)
{
    Node *new_top = (Node *)malloc(sizeof(Node));
    new_top->value = value;
    new_top->next = top;
    top = new_top;
}

char pop(void)
{
    if (top == NULL)
    {
        printf("Stack is empty, cannot pop.");
    }
    else
    {
        char poppedChar = top->value;
        top = top->next;
        return poppedChar;
    }
}

void print_stack()
{
    if (top == NULL)
    {
        printf("EMPTY STACK.");
        return;
    }
    Node *tempNode = top;
    while (tempNode != NULL)
    {
        printf("%c -> ", tempNode->value);
        tempNode = tempNode->next;
    }
}

// Function to check if two passed characters are matched such that they are 'balanced'.
// Returns true if c2 is balanced with c1.
bool does_match(char c1, char c2)
{
    switch (c1)
    {
    case '(':
        if (c2 == ')')
            return true;
    case '{':
        if (c2 == '}')
            return true;
    case '[':
        if (c2 == ']')
            return true;
    default:
        return false;
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
        if (str[i] == '}' || str[i] == ']' || str[i] == ')')
        {
            if (top == NULL)
            {
                // found an end bracket and stack is empty, therefore no
                // pair open bracket exists. Expression must be unbalanced.
                return false;
            }
            else
            {
                // Closed bracket, pop from the top of the stack and and compare
                char poppedChar = pop();

                // Found a pair of brackets that don't match, must be unbalanced
                if (!does_match(poppedChar, str[i]))
                {
                    return false;
                }
            }
        }
    }

    if (top == NULL)
    {
        // Expression was balanced, stack is left empty by end
        return true;
    }
    else
    {
        // Expression was unbalanced, stack is not empty by end
        return false;
    }
}

int main(void)
{
    char to_balance[50] = "{(})";
    printf("%d", is_balanced(to_balance));
    return 0;
}