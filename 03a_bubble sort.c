#include <stdio.h>

int main()
{
	//? Variables
	int n;
	int i, j;

	//? Input
	printf("Enter the amount of numbers you wish to sort: ");
	scanf("%d", &n);

	int ary[n];
	printf("Enter %d numbers: ", n);
	for (i = 0; i < n; i++)
		scanf("%d", &ary[i]);
	
	//? Processing - Bubble Sort
	int t;
	for (i = 0; i < n - 1; i++)
		for (j = 0; j < (n - i - 1); j++)
			if (ary[j] > ary[j + 1])
			{
				t = ary[j];
				ary[j] = ary[j + 1];
				ary[j + 1] = t;
			}
	//? Output
	printf("Sorted Array-\n");
	for (i = 0; i < n; i++)
		printf("%d ", ary[i]);
}