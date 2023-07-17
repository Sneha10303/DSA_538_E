#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct TreeNode
{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;
TreeNode* createNode(int data)
{
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
TreeNode* insertNode(TreeNode* root, int data)
{
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data >=root->data) {
        root->right = insertNode(root->right, data);
    }
    return root;
}
void printElements(TreeNode* root)
{
    if (root != NULL)
        {
        printf("%d ", root->data);
        printElements(root->left);
        printElements(root->right);
    }
}

void storeElements(TreeNode* root, FILE* file) {
    if (root != NULL) {
        fprintf(file, "%d ", root->data);
        storeElements(root->left, file);
        storeElements(root->right, file);
    }
}
int getTreeHeight(TreeNode* root) {
    if (root == NULL) {
        return 0;
    } else {
        int leftHeight = getTreeHeight(root->left);
        int rightHeight = getTreeHeight(root->right);
        return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
    }
}

int* countElementsAtEachLevel(TreeNode* root, int height) {
    int* count = (int*)calloc(height, sizeof(int));
    countElementsAtLevel(root, count, 0);
    return count;
}

void countElementsAtLevel(TreeNode* root, int* count, int level) {
    if (root != NULL) {
        count[level]++;
        countElementsAtLevel(root->left, count, level + 1);
        countElementsAtLevel(root->right, count, level + 1);
    }
}

void printTreePattern(TreeNode* root, int level) {
    if (root == NULL) {
        return;
    }

    printTreePattern(root->right, level + 1);

    for (int i = 0; i < level; i++) {
        printf("\t");
    }

    printf("%d\n", root->data);

    printTreePattern(root->left, level + 1);
}


int main() {
     FILE* fp = fopen("input1.txt", "w");

    if (fp == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }

    srand(time(NULL));

    int i;
    for (i = 0; i < 6; i++) {
        int randomNumber = rand() % 100;
        fprintf(fp, "%d\n", randomNumber);
    }

    fclose(fp);

    FILE* input1 = fopen("input1.txt", "r");
    if (input1 == NULL) {
        printf("Error opening the input file.\n");
        return 1;
    }

    TreeNode* root = NULL;

    int number;
    while (fscanf(input1, "%d", &number) == 1) {
        root = insertNode(root, number);
    }
   fclose(input1);


   FILE* output1 = fopen("output1.txt", "w");
    if (output1 == NULL) {
        printf("Error opening the output file.\n");
        return 1;
    }

    storeElements(root, output1);


    printf("Elements of the Binary Tree: ");
    printElements(root);

    int h=getTreeHeight(root);
    printf("\n \n The height of tree is  %d",h);



    int* elementCounts = countElementsAtEachLevel(root, h);
        printf("Number of Elements at Each Level:\n");
    for (int level = 0; level < h; level++) {
        printf("Level %d: %d elements\n", level, elementCounts[level]);
    }

    free(elementCounts);
    input1 = fopen("input1.txt", "r");
    printf("Binary Tree Pattern:\n");
    printTreePattern(root, 0);

    return 0;



}
