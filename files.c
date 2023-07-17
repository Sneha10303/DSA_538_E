#include<stdio.h>
#include<stdlib.h>
int main()
{
    char ch;
    FILE *fp;
    fp=fopen("input.txt","r");
    if(fp==NULL)
    {
        printf("Error\n");
        exit(1);
    }
    ch=fgetc(fp);
    printf("The character read from the file is %c",ch);
    fprintf(fp,"%c",ch);
    fclose(fp);
}
