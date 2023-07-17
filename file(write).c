#include<stdio.h>
#include<stdlib.h>
int main()
{
    char ch[20]="sneha bujurke";
    FILE *fp=NULL;
    fp=fopen("write.txt","w");
    if(fp==NULL)
    {
        printf("ERROR");
    }
    fputs(ch,fp);
    printf("%s",ch);
    fclose(fp);
}
