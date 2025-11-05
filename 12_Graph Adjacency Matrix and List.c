// EXP 12 - Write a program to create and display the Adjacency Matrix and Adjacency List representation of a graph 
// Assumed undirected

#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int v;
    int e;
    printf("Enter number of nodes: ");
    scanf(" %d", &v);
    printf("Enter number of edges: ");
    scanf(" %d", &e);

    int adjMatrix[v][v];
    for (int i = 0; i < v; i++)
        for (int j = 0; j < v; j++)
            adjMatrix[i][j] = 0;

    int e1;
    int e2;
    printf("Enter edges [index1 index2]: ");
    for (int i = 0; i < e; i++)
    {
        scanf(" %d %d", &e1, &e2);
        adjMatrix[e1][e2] = 1;   
        adjMatrix[e2][e1] = 1;
    }

    printf("Adjacency Matrix\n");
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
            printf("%d ", adjMatrix[i][j]);
        printf("\n");
    }

    printf("Adjacency List-");
    for (int i = 0; i < v; i++)
    {
        printf("\nNode %d -> ", i);
        for (int j = 0; j < v; j++)
        {
            if (adjMatrix[i][j] == 1)
                printf("%d ", j);
        }
    }

    return 0;
}
