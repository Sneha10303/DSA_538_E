#include<stdio.h>
int main()
{
    FILE *fp;
    char ch;
    fp=fopen("rand.txt","r");
    if(fp==NULL)
    {
        printf("Error,there is no such file\n");
    }
    else
    {
        while(!feof(fp))
        {
            ch=fgetc(fp);
            //fscanf(fp,"%d",ch);
            printf("%c",ch);

        }

    }

    fclose(fp);
}
