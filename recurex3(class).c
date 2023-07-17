#include<stdio.h>
void recursion(int n)
{
    int i;
    if(n>0)
    {
        for(i=1;i<n;i=i*2)
        {
             printf("%d ",n);
        }
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


