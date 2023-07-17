#include<stdio.h>
#include<stdlib.h>
int main()
{
    char ch;
    FILE *fp=NULL;
    fp=fopen("input.txt","r");
    if(fp==NULL)
    {
        printf("Error\n");
        exit(1);
    }
    //fgets(ch,20,fp);
    //printf("%s",ch);
    while(!feof(fp))
    {
        ch=fgetc(fp);
        printf("%c",ch);
    }
    //fprintf(fp,"%c",ch);
    fclose(fp);
}

