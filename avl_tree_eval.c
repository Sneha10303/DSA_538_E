#include <stdio.h>
#include <stdlib.h>
#define COUNT 5

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    int ht;
};
int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}
int getht(struct Node *node)
{
    if (node == NULL)
        return 0;
    return node->ht;
}

struct Node *createNode(int data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->ht = 1;
    return node;
}
struct Node *rt_rot(struct Node *y)
{
    struct Node *x = y->left;
    struct Node *T2 = x->right;
    x->right = y;
    y->left = T2;
    y->ht = max(getht(y->left), getht(y->right)) + 1;
    x->ht = max(getht(x->left), getht(x->right)) + 1;
    return x;
}
struct Node *lt_rot(struct Node *x)
{
    struct Node *y = x->right;
    struct Node *T2 = y->left;
    y->left = x;
    x->right = T2;
    x->ht = max(getht(x->left), getht(x->right)) + 1;
    y->ht = max(getht(y->left), getht(y->right)) + 1;
    return y;
}
int bal(struct Node *node)
{
    if (node == NULL)
        return 0;
    return getht(node->left) - getht(node->right);
}
struct Node *insertNode(struct Node *node, int data)
{
    if (node == NULL)
        return createNode(data);

    if (data < node->data)
        node->left = insertNode(node->left, data);
    else if (data > node->data)
        node->right = insertNode(node->right, data);
    else
        return node;
    node->ht = 1 + max(getht(node->left), getht(node->right));

    int b = bal(node);
    if (b > 1 && data < node->left->data)
        return rt_rot(node);
    if (b < -1 && data > node->right->data)
        return lt_rot(node);
    if (b > 1 && data > node->left->data)
    {
        node->left = lt_rot(node->left);
        return rt_rot(node);
    }
    if (b < -1 && data < node->right->data)
    {
        node->right = rt_rot(node->right);
        return lt_rot(node);
    }
    return node;
}
struct Node *min_val(struct Node *node)
{
    struct Node *current = node;

    while (current->left != NULL)
        current = current->left;

    return current;
}
struct Node *deleteNode(struct Node *root, int data)
{
    if (root == NULL)
        return root;

    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else
    {
        if (root->left == NULL || root->right == NULL)
        {
            struct Node *temp = root->left ? root->left : root->right;
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
            *root = *temp;
            free(temp);
        }
        else
        {
            struct Node *temp = min_val(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    if (root == NULL)
        return root;
    root->ht = 1 + max(getht(root->left), getht(root->right));

    int b = bal(root);

    if (b > 1 && bal(root->left) >= 0)
        return rt_rot(root);

    if (b > 1 && bal(root->left) < 0)
    {
        root->left = lt_rot(root->left);
        return rt_rot(root);
    }

    if (b < -1 && bal(root->right) <= 0)
        return lt_rot(root);

    if (b < -1 && bal(root->right) > 0)
    {
        root->right = rt_rot(root->right);
        return lt_rot(root);
    }
    return root;
}
void displayTree(struct Node *root)
{
    if (root != NULL)
    {
        displayTree(root->left);
        printf("%d ", root->data);
        displayTree(root->right);
    }
}

void print2DUtil(struct Node* root, int space)
{
	if (root == NULL)
		return;
	space += COUNT;
	print2DUtil(root->right, space);
	for (int i = COUNT; i < space; i++)
		printf(" ");
	printf("%d\n", root->data);
	print2DUtil(root->left, space);
}
void print2D(struct Node* root)
{
	print2DUtil(root, 0);
}
int main()
{
    struct Node *root = NULL;
    int choice, data;
    FILE *file;


    while (1)
    {
        printf("\n1--Random num generation\n");
        printf("2--insert a node\n");
        printf("3--Delete a node\n");
        printf("4--Display tree\n");
        printf("5--Display the tree like structure of avl tree\n");
        printf("0--Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                file = fopen("numbers.txt", "w");
                if (file == NULL)
                {
                    printf("Error opening the file.\n");
                    return 1;
                }

                int numCount;
                printf("Enter the number of random numbers to generate: ");
                scanf("%d", &numCount);

                printf("Generated numbers: ");
                for (int i = 0; i < numCount; i++)
                {
                    int num = rand() % 100;
                    printf("%d ", num);
                    fprintf(file, "%d\n", num);
                }

                fclose(file);
                printf("\nNumbers successfully stored in the file.\n");
                break;

            case 2:
                file = fopen("numbers.txt", "r");
                if (file == NULL)
                {
                    printf("Error opening the file.\n");
                    return 1;
                }

                while (fscanf(file, "%d", &data) != EOF)
                    root = insertNode(root, data);

                fclose(file);
                printf("Numbers successfully inserted as nodes in the AVL tree.\n");
                break;

            case 3:
                printf("Enter the node to delete: ");
                scanf("%d", &data);
                root = deleteNode(root, data);
                printf("Node successfully deleted from the AVL tree.\n");
                break;

            case 4:
                printf("Tree structure:\n");
                displayTree(root);
                printf("\n");
                break;

            case 5: print2D(root);
                break;

            case 0:
                printf("Exiting the program.\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}

