#include <stdio.h>
#include <stdlib.h>

// Binary Tree Node Structure
struct node
{
	int data;
	struct node *left;
	struct node *right;
};

struct node *root = NULL;

void displayNodeData(struct node *currentNode)
{
	printf("Data: %d\n", currentNode->data);
		if (currentNode->left == NULL)
			printf("<-- NULL\n");
		else
			printf("<-- %d\n", (currentNode->left)->data);
		if (currentNode->right == NULL)
			printf("--> NULL\n");
		else
			printf("--> %d\n", (currentNode->right)->data);
}

void freeNav()
{
	char ch;
	int temp;
	struct node *currentNode = root;
	do 
	{
		displayNodeData(currentNode);
		printf("[NAV] Enter Choice: ");
		scanf(" %c", &ch);
		if (ch == 'D') // Deletion
		{
			if (currentNode->left == NULL || currentNode->right != NULL)
			{
				printf("Node is a parent, Deletion Failed\n");
				continue;
			}
			currentNode = NULL;
			printf("Node Deleted\n");
			continue;
		}
		else if (ch == 'S')
			return;
			
		struct node *prvNode = currentNode;
		if (ch == 'L')
			currentNode = currentNode->left;
		else
			currentNode = currentNode->right;

		if (currentNode == NULL)
		{
			currentNode = malloc(sizeof(struct node));
			if (ch == 'L')
				prvNode->left = currentNode;
			else
				prvNode->right = currentNode;
			printf("Node Created, please enter value: ");
			scanf("%d", &temp);
			currentNode->data = temp;
			currentNode->left = NULL;
			currentNode->right = NULL;
		}
	} 
	while (ch != 'S');
}

int main()
{
	int ch;

	printf("CONTROLS (use UPPERCASE, navigate to a NULL node for insertion)-\n");
	printf("0. EXIT PROGRAM\n");
	printf("1. Navigation\n"); 	
	printf("\tL - Left\n");
	printf("\tR - Right\n");
	printf("\tS - Stop Free Navigation\n");
	printf("\tD - Delete Node\n");
	printf("2. Full Display\n");
	printf("3. In-Order Display\n");
	printf("4. Pre-Order Display\n");
	printf("5. Post-Order Display\n");
	
	root = malloc(sizeof(struct node));
	printf("[INTLZTN] Enter value of root node: ");
	scanf("%d", &(root->data));
	root->left = NULL;
	root->right = NULL;

	do 
	{
		printf("[OPRTN] Enter Choice: ");
		scanf("%d", &ch);
		switch (ch)
		{
			case 0:
				return 0;
			case 1:
				freeNav();
				break;
			case 2:
				printf("WIP\n");
				break;
			case 3:
				printf("WIP\n");
				break;
			case 4:
				printf("WIP\n");
				break;
			case 5:
				printf("WIP\n");
				break;
			default: 
				printf("Wrong Option Chosen\n");
				break;
		}
	} 
	while (ch != 0);
	return 0;
}
