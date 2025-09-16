#include <stdio.h>
#include <stdlib.h>

void stkPush(int *stk, int *top, int val)
{
    if (*top + 1 > 9)
    {
        printf("STACK OVERFLOW DETECTED! Push Fail\n");
        return; 
    }
    else
        stk[++(*top)] = val;
    printf("Push Successful\n");
    return;
}

void stkPop(int *stk, int *top)
{
    if (*top < 0)
    {
        printf("NO ELEMENTS INSERTED! Pop Fail\n");
        return;
    }
    else
        (*top)--;
    printf("Pop Successful\n");
    return;
}

void stkPeek(int *stk, int *top)
{
    if (*top < 0)
    {
        printf("NO ELEMENTS INSERTED! Peek Fail\n");
        return;
    }
    else
        printf("Peek: %d\n", stk[*top]);
    return;
}

int main()
{
    int stk[10];
    int *top;
    *top = -1;
    int val;
    int ch;

    printf("NOTE: MAX SIZE OF STACK IS 10\n");
    mainMenu:
    printf("<----------MENU---------->\n");
    printf("0. Exit\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Peek\n");
    printf("4. Size\n");
    scanf("%d", &ch);

    switch(ch)
    {
        case 0:
            return 0;
        case 1:
            printf("Enter Value: ");
            scanf("%d", &val);
            stkPush(stk, top, val);
            break;
        case 2:
            stkPop(stk, top);
            break;
        case 3:
            stkPeek(stk, top);
            break;
        case 4:
            printf("Size is %d\n", *top + 1);
            break;
        default:
            printf("INVALID CHOICE OF INTEGER! Choose Again\n");
            goto mainMenu;
            break;
    }
    goto mainMenu;

    return 0;
}
