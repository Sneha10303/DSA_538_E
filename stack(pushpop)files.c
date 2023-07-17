#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#define SIZE 10
struct stack
{
    char element[SIZE];
    int top;
};
void random(struct stack *s)
{
    FILE *fpin;
    int i,num;
    int count=1,upper,lower;
    printf("Enter the lower number = ");
    scanf("%d",&lower);
    printf("Enter the upper number = ");
    scanf("%d",&upper);
    printf("how many random numbers to generate = ");
    scanf("%d",&count);
    fpin=fopen("inputrandom.txt","r+");
    for(i=0;i<count;i++)
    {
        num=(rand()%(upper-lower+1)+lower);
        printf("%d ",num);
        fprintf(fpin,"%d ",num);
    }
    fclose(fpin);
}
void initstack(struct stack *s)
{
    s->top=-1;
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
    FILE *fpush,*fpin;
    int i;
    fpush=fopen("push.txt","w");

    while(!feof)
    {
        fscanf(fpin,"inputrandom.txt","r");
    }
    s->top++;
    s->element[s->top]=e;
    for(i=s->top;i>0;i--)
    {
        //printf("%d->",s->element[i]);
        fprintf(fpush,"%d->",s->element[i]);
    }
    fclose(fpush);

}
int isEmpty(struct stack *s)
{
    if(s->top==-1)
        return 1;
    else
        return 0;
}
int pop(struct stack *s)
{
    FILE *fpop;
    fpop=fopen("pop.txt","r+");
    int e;
    e=s->element[s->top];
    s->top--;
    fprintf(fpop,"%d",e);
    fclose(fpop);
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
        printf("%d->",s->element[i]);
    }
}
void stackfile(struct stack *s)
{
    FILE *fst;
    int i;
    fst=fopen("stack.txt","r+");
    for(i=s->top;i>0;i--)
    {
        fprintf(fst,"%d ",s->element[i]);
    }
    fclose(fst);
}
int main()
{
    struct stack s;
    FILE *fpin;
    int e,ch,i;
    while(1)
    {
        printf("\n1--Push\n");
        printf("2--Pop\n");
        printf("3--Peek\n");
        printf("4--Display\n");
        printf("5--Exit\n");
        printf("6--Random numbers\n");
        printf("7--stackfile\n");

        printf("Enter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: if(isFull(&s))
                    printf("Stack overflow\n");
                    else
                    {
                        printf("Enter the element\n");
                        //fscanf(fpin,"inputrandom.txt","r+");
                        //scanf("%d",&e);
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
            case 6: random(&s);
                    break;
            case 7: stackfile(&s);
                    break;
        }

    }
    return 0;
}
