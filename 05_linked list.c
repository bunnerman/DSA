#include <stdio.h>
#include <stdlib.h>


struct node
{
    int data;
    struct node *nxt;
};


void newNodeTail(int val, struct node **head)
{
    if (*head == NULL)
    {
        *head = malloc(sizeof(struct node)); 
        (*head)->data = val;
        (*head)->nxt = NULL;
    }
    else
    {
        struct node *ptr = *head;
        while (ptr->nxt != NULL)
        {
            ptr = ptr->nxt;
        }
        ptr->nxt = malloc(sizeof(struct node));
        ptr = ptr->nxt;
		
        ptr->data = val;
        ptr->nxt = NULL;
    }
}

void newNodeHead(int val, struct node **head)
{
    if (*head == NULL)
    {
        *head = malloc(sizeof(struct node));
        (*head)->data = val;
        (*head)->nxt = NULL;
    }
    else
    {
        struct node *ptr;
        ptr = malloc(sizeof(struct node));
        ptr->data = val;
        ptr->nxt = *head;
        *head = ptr;
    }
}

void newNodeChoose(int val, struct node **head, int index, int length)
{
    if (*head == NULL)
    {
        (*head) = malloc(sizeof(struct node));
        (*head)->data = val;
        (*head)->nxt = NULL;
    }
    else
    {
        struct node *ptr = *head;
        int i = 0;
        while (i < index && i < length && ptr != NULL)
        {
            ptr = ptr->nxt;
            i++;
        }
        if (ptr != NULL)
            ptr->data = val;
        else
            printf("\nINDEX INVALID\n\n");
    }
}

void displayList(struct node* ptr)
{
    printf("\nList-\n");
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->nxt;
    }
    printf("\n\n");
}

int linkedListLength(struct node *head)
{
    int i = 0; 
    struct node *ptr = head;
    while (ptr != NULL)
    {
        ptr = ptr->nxt;
        i++;
    }

    return i;
}

int main()
{
    int ch;
    int val;
    int index;
    struct node *head = NULL;
    
    mainMenu:
    printf("<----------------Menu---------------->\n");
    printf("0. Exit\n");
    printf("1. New Node\n");
    printf("2. View List\n");
    scanf("%d", &ch);
    switch(ch)
    {
        case 0:
            exit(0);
            break;
        case 1:
            goto nodeMenu;
            break;
        case 2: 
            if (head != NULL)
                displayList(head);
            else
                printf("\nNO LIST CREATED!\n\n");
            goto mainMenu;
            break;
        default:
            printf("\nINVALID INPUT, TRY AGAIN\n\n");
            goto mainMenu;
            break;
    }
	
    nodeMenu:
    printf("<------------Node Actions------------>\n");
    printf("0. Back\n");
    printf("1. Insert at End\n");
    printf("2. Insert at Beginning\n");
    printf("3. Insert in Between\n");
    scanf("%d", &ch);

    switch (ch)
    {
        case 0:
            goto mainMenu;
            break;
        case 1:
            printf("Value: ");
            scanf("%d", &val);
            newNodeTail(val, &head);
            break;
        case 2:
            printf("Value: ");
            scanf("%d", &val);
            newNodeHead(val, &head);
            break;
        case 3:
            printf("Value: ");
            scanf("%d", &val);
            printf("Index: ");
            scanf("%d", &index);
            newNodeChoose(val, &head, index, linkedListLength(head));
            break; 
        default: 
            printf("\nINVALID INPUT, TRY AGAIN\n\n");
            break;
    }
    goto nodeMenu;
}