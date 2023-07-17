#include<stdio.h>
#include<string.h>
int main()
{
    FILE *fp;
    int i;
    char ch;
    char str[30]="My name is sneha sb is good";
    fp=fopen("myaname.txt","r");
    //fputs(str,fp);

    for(i=0;i!=strlen(str);i++)
        fputc(str[i],fp);
    //fprintf(fp,"%c",str[i]);
    fclose(fp);
}
