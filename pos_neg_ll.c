#include<stdio.h>
#include<stdlib.h>
struct node
{
    char data;
    struct node *next;
};
struct node *getNode()
{
    FILE *fp;
    fp=fopen("posneg.txt","r");
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Numbers in the linked list are\n");
    while(!feof(fp))
    {
        //newnode->data=fgetc(fp);
        fscanf(fp,"%c",&newnode->data);
        printf("%c",newnode->data);
    }
    //scanf("%d",&newnode->data);
    newnode->next=NULL;
    fclose(fp);
    return newnode;
}
struct node *insert_end(struct node *head)
{
    struct node *temp,*temp1;
    if(head==NULL)
    {
        head=getNode();
        return head;
    }
    else
    {
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp1=getNode();
        temp->next=temp1;
        temp1->next=NULL;
        return head;
    }
}
struct node *sort_pn(struct node *head)
{
    struct node *temp,*newnode;
    printf("\nPositive numbers are = ");
    temp=head;
    while(temp->next!=NULL)
    {
        if((newnode->data)>0)
        {
            printf("%c",temp->data);
        }
        else
        {
            printf("%c ",temp->data);
        }
        temp=temp->next;
    }

    return head;
}
int main()
{
    struct node *head;
    head=NULL;
    char ch;
    head=insert_end(head);
    head=sort_pn(head);
}
