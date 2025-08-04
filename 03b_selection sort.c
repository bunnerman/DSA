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
	
	//? Processing - Selection Sort
	int min, t;
	int swap;
	for (i = 0; i < n - 1; i++)
	{
		swap = 0;
		min = i;
		for (j = i + 1; j < n; j++)
		{
			if (ary[min] > ary[j])
			{
				min = j;
				swap = 1;
			}
		} 	
		if (swap)
		{
			t = ary[min];
			ary[min] = ary[i];
			ary[i] = t;
		}

	}
	
	//? Output
	printf("Sorted Array-\n");
	for (i = 0; i < n; i++)
		printf("%d ", ary[i]);
}