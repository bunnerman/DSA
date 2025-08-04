#include <stdio.h>

int main() 
{
    //? Variables
    int n;
    int i, j, k;

	//? Input
	printf("Enter the amount of numbers you wish to sort: ");
	scanf("%d", &n);

	int ary[n];
    int tary[n];
	printf("Enter %d numbers: ", n);
	for (i = 0; i < n; i++)
		scanf("%d", &ary[i]);

	//? Processing - Radix Sort w/ Counting Sort
	int max = ary[0];
	int maxdig = 0;
	int cntary[10];
	int t;

	// Highest Number (more efficient than finding number of digits of each number)
    for (i = 0; i < n; i++)
        if (ary[i] > max)
            max = ary[i];

	// Max number of Digits
	while (max != 0)
	{
		max /= 10;
		maxdig++;
	}

	// Main Loop
	for (i = 0; i < maxdig; i++)
	{
		// Reinitializing all digits in counting array to 0
		for (j = 0; j < 10; j++)
			cntary[j] = 0;

		// Counting Sort array digit count
		for (j = 0; j < n; j++)
		{
			t = ary[j];

			for (k = 0; k < i; k++)
				t /= 10;
			t %= 10;
			cntary[t]++;
		}
		// Get the index where they have to be inserted/Cumulative sum
		for (j = 1; j < 10; j++)
			cntary[j] += cntary[j - 1];
		
		// Place values into temporary array tary
		for (j = n - 1; j >= 0; j--)
		{
			t = ary[j];
			for (k = 0; k < i; k++)
				t /= 10;
			t %= 10;

			cntary[t]--;
			tary[cntary[t]] = ary[j];
		}

		// Values copied back to original array ary
		for (j = 0; j < n; j++)
			ary[j] = tary[j];
	}    

    //? Output
    printf("Sorted array-\n");
    for (i = 0; i < n; i++)
        printf("%d ", ary[i]);

    return 0;
}