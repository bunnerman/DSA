#include <stdio.h>

int main()
{
	//? Variables
	int n;
	int key;
	int i;

	//? Input
	printf("Enter the amount of numbers you wish to input: ");
	scanf("%d", &n);

	int ary[n];
	printf("Enter %d numbers IN ASCENDING ORDER: ", n);
	for (i = 0; i < n; i++)
		scanf("%d", &ary[i]);

	printf("Enter the key (number you wish to search for): ");
	scanf("%d", &key);

	//? Processing and Output - Binary Search (single number)
	int low = 0, high = n - 1;
	int mid;
	while (high >= low)
	{
		mid = (high + low) / 2;
		if (key == ary[mid])
		{
			printf("Key found at index [%d]", mid);
			return 0;
		}
		else if (key > ary[mid])
			low = mid + 1;
		else
			high = mid - 1;
	}
	
	printf("Key not found");
}