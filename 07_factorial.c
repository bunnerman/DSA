#include <stdio.h>
#include <stdlib.h>

int factorial(int n)
{
    if (n <= 1)
        return 1;
    else
        return factorial(n - 1) * n;
}

int main()
{
    int n;
    printf("Enter number: ");
    scanf("%d", &n);
    printf("Factorial is %d", factorial(n));
}
