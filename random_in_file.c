#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void random(int upper,int lower,int n)
{
    FILE *fp;
    int a,i;
    fp=fopen("rand.txt","w");
    for(i=0;i<n;i++)
    {
        a=(rand()%(upper+lower-1)+lower);
        printf("%d ",a);
        fprintf(fp,"%d ",a);
    }
    fclose(fp);
}
int main()
{
    int a,n,upper,lower;
    printf("Enter the value of n\n");
    scanf("%d",&n);
    printf("Enter the range\n");
    scanf("%d %d",&lower,&upper);
    random(upper,lower,n);
}

