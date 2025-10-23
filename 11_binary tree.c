#include <stdio.h>
#include <stdlib.h>

// Binary Tree Node Structure
struct node
{
	int data;
	struct node* left;
	struct node* right;
	struct node* back;
};

struct node* root = NULL;

void displayNodeData(struct node *currentNode)
{
	if (currentNode->left == NULL)
		printf("\nNULL <--");
	else
		printf("\n%d <--", currentNode->left->data);
	printf(" %d ", currentNode->data);
	if (currentNode->right == NULL)
		printf("--> NULL\n");
	else
		printf("--> %d\n", currentNode->right->data);
	if (currentNode->back != NULL)
		printf("Parent: %d\n\n", currentNode->back->data);
	else	
		printf("Parent: NULL (root node)\n\n");
}

void traverseLeft(struct node* currentNode)
{
	while (currentNode->left != NULL)
		currentNode = currentNode->left;
}

void traverseRight(struct node* currentNode)
{
	if (currentNode->right != NULL)
		currentNode = currentNode->right;
	else
		currentNode = currentNode->back;
}

void printNode(struct node* currentNode)
{
	printf("%d ", currentNode->data);
}

void inorderTraversal(struct node* currentNode)
{
	if (currentNode == NULL)
	{
		return;
	}
	inorderTraversal(currentNode->left);
	printf("%d ", currentNode->data);
	inorderTraversal(currentNode->right);	
}

void freeNav()
{
	char ch;
	int temp;
	struct node* currentNode = root;
	if (root == NULL)
	{
		root = malloc(sizeof(struct node));
		printf("[INTLZTN] Enter value of root node: ");
		scanf("%d", &(root->data));
		root->left = NULL;
		root->right = NULL;
		root->back = NULL;
		currentNode = root;
	}
	do 
	{
		displayNodeData(currentNode);
		printf("[NAV] Enter Choice: ");
		scanf(" %c", &ch);
		if (ch == 'D') // Deletion
		{
			if (currentNode->left != NULL || currentNode->right != NULL)
			{
				printf("Node is a parent, Deletion Failed\n");
				continue;
			}
			if (currentNode == root)
			{
				root = NULL;
				printf("Root Node Deleted, Ending Navigation Mode\n");
				return;
			}
			struct node* parentNode = currentNode->back;
			free(currentNode);
			printf("Node Deleted, rerouting to parent node\n");
			currentNode = parentNode;
			continue;
		}
		else if (ch == 'B')
		{
			if (currentNode->back == NULL)
				printf("Back Navigation Failed, already at root node\n");
			else
				currentNode = currentNode->back;
			continue;
		}
		else if (ch == 'S')
			return;
			
		struct node* prvNode = currentNode;
		if (ch == 'L')
			currentNode = currentNode->left;
		else if (ch == 'R')
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
			currentNode->back = prvNode;
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
	printf("\tB - Previous Node\n");
	printf("2. Full Display\n");
	printf("3. In-Order Display\n");
	printf("4. Pre-Order Display\n");
	printf("5. Post-Order Display\n");

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
				inorderTraversal(root);
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
