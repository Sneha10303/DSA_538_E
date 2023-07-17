#include<stdio.h>
void duplicate(int a[20])
{
    int n,i,j,d,b;
    for(i=0;i<n;i++)
    {
      int flag=0;
      b=0;
      for(j=i+1;j<n;j++)
      {
          if(a[i]==a[j])
          {
              if(a[j]!=0)
              {
                flag=1;
                d=a[i];
                a[j]=0;
                b++;
              }
          }
      }
      if(flag==1)
      {
          printf("the number %d is repeated for %d \n",d,b+1);
      }

  }
}
int main()
{
      int n,i,j,a[20],d,c;
      printf("Enter n = \n");
      scanf("%d",&n);
      for(i=0;i<n;i++)
      {
        scanf("%d",&a[i]);
      }
      printf("The array elements are\n");
      for(i=0;i<n;i++)
      {
        printf("%d ",a[i]);
      }
      printf("\n");
    duplicate(a);
}
