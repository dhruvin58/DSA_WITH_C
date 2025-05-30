#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "Stack.c"
int is_operator(char ch)
{
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}
int is_operand(char ch)
{
    return ch >= '0' && ch <= '9';
}
int evaluation_prefix(char *prefix)
{
    int n = strlen(prefix);
    STACK *stack = CREATE(n + 10);


    int result = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        char ch = prefix[i];

        if (is_operand(ch))
        {

            push(stack, ch - '0');
        }
        else if (is_operator(ch))
        {
            int operand1 = pop(stack);
            int operand2 = pop(stack);

            if (ch == '+')
                result = operand2 + operand1;
            else if (ch == '-')
            {
                result = operand2 - operand1;
            }
            else if (ch == '*')
            {
                result = operand2 * operand1;
            }
            else if (ch == '/')
            {
                result = operand2 / operand1;
            }
            else if (ch == '^')
            {
                result = pow(operand2, operand1);
            }
            push(stack, result);
        }
    }
    result = pop(stack);
    destroy(stack);
    return result;
}
// int evaluation_prefix(char *prefix)
// {
//     int n = strlen(prefix);
//     STACK *stack = CREATE(n + 10);

//     if (stack == NULL) {
//         printf("Stack creation failed!\n");
//         return -1;
//     }

//     int result = 0;
//     for (int i = n - 1; i >= 0; i--)
//     {
//         char ch = prefix[i];
//         // printf("Processing: %c\n", ch);

//         if (is_operand(ch))
//         {
//             // printf("Pushing operand: %d\n", ch - '0');
//             push(stack, ch - '0');
//         }
//         else if (is_operator(ch))
//         {
//             int operand1 = pop(stack);
//             int operand2 = pop(stack);
//             // printf("Popped: %d, %d for operator %c\n", operand2, operand1, ch);

//             if (ch == '+')
//                 result = operand2 + operand1;
//             else if (ch == '-')
//                 result = operand2 - operand1;
//             else if (ch == '*')
//                 result = operand2 * operand1;
//             else if (ch == '/')
//                 result = operand2 / operand1;
//             else if (ch == '^')
//                 result = pow(operand2, operand1);

//             // printf("Result after %c: %d\n", ch, result);
//             push(stack, result);
//         }
//     }

//     result = pop(stack);
//     destroy(stack);
//     return result;
// }

int main()
{

    char prefix[100];
    printf("Enter prefix expression (e.g. +23): ");
    scanf("%s", prefix);

    int result = evaluation_prefix(prefix);
    printf("Evaluated result: %d\n", result);
    return 0;
}