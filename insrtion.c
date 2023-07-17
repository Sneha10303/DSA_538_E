#include<stdio.h>
#include<stdlib.h>
struct tree
{
    int data;
    struct tree *left;
    struct tree *right;
};
struct tree *getNode(int key)
{
    struct tree *newnode;
    newnode=(struct tree*)malloc(sizeof(struct tree));
    newnode->data=key;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}
struct tree *insert_tree(struct tree *root,int key)
{
    struct tree *newnode=getNode(key);
    if(root==NULL)
    {
        root=newnode;
        return root;
    }
    if(key<root->data)
    {
        root->left=insert_tree(root->left,key);
    }
    else if(key>root->data)
    {
        root->right=insert_tree(root->right,key);
    }
    return root;
}
void inorder(struct tree *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}
int main()
{
    struct tree *root=NULL;
    int ch,key;
    while(1)
    {
        printf("\n1--insert\n");
        printf("2--display\n");

        printf("Enter your choice = ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1 : printf("Enter the tree \n");
                     scanf("%d",&key);
                     root=insert_tree(root,key);
                     break;
            case 2 : inorder(root);
                     break;
        }
    }
}
