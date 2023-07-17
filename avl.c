#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    int level;
    struct node *left;
    struct node *right;
};
struct node *create_node(int key)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=key;
    newnode->right=newnode->left=NULL;
    newnode->level=1;
    return newnode;
}
struct node *insertion(struct node *root,int key)
{
    struct node *newnode;
    if(root==NULL)
    {
        newnode=create_node(key);
        return newnode;
    }
    else
    {
        if(key>=root->data)
        {
            root->right=insertion(root->right,key);
        }
        else
        {
            root->left=insertion(root->left,key);
        }
    }
    root->level=1+root->level;
    return root;
}
struct node *deletion(struct node *root)
{

}
int max(int a,int b)
{
    if(a>b)
        return a;
    else
        return b;
}
int height(struct node *root)
{
    if(root==NULL)
        return 0;
    else
        return root->level;
}
void printlevel_order(struct node *root , int i)
{
    struct node *k;
    k=root;
    int m;
    m=i;
    if(k==NULL)
    {
        return;
    }
    else if(i==1)
    {
        printf(" %d",root->data);
    }
    else
    {
        printlevel_order(root->left,i-1);
        printlevel_order(k->right,m-1);
    }
}
void level_order(struct node *root)
{
    int ht;
    ht=height(root);
    for(int i=1;i<=ht;i++)
    {
        printlevel_order(root,i);
        printf("\n");
    }
}
int main()
{
    struct node *root=NULL;
    int m,key;
    while(1)
    {
        printf("1:Insertion 2:Level order display 3:exit\n");
        scanf("%d",&m);
        if(m==1)
        {
            printf("Enter the data \n");
            scanf("%d",&key);
            root=insertion(root,key);
        }
        else if(m==2)
        {
            level_order(root);
        }
        else if(m==3)
        {
            exit(0);
        }
        else
        {
            printf("Invalid choice\n");
        }
    }
}
