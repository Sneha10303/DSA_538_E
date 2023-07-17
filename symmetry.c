#include<stdio.h>
#include<stdio.h>
void read(int a[3][3])
{
    int i,j;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
}
void display(int a[3][3])
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
}
void transpose(int a[3][3])
{
    int i,j;
    printf("\n");
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d ",a[j][i]);
        }
        printf("\n");
    }
}
void sym_matrix(int a[3][3])
{
    int i,j,flag;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
             if(a[i][j]==a[j][i])
            {
                flag=1;
                break;
            }
            else
            {
                flag=0;
                break;
            }

        }

    }
    if(flag==1)
        {
            printf("Matrix are symmetric\n");
        }
        else
        {
            printf("Matrix are not symmetric\n");
        }
        printf("\n");
}
int main()
{
    int a[3][3],b[3][3],c[3][3];
    read(a);
    display(a);
    transpose(a);
    sym_matrix(a);
}
