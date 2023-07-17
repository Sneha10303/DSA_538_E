#include<stdio.h>
void quick_sort();
int main()
{
    int n,i,a[50];
    printf("Enter the size of an array\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    quick_sort(a,0,n-1);
    printf("Sorted elements are\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}

void quick_sort(int a[50],int first,int last)
{
    int i,j,pivot,temp;
    if(first<last)
    {
        pivot=first;
        i=first;
        j=last;
        while(i<j)
        {
            while(a[i]<=a[pivot]&&i<last)
                i++;
            while(a[j]>a[pivot])
                j--;
            if(i<j)
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
        temp=a[pivot];
        a[pivot]=a[j];
        a[j]=temp;
        quick_sort(a,0,j-1);
        quick_sort(a,j+1,last);
    }
}
