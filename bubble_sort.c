#include<stdio.h>
void bubble_sort(int a[],int n)
{
    int i,j,temp;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    printf("Sorted by bubble sort = ");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}
void merge(int a[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = a[l + i];
    for (j = 0; j < n2; j++)
        R[j] = a[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            a[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        a[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        a[k] = R[j];
        j++;
        k++;
    }
}

void mergesort(int a[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergesort(a, l, m);
        mergesort(a, m + 1, r);
        merge(a, l, m, r);
    }
}
void printarray(int A[], int n)
{
    int i;
    printf("\nSorted by merge sort = ");
    for (i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
}
/*void random(int n)
{
    int n;
    for(i=0;i<n;i++)
    {
        if(n%)
    }
}*/
int main()
{
    int a[20],n,i,l,r;
    printf("Enter the n numbers\n");
    scanf("%d",&n);
    printf("Enter the numbers you want to sort\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    bubble_sort(a,n);
    mergesort(a,l,r);
    printarray(a,n);
}
