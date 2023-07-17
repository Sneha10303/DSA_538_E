#include<stdio.h>
#include<stdlib.h>
#define size 5
struct Q
{
    int queue[size];
    int front;
    int rear;
};
void create(struct Q *q)
{
    q->front=-1;
    q->rear=-1;
}
void insert(struct Q *q)
{
    int item;
    printf("Enter the element\n");
    scanf("%d",&item);
    if(q->rear==size-1)
    {
        printf("\nOVERFLOW\n");
        return;
    }
    if(q->front==-1 && q->rear == -1)
    {
        q->front = 0;
        q->rear = 0;
    }
    else
    {
        q->rear++;
    }
    q->queue[q->rear] = item;
    printf("Value inserted\n");
}
void delete(struct Q *q)
{
    int item;
    if (q->front == -1 || q->front > q->rear)
    {
        printf("UNDERFLOW\n");
        return;
    }
    else
    {
        item = q->queue[q->front];
        if(q->front == q->rear)
        {
            q->front = -1;
            q->rear = -1 ;
        }
        else
        {
            q->front++;
        }
        printf("value deleted\n");
    }
}
void display(struct Q *q)
{
    int i,item;
    if(q->rear == -1)
    {
        printf("Empty queue\n");
    }
    else
    {
        printf("printing values .....\n");
        for(i=q->front;i<=q->rear;i++)
        {
            printf("%d\n",q->queue[i]);
        }
    }
}
int main ()
{
    struct Q *q,a;
    q=&a;
    q->front=-1;
    q->rear=-1;
    int ch;
    while(1)
    {
        printf("1.insert an element\n");
        printf("2.Delete an element\n");
        printf("3.Display the queue\n");
        printf("4.Exit\n");
        printf("Enter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: insert(q);
                    break;
            case 2: delete(q);
                    break;
            case 3: display(q);
                    break;
            case 4: exit(0);
                    break;
            default:
            printf("Enter valid choice\n");
        }
    }
}

