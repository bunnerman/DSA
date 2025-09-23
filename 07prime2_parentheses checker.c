#include <stdio.h>
#include <string.h>

int main() 
{
    int stk = 0;
    char string[4096]; // big limit
    printf("Enter a string to check for parentheses-\n\n");
    fgets(string, sizeof(string), stdin);
    char *ch = string;
    
    while (*ch != '\0') // end of string
    {
        if (*ch == '(')
            stk++;
        else if (*ch == ')') 
            stk--;
        if (stk < 0)
        {
            printf("Wrong Bracket Order OR Excess ')' Brackets\n");
            return 0;
        }
        ch++;
    }
    
    if (stk > 0)
        printf("Excess '(' Brackets\n");
    else
        printf("No parentheses anomalies detected\n");
    
    return 0;
}
