#include<stdio.h>
int main()
{
    FILE *fpi,*fpo;
    char ch;
    fpi=fopen("myname.txt","r");
    fpo=fopen("opname.txt","w");
    while((ch=fgetc(fpi))!=EOF)
    {
        fprintf(fpo,"%c",ch);
    }
    fclose(fpi);
    fclose(fpo);
}
