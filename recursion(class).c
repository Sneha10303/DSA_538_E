#include<stdio.h>
void recursion(int n)
{
    if(n>0)
    {
        printf("%d ",n);
        recursion(n-1);
    }
}
int main()
{
    int n;
    printf("Enter the value of n\n");
    scanf("%d",&n);
    recursion(n);
}
