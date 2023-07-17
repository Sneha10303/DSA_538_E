#include<stdio.h>
int factorial(int n)
{
    if(n==1)
        return 1;
    else
        return (n*factorial(n-1));
}
int main()
{
    int num;
    long long int a;
    printf("Enter the number\n");
    scanf("%d",&num);
    a=factorial(num);
    printf("factorial of %d is %lld\n",num,a);
}

