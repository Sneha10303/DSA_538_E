#include<stdio.h>
/*void read(int a[3][3])
{
    int i,j;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
}*/
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
void random(int ch,int n)
{
    int r,i;
    printf("Enter how many random values you need : ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        ch=((n%10)+i);
        printf("%d ",ch);
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
    int a[3][3],ch,i;
    random(ch,i);
    //read(a);
    display(a);
    transpose(a);
}
