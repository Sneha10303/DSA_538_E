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
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d ",a[j][i]);
        }
        printf("\n");
    }
}
int main()
{
    int a[3][3],ch[3][3];
    FILE *fp1,*fp2;
    fp1=fopen("input.txt","w");
    read(a);
    display(a);
    transpose(a);
    fp2=fopen("output.txt","r");
    fclose(fp1);
    fclose(fp2);
}

