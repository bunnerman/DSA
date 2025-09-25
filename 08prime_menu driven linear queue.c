#include <stdio.h>
#include <stdlib.h>

void qqeInsert(int *qqe, int *frnt, int *rr, int val)
{
    if (*frnt == -1)
        *frnt = 0;
    if (*rr < 10)
    {
        qqe[++*(rr)] = val;
        printf("Insertion Successful\n");
    }
    else
        printf("QUEUE OVERFLOW! Insertion Failed\n");
}

void qqeDelete(int *qqe, int *frnt, int *rr, int val)
{
    if (*frnt < *rr)
    {
        printf("Deletion Successful\n");
        (*frnt)++;
    }
    else if (*frnt == *rr)
    {
        printf("Only Element Deleted\n");
        (*frnt)++;    
    }
    else
        printf("QUEUE UNDERFLOW! Deletion Failed\n");
}

void qqeDisplay(int *qqe, int *frnt, int *rr)
{
    if (*frnt <= *rr)
        for (int i = *frnt; i <= *rr; i++)
            printf("%d ", qqe[i]);
    else
        printf("NO ELEMENTS INSERTED! Displaying Failed\n");
    printf("\nEmpty Spaces (-1 if none inserted yet)- %d\n", *frnt);
}

int main()
{
    int qqe[10];
    int *frnt = malloc(sizeof(int));
    *frnt = -1;
    int *rr = malloc(sizeof(int));
    *rr = -1;
    int val;
    int choice;

    printf("NOTE: MAX SIZE OF QUEUE IS 10\n");
    mainMenu:
    printf("\n<----------MENU---------->\n");
    printf("0. Exit\n");
    printf("1. Insert\n");
    printf("2. Delete\n");
    printf("3. Display\n");
    scanf("%d", &choice);

    switch(choice)
    {
        case 0:
            return 0;
        case 1:
            printf("Enter Value: ");
            scanf("%d", &val);
            qqeInsert(qqe, frnt, rr, val);
            break;
        case 2:
            qqeDelete(qqe, frnt, rr, val);
            break;
        case 3:
            qqeDisplay(qqe, frnt, rr);
            break;
        default:
            printf("INVALID CHOICE OF INTEGER! Choose Again\n");
            goto mainMenu;
            break;
    }
    goto mainMenu;

    return 0;
}