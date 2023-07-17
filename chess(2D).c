#include<stdio.h>
#include<string.h>
void read(char a[8][8])
{
    int i,j;
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
            scanf("%s",&a[i][j]);
        }
    }
}
void display(char a[8][8])
{
    int i,j;
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
            printf("%s ",&a[i][j]);
        }
        printf("\n");
    }

}
/*void chess(int a[8][8])
{
    int i,j;
    for(i=0;i<2;i++)
    {
        for(i=0;i<2;i++)
        {
            a[j]=
        }
    }
}*/
int main()
{
    char a[8][8]={'a','b','c','d','e','f','g','h'
                  'a','b','c','d','e','f','g','h'
                  'a','b','c','d','e','f','g','h'
                  'a','b','c','d','e','f','g','h'
                                }
    read(a);
    display(a);
}

