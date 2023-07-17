#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void replaceAll(char *str,char *ow,char *nw);
int main()
{
    FILE * fPtr;
    FILE * fTemp;
    char path[100];

    char buffer[100];
    char ow[100], nw[100];


    printf("Enter path of source file: ");
    scanf("%s", path);

    printf("Enter word to replace: ");
    scanf("%s", ow);

    printf("Replace '%s' with: ");
    scanf("%s", nw);

    fPtr  = fopen(path, "r");
    fTemp = fopen("replace.txt", "w");
    if (fPtr == NULL || fTemp == NULL)
    {
        printf("can't open file.\n");
        exit(0);
    }
    while ((fgets(buffer,100, fPtr)) != NULL)
    {
        replaceAll(buffer, ow, nw);
        fputs(buffer, fTemp);
    }
    fclose(fPtr);
    fclose(fTemp);
    remove(path);
    rename("replace.tmp", path);

    printf("\nSuccessfully replaced all occurrences of '%s' with '%s'.", ow, nw);

    return 0;
}
void replaceAll(char *str,char *ow,char *nw)
{
    char *pos, temp[100];
    int index = 0;
    int len;

    len = strlen(ow);
    if (!strcmp(ow,nw))
    {
        return;
    }
    while ((pos = strstr(str,ow)) != NULL)
    {
        strcpy(temp,str);
        index = pos - str;
        str[index] = '\0';
        strcat(str, nw);
        strcat(str, temp + index + len);
    }
}
