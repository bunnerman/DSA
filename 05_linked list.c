#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *nxt;
};

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

void newNodeAt(int val, struct node **head, int index)
{
    struct node *ptr;
    ptr = *head;
    if (*head == NULL || index <= 0)
        newNodeHead(val, head);
    else if (index >= linkedListLength(*head))
        newNodeTail(val, head);
    else
    {
        int i = 0;
        while (i < index - 1)
        {
            ptr = ptr->nxt;
            i++;
        }
        struct node *newPtr;
        newPtr = malloc(sizeof(struct node));
        newPtr->data = val;
        newPtr->nxt = ptr->nxt;
        ptr->nxt = newPtr;
    }
}

void newNodeBefore(int val, struct node **head, int num)
{
    if (*head == NULL) 
    {
        printf("NO NODE INSERTED!\n");
        return;
    }
    if ((*head)->data == num)
    {
        newNodeHead(val, head);
        return;
    }
    struct node *ptr = *head;
    while (ptr->nxt != NULL && ptr->nxt->data != num)
        ptr = ptr->nxt;
    if (ptr->nxt == NULL) 
    {
        printf("NODE NOT FOUND!\n");
        return;
    }

    struct node *newPtr = malloc(sizeof(struct node));
    newPtr->data = val;
    newPtr->nxt = ptr->nxt;
    ptr->nxt = newPtr;
}

void newNodeAfter(int val, struct node **head, int num)
{
    struct node *ptr = *head;
    while (ptr != NULL && ptr->data != num)
        ptr = ptr->nxt;
    if (ptr == NULL) 
        return;

    struct node *newPtr = malloc(sizeof(struct node));
    newPtr->data = val;
    newPtr->nxt = ptr->nxt;
    ptr->nxt = newPtr;
}

void delNodeHead(struct node **head)
{
    if (*head == NULL) 
        return;
    struct node *t = *head;
    *head = (*head)->nxt;
    free(t);
}

void delNodeTail(struct node **head)
{
    if (*head == NULL)
        return;
    if ((*head)->nxt == NULL)
    {
        free(*head);
        *head = NULL;
        return;
    }
    struct node *ptr = *head;
    while (ptr->nxt->nxt != NULL)
        ptr = ptr->nxt;
    free(ptr->nxt);
    ptr->nxt = NULL;
}

void delNodeAt(struct node **head, int index)
{
    if (*head == NULL)
        return;
    if (index <= 0)
    {
        delNodeHead(head);
        return;
    }
    struct node *ptr = *head;
    int i = 0;
    while (ptr->nxt != NULL && i < index - 1)
    {
        ptr = ptr->nxt;
        i++;
    }
    if (ptr->nxt == NULL) 
        return;
    struct node *tmp = ptr->nxt;
    ptr->nxt = tmp->nxt;
    free(tmp);
}

void delNodeBefore(struct node **head, int num)
{
    struct node *ptr = *head;
    struct node *prv = NULL;
    
    if (*head == NULL || (*head)->nxt == NULL) 
    {
        printf("No node exists before %d\n", num);
        return;
    }
    if (ptr->data == num) 
    {
        printf("No node exists before %d\n", num);
        return;
    }
    if (ptr->nxt->data == num) 
    {
        struct node *temp = *head;
        *head = (*head)->nxt;
        free(temp);
        return;
    }
    while (ptr->nxt != NULL && ptr->nxt->data != num) 
    {
        prv = ptr;
        ptr = ptr->nxt;
    }
    if (ptr->nxt == NULL) 
    {
        printf("Node with data %d not found\n", num);
        return;
    }
    if (prv != NULL) 
    {
        prv->nxt = ptr->nxt;
        free(ptr);
    }
}

void delNodeAfter(struct node **head, int num)
{
    if (*head == NULL) return;

    struct node *ptr = *head;
    while (ptr != NULL && ptr->data != num)
        ptr = ptr->nxt;

    if (ptr == NULL || ptr->nxt == NULL) return;

    struct node *temp = ptr->nxt;
    ptr->nxt = temp->nxt;
    free(temp);
}


int searchNode(struct node *head, int val)
{
    int index = 0;
    while (head != NULL)
    {
        if (head->data == val)
            return index;
        head = head->nxt;
        index++;
    }
    return -1; // less than 0 to show no index found
}

