#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Stack.c"
int precedance(char ch);
int is_operator(char ch);
int is_operand(char ch);
void infix_to_postfix(char *infix, char *postfix);
int main()
{
    char infix[100], postfix[100];

    printf("Enter Your Infix Statement..\n");
    scanf("%s", infix);

    infix_to_postfix(infix, postfix);

    printf("Your Relvant Postfix expression : %s", postfix);

    return 0;
}
int precedance(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    default:
        return 0;
    }
}
int is_operator(char ch)
{
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}
int is_operand(char ch)
{
    return (ch >= 'A' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9');
}
void infix_to_postfix(char *infix, char *postfix)
{
    STACK* stack = CREATE(strlen(infix));

    int k=0;

    for (int i = 0; infix[i] != '\0'; i++)
    {
        if(is_operand(infix[i]))
        {
            postfix[k++] = infix[i];
        }
        else if (infix[i] == '(')
        {
            push(stack,infix[i]);
        }
        else if(infix[i] == ')')
        {
            while (!IS_EMPTY(stack) && peek(stack) != '(' )
            {
                postfix[k++] = pop(stack);
            }
            pop(stack);
        }
        else if(is_operator(infix[i]))
        {
            while (!IS_EMPTY(stack) && precedance(infix[i]) <=  precedance(peek(stack)))
            {
                postfix[k++] = pop(stack);
            }
            push(stack,infix[i]);
        }
    }
    while (!IS_EMPTY(stack))
    {
        postfix[k++] = pop(stack);
    }
    
    postfix[k] = '\0';

    destroy(stack);
}