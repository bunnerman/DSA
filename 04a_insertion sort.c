#include <stdio.h>

int main()
{
	//? Variables
	int ary[10];
	int i, j;
	int n = 0;
	int temp;
	int shifts = 0, inserts = 0;

	//? Input
	printf("Enter the number of numbers you wish to sort: ");
	scanf("%d", &n);
	printf("Enter %d numbers: ", n);
	for (i = 0; i < n; i++)
		scanf("%d", &ary[i]);

	//? Process - Insertion Sort
	for (i = 1; i < n; i++)
	{
		j = i - 1;
		temp = ary[i];
		while (j >= 0 && ary[j] > temp)
		{
			ary[j + 1] = ary[j];
			j--;
			shifts++;
		}
		ary[j + 1] = temp;
		inserts++;
	}

	//? Display
	for (i = 0; i < n; i++)
		printf("%d ", ary[i]);

	printf("\n\n");

	printf("i loop iterations: %d\n", i);
	printf("Inserts (should always be 1 less than i): %d\n", inserts);
	printf("Shifts (amount of times j got decremented): %d\n", shifts);

    return 0;
}
