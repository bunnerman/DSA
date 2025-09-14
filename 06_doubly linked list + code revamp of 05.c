#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prv;
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
        (*head)->prv = NULL;
        (*head)->nxt = NULL;
    }
    else
    {
        struct node *ptr = *head;
        while (ptr->nxt != NULL)
            ptr = ptr->nxt;
        
        struct node *nnPtr = malloc(sizeof(struct node));
        ptr->nxt = nnPtr;
        nnPtr->data = val;
        nnPtr->prv = ptr;
        nnPtr->nxt = NULL;
    }
}

void newNodeHead(int val, struct node **head)
{
    if (*head == NULL)
    {
        *head = malloc(sizeof(struct node));
        (*head)->data = val;
        (*head)->prv = NULL;
        (*head)->nxt = NULL;
    }
    else
    {
        struct node *nnPtr;
        nnPtr = malloc(sizeof(struct node));
        nnPtr->data = val;
        nnPtr->prv = NULL;
        nnPtr->nxt = *head;
        (*head)->prv = nnPtr;
        *head = nnPtr;
    }
}

void newNodeAt(int val, struct node **head, int index)
{
    struct node *ptr = *head;

    if (*head == NULL || index <= 0)
    {
        printf("Index either too short, at head or list hasn't been made, inserting at head\n");
        newNodeHead(val, head);
        return;
    }
    else if (index >= linkedListLength(*head))
    {
        printf("Index either too long or at tail, inserting at tail\n");
        newNodeTail(val, head);
        return;
    }
    else
    {
        int i = 0;
        while (i < index - 1)
        {
            ptr = ptr->nxt;
            i++;
        }

        struct node *nnPtr = malloc(sizeof(struct node));
        nnPtr->data = val;
        nnPtr->prv = ptr;
        nnPtr->nxt = ptr->nxt;
        ptr->nxt = nnPtr;
        (nnPtr->nxt)->prv = nnPtr;
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
    while (ptr != NULL && ptr->data != num)
        ptr = ptr->nxt;
    if (ptr == NULL)
    {
        printf("VALID NODE NOT FOUND!\n");
        return;
    }

    struct node *nnPtr = malloc(sizeof(struct node));
    nnPtr->data = val;
    nnPtr->prv = ptr->prv;
    nnPtr->nxt = ptr;

    if (ptr->prv == NULL)
        *head = nnPtr;
    else
        (nnPtr->prv)->nxt = nnPtr;
    ptr->prv = nnPtr;
}

void newNodeAfter(int val, struct node **head, int num)
{
    struct node *ptr = *head;
    while (ptr != NULL && ptr->data != num)
        ptr = ptr->nxt;
    if (ptr == NULL)
    {
        printf("VALID NODE NOT FOUND!");
        return;
    }
    struct node *nnPtr = malloc(sizeof(struct node));
    nnPtr->data = val;
    nnPtr->prv = ptr;
    nnPtr->nxt = ptr->nxt;

    if (nnPtr->nxt != NULL)
        (nnPtr->nxt)->prv = nnPtr;
    ptr->nxt = nnPtr;
}

void delNodeTail(struct node **head)
{
    if (*head == NULL)
    {
        printf("NO NODES IN LIST\n");
        return;
    }
    else if ((*head)->nxt == NULL)
    {
        printf("Only one node found, deleting head\n");
        free(*head);
        *head = NULL;
        return;
    }
    struct node *ptr = *head;
    while (ptr->nxt != NULL)
        ptr = ptr->nxt;
    (ptr->prv)->nxt = NULL;
    free(ptr);
}

void delNodeHead(struct node **head)
{
    if (*head == NULL)
    {
        printf("NO NODES IN LIST\n");
        return;
    }
    else if ((*head)->nxt == NULL)
    {
        printf("Only one node found, deleting head\n");
        free(*head);
        *head = NULL;
        return;
    }
    struct node *ptr = *head;
    *head = (*head)->nxt;
    (*head)->prv = NULL;
    free(ptr);
}

void delNodeAt(struct node **head, int index)
{
    if (index <= 0)
    {
        printf("Index either too short or at head, deleting at head\n");
        delNodeHead(head);
        return;
    }
    else if (index >= linkedListLength(*head))
    {
        printf("Index either too long or at tail, deleting at tail\n");
        delNodeTail(head);
        return;
    }
    struct node *ptr = *head;
    int i = 0;
    while (ptr != NULL && i < index)
    {
        ptr = ptr->nxt;
        i++;
    }

    if (ptr->prv != NULL)
        (ptr->prv)->nxt = ptr->nxt;
    if (ptr->nxt != NULL)
        ptr->nxt->prv = ptr->prv;
    free(ptr);
}

void delNodeBefore(struct node **head, int num)
{
    struct node *ptr = *head;
    if (*head == NULL)
    {
        printf("NO NODE INSERTED!\n");
        return;
    }
    while (ptr != NULL && ptr->data != num)
        ptr = ptr->nxt;
    if (ptr == NULL)
    {
        printf("Node with value %d not found\n", num);
        return;
    }
    ptr = ptr->prv;
    if (ptr == NULL)
    {
        printf("No node exists before %d\n", num);
        return;
    }
    if (ptr->prv == NULL)
        *head = ptr->nxt;
    else
        (ptr->prv)->nxt = ptr->nxt;
    (ptr->nxt)->prv = ptr->prv;
    free(ptr);
}

void delNodeAfter(struct node **head, int num)
{
    struct node *ptr = *head;
    if (*head == NULL)
    {
        printf("NO NODE INSERTED!\n");
        return;
    }
    while (ptr != NULL && ptr->data != num)
        ptr = ptr->nxt;
    if (ptr == NULL)
    {
        printf("Node with value %d not found\n", num);
        return;
    }
    ptr = ptr->nxt;
    if (ptr == NULL)
    {
        printf("No node exists after %d\n", num);
        return;
    }
    if (ptr->nxt != NULL)
        ptr->nxt->prv = ptr->prv;
    (ptr->prv)->nxt = ptr->nxt;
    free(ptr);
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
    (*h2)->prv = ptr;
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
    head2->prv = NULL;
    head2->nxt = malloc(sizeof(struct node));
    (head2->nxt)->data = 222;
    (head2->nxt)->prv = head2;
    (head2->nxt)->nxt = NULL;

    mainMenu:
    printf("<----------------Menu---------------->\n");
    printf("0. Exit\n");
    printf("1. New Node\n");
    printf("2. View List\n");
    printf("3. Delete Node\n");
    printf("4. Search\n");
    if (!listMergeFlag) // If list is merged, don't show this menu again
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
            scanf("%d", &index); // reused, the variable is actually the number you want to search
            printf("Number found at: [%d] (-1 if not found)\n", searchNode(head, index));
            goto mainMenu;
            break;
        case 5:
            if (!listMergeFlag)
            {
                displayList(head2);
                goto mainMenu;
                break;
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
    printf("1. Delete at Tail\n");
    printf("2. Delete at Head\n");
    printf("3. Delete at Index\n");
    printf("4. Delete before Number\n");
    printf("5. Delete after Number\n");
    scanf("%d", &ch);
    switch(ch)
    {
        case 0:
            goto mainMenu;
        case 1:
            delNodeTail(&head);
            break;
        case 2:
            delNodeHead(&head);
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