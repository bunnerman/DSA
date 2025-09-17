#include <stdio.h>
#include <stdlib.h>

int fib(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    else
        return fib(n - 1) + fib(n - 2);
}

int main()
{
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    printf("The number in nth place in fibonacci is %d", fib(n));
}
