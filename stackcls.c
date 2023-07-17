#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
struct stack
{
    char element[SIZE];
    int top;
};
void initstack(struct stack *s)
{
    s->top=0;
}
int isFull(struct stack *s)
{
    if(s->top==SIZE-1)
        return 1;
    else
        return 0;
}
void push(struct stack *s,int e)
{
    FILE *fpr;
    fpr=fopen("pushread.txt","w");

    s->top++;
    s->element[s->top]=e;

    fclose(fpr);
}
int isEmpty(struct stack *s)
{
    if(s->top==0)
        return 1;
    else
        return 0;
}
int pop(struct stack *s)
{
    int e;
    e=s->element[s->top];
    s->top--;
    return e;
}
int peek(struct stack *s)
{
    return s->element[s->top];
}
void dispaly(struct stack *s)
{
    int i;
    for(i=s->top;i>0;i--)
    {
        printf("%d ",s->element[i]);
    }
}
int main()
{
    struct stack s;
    FILE *fpi;
    int e,ch;
    fpi=fopen("pushread.txt","r");
    while(1)
    {
        printf("\n1--Push\n");
        printf("2--Pop\n");
        printf("3--Peek\n");
        printf("4--Display\n");
        printf("5--Exit\n");

        printf("Enter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: if(isFull(&s))
                    printf("Stack overflow\n");
                    else
                    {
                        fscanf(fpi,"%d",&e);
                        push(&s,e);
                    }
                    break;
            case 2: if(isEmpty(&s))
                    printf("Stack underflow\n");
                    else
                    {
                        e=pop(&s);
                        printf("%d\n",e);
                    }
                    break;
            case 3: if(isEmpty(&s))
                    printf("Stack underflow\n");
                    else
                    {
                        e=peek(&s);
                        printf("%d\n",e);
                    }
                    break;
            case 4: dispaly(&s);
                    break;
            case 5: exit(0);
                    break;
        }
    }
    fclose(fpi);
    return 0;
}
