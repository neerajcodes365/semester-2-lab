#include<stdio.h>
#include<stdlib.h>

typedef struct bst {
    int key;
    struct bst *left, *right;
} node;

node* newNode(int item) {
    node* temp = (node*)malloc(sizeof(node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

node* insert(node* node, int key) {
    if (node == NULL) return newNode(key);
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    return node;
}
node* search(node* root, int key) {
    if (root == NULL || root->key == key)
       return root;
    if (root->key < key)
       return search(root->right, key);
    return search(root->left, key);
}
node* min(node* x) {
    node* current = x;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}
node* deleteNode(node* root, int key) {
    if (root == NULL) return root;
    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL) {
            node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            node* temp = root->left;
            free(root);
            return temp;
        }
        node* temp = min(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

void kthSmallest(node* root, int k, int* count) {
    if (root == NULL || *count >= k)
        return;
    kthSmallest(root->left, k, count);
    if (++(*count) == k) {
        printf("%d ", root->key);
        return;
    }
    kthSmallest(root->right, k, count);
}

node* maximum(node* x) {
    node* current = x;
    while (current->right != NULL)
        current = current->right;
    return current;
}

node* inOrderSuccessor(node* root,node* n) {
    if (n->right != NULL)
        return min(n->right);
    node* succ = NULL;
    while (root != NULL) {
        if (n->key < root->key) {
            succ = root;
            root = root->left;
        }
        else if (n->key > root->key)
            root = root->right;
        else
           break;
    }
    return succ;
}

int main() {
    node* root = NULL,*temp;
    char c;
    int num, k, count;
    do {
        scanf(" %c", &c);
        switch(c) {
            case 'i':
                scanf("%d", &num);
                root = insert(root, num);
                break;
            case 's':
                scanf("%d", &num);
                temp = search(root, num);
                if(temp != NULL)
                    printf("PRESENT\n");
                else
                    printf("NOT PRESENT\n");
                break;
            case 'd':
                scanf("%d", &num);
                temp = search(root, num);
                if(temp != NULL)root = deleteNode(root, num);
                else
                    printf("NOT PRESENT in the BST\n");
                break;
            case 'k':
                scanf("%d", &k);
                count = 0;
                kthSmallest(root, k, &count);
                printf("\n");
                break;
            case 'm':
                temp = maximum(root);
                printf("%d\n", temp->key);
                break;
            case 'n':
                scanf("%d", &num);
                temp = search(root, num);
                if(temp != NULL) {
                    node* succ = inOrderSuccessor(root, temp);
                    printf("%d\n", succ->key);
                }
                else
                    printf("NOT PRESENT in the BST\n");
                break;
            case 'e':
                break;
            default:
                printf("Invalid option\n");
        }
    } while(c != 'e');
    return 0;
}

