#include <stdio.h>

int main()
{
    //? Variables
    int n;
    int key;
    int i;
    int found = 0;
    
    //?Input
    printf("Enter the amount of numbers you wish to input: \n");
    scanf("%d", &n);

    int ary[n];
    printf("Enter %d numbers: ", n);
    for (int i = 0; i < 10; i++)
        scanf("%d", &ary[i]);
        
    printf("Enter key (number you wish to search for): ");
    scanf("%d", &key);

    //? Processing and Output - Linear Search
    for (i = 0; i < n; i++)
        if (key == ary[i])
        {
            printf("Key found at index [%d]\n", i);
            found = 1;
        }
    if (found)
        printf("Key not found");
        
    return 0;
}