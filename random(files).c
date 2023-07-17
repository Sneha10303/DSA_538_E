#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void random(int lower,int upper,int count)
{
    FILE *fpin;
    int i,num;
    fpin=fopen("Randominput.txt","w");
    for(i=0;i<count;i++)
    {
        num=(rand()%(upper-lower+1)+lower);
        printf("%d ",num);
        fprintf(fpin,"%d ",num);
    }
    fclose(fpin);
}
int main()
{
    FILE *fpout;
    int count=1,upper,lower;
    printf("Enter the lower number = ");
    scanf("%d",&lower);
    printf("Enter the upper number = ");
    scanf("%d",&upper);
    printf("how many random numbers to generate = ");
    scanf("%d",&count);
    random(lower,upper,count);
}

