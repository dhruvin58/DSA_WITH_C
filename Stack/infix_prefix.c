#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Stack.c"
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
    }
}
int is_operator(char ch) 
{
    return ch == '+' || ch == '*' || ch == '/' || ch == '-' || ch == '^';
}
int is_operand(char ch)
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9');
}
void reverse(char *str)
{
    int n = strlen(str);

    for (int i = 0; i < n/2; i++)
    {
        char temp = str[i];
        str[i] = str[n-1-i];
        str[n-i-1] = temp;
    }
    
}
void reverse_parenthesis(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if(str[i] == '(')
            str[i] = ')';
        else if (str[i] == ')')
            str[i] = '(';
    }
}
void infix_to_postfix(char *infix, char *postfix)
{
    STACK* stack = CREATE(strlen(infix));
    int k=0;

    for (int i = 0; infix[i] != '\0'; i++)
    {
        char ch = infix[i];

        if(is_operand(ch))
        {
            postfix[k++] = ch;
        }
        else if(ch == '(')
        {
            push(stack,ch);
        }
        else if(ch == ')')
        {
            while (!IS_EMPTY(stack) && peek(stack) != '(')
            {
                postfix[k++] = pop(stack);
            }
            pop(stack);
        }
        else if(is_operator(ch))
        {
            while (!IS_EMPTY(stack) && precedance(peek(stack)) >= precedance(ch))
            {
                postfix[k++] = pop(stack);
            }
            push(stack,ch);
        }
    }
    while (!IS_EMPTY(stack))
    {
        postfix[k++] = pop(stack);
    }
    postfix[k] = '\0';
    destroy(stack);
}
void infix_to_prefix(char* infix, char* prefix)
{
    char reversed[100], postfix[100];
    strcpy(reversed,infix);
    reverse(reversed);
    reverse_parenthesis(reversed);
    infix_to_postfix(reversed,postfix);
    reverse(postfix);
    strcpy(prefix,postfix);
}
int main()
{
    char infix[100], prefix[100];

    printf("Enter Your infix Statement : ");
    scanf("%s", infix);

    infix_to_prefix(infix, prefix);

    printf("Prefix Expression is : %s ", prefix);

    return 0;
}