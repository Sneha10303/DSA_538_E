#include<stdio.h>
int main()
{
    FILE *fp;
    char ch;
    int count=1;
    fp=fopen("myname.txt","r");
    while((ch=fgetc(fp))!=EOF)
    {
        if(ch=='\n')
        {
            count++;
        }
    }
    printf("%d",count);
    fclose(fp);
}

