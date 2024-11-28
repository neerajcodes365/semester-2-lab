#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};
typedef struct node node;

node *newnode(int num)
{
    node *ptr = (node *)malloc(sizeof(node));
    ptr->data = num;
    ptr->left = ptr->right = NULL;
    return ptr;
}

node *insertkey(node *root, int num)
{
    if (root == NULL)
        return newnode(num);

    if (num > root->data)
        root->right = insertkey(root->right, num);
    else if (num < root->data)
        root->left = insertkey(root->left, num);

    return root;
}

void searchkey(node *root, int num)
{
    node *ptr = root;
    while (ptr != NULL)
    {
        if (ptr->data == num)
        {
            printf("PRESENT\n");
            return;
        }
        if (ptr->data > num)
            ptr = ptr->left;
        else
            ptr = ptr->right;
    }
    printf("NOT PRESENT\n");
}

node *minValue(node *root)
{
    node *ptr = root;
    while (ptr != NULL && ptr->left != NULL)
    {
        ptr = ptr->left;
    }
    return ptr;
}

node *deletekey(node *root, int num)
{
    if (root == NULL)
    {
        printf("NOT PRESENT\n");
        return root;
    }

    if (num < root->data)
        root->left = deletekey(root->left, num);
    else if (num > root->data)
        root->right = deletekey(root->right, num);
    else
    {
        if (root->left == NULL)
        {
            node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            node *temp = root->left;
            free(root);
            return temp;
        }

        node *temp = minValue(root->right);
        root->data = temp->data;
        root->right = deletekey(root->right, temp->data);
    }
    return root;
}

void inorder(node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main()
{
    int num;
    char choice;
    node *root = NULL;
    do
    {
        scanf(" %c", &choice);
        switch (choice)
        {
        case 'i':
            scanf("%d", &num);
            root = insertkey(root, num);
            break;
        case 's':
            scanf("%d", &num);
            searchkey(root, num);
            break;
        case 'd':
            scanf("%d", &num);
            root = deletekey(root, num);
            break;
        case 'p':
            if (root == NULL)
            {
                printf("NULL\n");
                break;
            }
            else
            {
                inorder(root);
                printf("\n");
                break;
            }
        case 't':
            if (root == NULL)
            {
                printf("NULL\n");
                break;
            }
            else
            {
                preorder(root);
                printf("\n");
                break;
            }
        case 'b':
            if (root == NULL)
            {
                printf("NULL\n");
                break;
            }
            else
            {
                postorder(root);
                printf("\n");
                break;
            }
        case 'e':
            break;
        }
    } while (choice != 'e');

    return 0;
}