void mergeLists(struct node *h1, struct node **h2)
{
    if (h1 == NULL)
    {
        printf("PLEASE ENTER ELEMENTS INTO FIRST LIST!!!!!!!\n");
        return;
    }
    struct node *ptr = h1;
    while (ptr->nxt != NULL)
        ptr = ptr->nxt;

    ptr->nxt = *h2;
    *h2 = NULL;
}

void displayList(struct node *ptr)  
{
    printf("\nList-\n");
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->nxt;
    }
    printf("\n\n");
}

int main()
{
    int ch;
    int val;
    int index;
    int listMergeFlag = 0;
    struct node *head = NULL;
    
    // Second List to show merging concept and function
    struct node *head2 = NULL;
    head2 = malloc(sizeof(struct node));
    head2->data = 111;
    head2->nxt = malloc(sizeof(struct node));
    (head2->nxt)->data = 222;
    (head2->nxt)->nxt = NULL;

    mainMenu:
    printf("<----------------Menu---------------->\n");
    printf("0. Exit\n");
    printf("1. New Node\n");
    printf("2. View List\n");
    printf("3. Delete Node\n");
    printf("4. Search\n");
    if (!listMergeFlag) //` If list is merged, don't show this menu again
    {
        printf("5. View Second List ([111], [222] are the only elements taken for example)\n");
        printf("6. Merge Second List's Head to First List's Tail\n");
        printf("7. Merge First List's Head to Second List's Tail\n");
    }

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
        case 3: 
            goto delMenu;
            break;
        case 4:
            printf("Number: ");
            scanf("%d", &index); // reused, actually the number you want to search
            printf("Number found at: [%d] (-1 if not found)\n", searchNode(head, index));
            goto mainMenu;
            break;
        case 5:
            if (!listMergeFlag) 
            {
                displayList(head2);
                break;
                goto mainMenu;
            }
            printf("List Operations have been performed already\n");
            goto mainMenu;
            break;
        case 6:
            if (!listMergeFlag) 
            {
                mergeLists(head, &head2);
                listMergeFlag = 1;
                goto mainMenu;
                break;
            }
            printf("List Operations have been performed already\n");
            goto mainMenu;
            break;
        case 7:
            if (!listMergeFlag) 
            {
                mergeLists(head2, &head);
                listMergeFlag = 1;
                goto mainMenu;
                break;
            }
            printf("List Operations have been performed already\n");
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
    printf("1. Insert at Tail\n");
    printf("2. Insert at Head\n");
    printf("3. Insert at Index\n");
    printf("4. Insert before Number\n");
    printf("5. Insert after Number\n");
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
            newNodeAt(val, &head, index);
            break;
        case 4:
            printf("Value: ");
            scanf("%d", &val);
            printf("Number: ");
            scanf("%d", &index); // repurposed for number
            newNodeBefore(val, &head, index);
            break;
        case 5:
            printf("Value: ");
            scanf("%d", &val);
            printf("Number: ");
            scanf("%d", &index); // repurposed for number
            newNodeAfter(val, &head, index);
            break;
        default: 
            printf("\nINVALID INPUT, TRY AGAIN\n\n");
            break;
    }
    goto nodeMenu;

    delMenu:
    printf("<-----------Deletion Menu------------>\n");
    printf("0. Back\n");
    printf("1. Delete at Head\n");
    printf("2. Delete at Tail\n");
    printf("3. Delete at Index\n");
    printf("4. Delete before Number\n");
    printf("5. Delete after Number\n");
    scanf("%d", &ch);
    switch(ch)
    {
        case 0:
            goto mainMenu;
        case 1:
            delNodeHead(&head);
            break;
        case 2:
            delNodeTail(&head);
            break;
        case 3:
            printf("Index: ");
            scanf("%d", &index);
            delNodeAt(&head, index);
            break;
        case 4:
            printf("Number: ");
            scanf("%d", &index); // repurposed for number
            delNodeBefore(&head, index);
            break;
        case 5:
            printf("Number: ");
            scanf("%d", &index); // repurposed for number
            delNodeAfter(&head, index);
            break;
        default:
            printf("\nINVALID INPUT, TRY AGAIN\n");
            break;
    }
    goto delMenu;
}
