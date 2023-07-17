#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void random(int lower,int upper,int count)
{
    int num,i;
    for(i=0;i<count;i++)
    {
        num=(rand()%(upper-lower+1))+lower;
        printf("%d ",num);
    }
}
int main()
{
    int count=1,upper,lower;
    printf("Enter the lower number = ");
    scanf("%d",&lower);
    printf("Enter the upper number = ");
    scanf("%d",&upper);
    printf("how many random numbers to generate = ");
    scanf("%d",&count);
    random(lower,upper,count);
}
