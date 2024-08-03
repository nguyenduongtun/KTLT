#include<stdio.h>

#include <stdio.h>

int sum(int n)
{
    if (n == 1)
    {
        return 1 * 2;
    }
    return n * (n + 1) + sum(n - 1);
}
void main()
{
	int n;
	printf("nhap so nguyen duong n: ");
	scanf_s("%d", &n);
	int result = sum(n);
	printf("S(%d)=%d \n", n, result);
}