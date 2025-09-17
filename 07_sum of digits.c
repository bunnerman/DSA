#include <stdio.h>
#include <stdlib.h>

int digitSum(int n)
{
    if (n == 0)
        return 0;
    else
        return digitSum(n / 10) + n % 10;
}

int main()
{
    int n;
    printf("Enter number: ");
    scanf("%d", &n);
    printf("The sum of digits is %d", digitSum(n));
}
