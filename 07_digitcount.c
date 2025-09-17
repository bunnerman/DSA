#include <stdio.h>
#include <stdlib.h>

int digitCount(int n)
{
    if (n == 0)
        return 0;
    else
        return digitCount(n / 10) + 1;
}

int main()
{
    int n;
    printf("Enter number: ");
    scanf("%d", &n);
    printf("The number of digits is %d", digitCount(n));
}
