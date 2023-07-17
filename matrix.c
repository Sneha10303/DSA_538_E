#include<stdio.h>
void read();
void display();
void multiply();
int main()
{
    int r,c,n;
    int a[r][c],b[r][c],i,j;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++);
        {
            read();
        }
    }
    display(a,b);
}
void read()
{
    int i,j;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++);
        {
            scanf("%d",&a[i][j]);
        }
    }
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++);
        {
            scanf("%d",&b[i][j]);
        }
    }
}
void display()
{
    int i,j;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++);
        {
            printf("%d ",a[i][j]);
        }
    }
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++);
        {
            printf("%d ",b[i][j]);
        }
    }
}
void multiply()
{
    int i,j,sum[10][10];
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++);
        {
           sum[i][j]=c[i][j]+a[i][j]*b[i][j];
        }
    }
    printf("%d ",c[i][j]);
}













