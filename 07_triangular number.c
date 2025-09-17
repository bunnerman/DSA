#include <stdio.h>
#include <stdlib.h>

int triangularNumber(int n)
{
    if (n <= 1)
        return 1;
    else
        return triangularNumber(n - 1) + n;
}

int main()
{
    int n;
    printf("Enter number: ");
    scanf("%d", &n);
    printf("Triangular Number is %d", triangularNumber(n));
}
