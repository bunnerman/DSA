#include <stdio.h>
#include <stdlib.h>

void queueInsert(int val);
void queueDelete();
void queueDisplay();

// Global variables and MACRO for convenience
#define MAXSIZE 10
int queue[MAXSIZE];
int front = -1;
int rear = -1;

int main()
{
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
            queueInsert(val);
            break;
        case 2:
            queueDelete();
            break;
        case 3:
            queueDisplay();
            break;
        default:
            printf("INVALID CHOICE OF INTEGER! Choose Again\n");
            goto mainMenu;
            break;
    }
    goto mainMenu;

    return 0;
}

void queueInsert(int val)
{
    if (rear == front - 1 || (front == 0 && rear == MAXSIZE - 1))
    {
        printf("Insertion Failed, QUEUE OVERFLOW\n");
        printf("Front - %d\n", front);
        printf("Rear - %d\n", rear);
    }
    else if (front == -1)
    {
        front = 0;
        queue[++rear] = val;
        printf("Insertion Sucessful, First element inserted\n");
        printf("Front - %d\n", front);
        printf("Rear - %d\n", rear);
    }
    else if (rear == MAXSIZE - 1 && front > 0)
    {
        rear = -1;
        queue[++rear] = val;
        printf("Insertion Successful, Looping rear to beginning\n");
        printf("Front - %d\n", front);
        printf("Rear - %d\n", rear);
    }
    else if (rear == front - 2 || (rear == MAXSIZE - 2 && front == 0))
    {
        queue[++rear] = val;
        printf("Insertion Successful, next insert will overflow\n");
        printf("Front - %d\n", front);
        printf("Rear - %d\n", rear);
    }
    else
    {
        queue[++rear] = val;
        printf("Insertion Sucessful\n");
        printf("Front - %d\n", front);
        printf("Rear - %d\n", rear);
    }
}

void queueDelete()
{
    if (front == -1)
    {
        printf("Deletion Failed, QUEUE UNDERFLOW\n");
        printf("Front - %d\n", front);
        printf("Rear - %d\n", rear);
    }
    else if (front == rear)
    {
        front = -1;
        rear = -1;
        printf("Deletion Successful, no element remains, resetting queue\n");
    }
    else if (front == MAXSIZE - 1 && rear > 0) 
    {
        front = 0;
        printf("Deletion Successful, Looping front to beginning\n");
        printf("Front - %d\n", front);
        printf("Rear - %d\n", rear);
    }
    else if (front == rear - 1 || (front == MAXSIZE - 2 && rear == 0))
    {
        front++;
        printf("Deletion Successful, only one element remains\n");
    }
    else
    {
        printf("Deletion Successful\n");
        printf("Front - %d\n", ++front);
        printf("Rear - %d\n", rear);
    }
}
void queueDisplay()
{
    int i = front;
    if (front <= rear)
        while (i <= rear)
            printf("%d ", queue[i++]);
    else if (front > rear)
    {
        while (i < MAXSIZE)
            printf("%d ", queue[i++]);
        i = 0;
        while (i <= rear)
            printf("%d ", queue[i++]);
    }    
    printf("\nFront - %d\n", front);
    printf("Rear - %d\n", rear);
}
