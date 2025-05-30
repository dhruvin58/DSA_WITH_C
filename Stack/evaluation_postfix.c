#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include"Stack.c"
int is_operator(char ch)
{
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}
int is_operand(char ch)
{
    return ch >= '0' && ch <= '9';
}
int evaluation_postfix(char *postfix)
{
    STACK* stack = CREATE(strlen(postfix));

    int i=0;
    int result = 0;
    while(postfix[i] != '\0')
    {
        int ch = postfix[i];

        if(is_operand(ch))
        {
            
            push(stack,ch-'0');
        }
        else if(is_operator(ch))
        {
            int operand1 = pop(stack);
            int operand2 = pop(stack);


            if(ch == '+')
                result = operand2 + operand1;
            else if(ch == '-')
            {
                result = operand2 - operand1;
            }
            else if(ch == '*')
            {
                result = operand2 * operand1;
            }
            else if(ch == '/')
            {
                result = operand2 / operand1;
            }
            else if(ch == '^')
            {
                result = pow(operand2,operand1);
            }
            push(stack,result);
        }
        i++;
    }
    result = pop(stack);
    destroy(stack);
    return result;
    
}
int main()
{

    char postfix[100];
    printf("Enter postfix expression (e.g. 23+): ");
    scanf("%s", postfix);

    int result = evaluation_postfix(postfix);
    printf("Evaluated result: %d\n", result);
    return 0;
}