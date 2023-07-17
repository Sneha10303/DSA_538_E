#include<stdio.h>
void read(int a[3][3],int b[3][3])
{
    int i,j;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            scanf("%d",&b[i][j]);
        }
    }
}
void display(int a[3][3],int b[3][3])
{
    int i,j;
     printf("\n");
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d ",b[i][j]);
        }
        printf("\n");
    }
}
void multiply(int a[3][3],int b[3][3])
{
    int i,j,k,mul[3][3];

    printf("\n");
    for(k=0;k<3;k++)
    {
        for(i=0;i<3;i++)
        {
            mul[k][i]=0;
            for(j=0;j<3;j++)
            {
                mul[k][i]=mul[k][i]+(a[k][j]*b[j][i]);
                //printf("%d ",mul[k][i]);
            }
            printf("%d ",mul[k][i]);
        }
         printf("\n");
    }
}
int main()
{
    int a[3][3],b[3][3],mul[3][3];
    read(a,b);
    display(a,b);
    multiply(a,b);
}
//1 1 1 1 1 1 1 1 1
//1 1 1 1 1 1 1 1 1
