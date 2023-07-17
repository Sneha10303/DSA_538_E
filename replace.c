#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void findandreplace()
{
    FILE *ow,*nw;
    char word[100],ch,read[100],replace[100];
    int wordlen,i, p = 0;

    ow = fopen("search.txt", "r");
    nw = fopen("replace.txt", "w+");
    if (ow== NULL || nw== NULL)
    {
        printf("Can't open file.");
        exit(0);
    }
    while (1)
    {
        ch = fgetc(ow);
        if (ch == EOF)
        {
            break;
        }
        printf("%c", ch);
    }
}
int main()
{
    char ch[100];
    printf("Enter the word you want to replace = ");
    scanf("%s",ch);
}
