#include<stdio.h>
#include<stdlib.h>
typedef struct bst{
    struct bst* left,*right;
    int key;
}node;
node* buildTree(char *str, int *pos) {
    if (str[*pos] == '('){
        (*pos)+=2;
        if (str[*pos]==')') {
            (*pos)+=2;
            return NULL;
        }
        int num = 0;
        while (str[*pos]>='0' && str[*pos]<='9') {
            num=num*10+(str[*pos]-'0');
            (*pos)++;
        }
        if(str[*pos]==' ')
        (*pos)++;
        node* newnode=(node*)malloc(sizeof(node));
        newnode->key=num;
        newnode->left=buildTree(str, pos);
        newnode->right=buildTree(str, pos);
        (*pos)+=2;
        return newnode;
    }
    return NULL;
}
node* search(node* root,int x){
    if(root==NULL || root->key==x)
    return root;
    node* left=search(root->left,x);
    node* right=search(root->right,x);
    if(left!=NULL)
    return left;
    else
    return right;
}
void print(node* root,int k,int depth){
    if(root==NULL)
    return;
    if(depth==k)
    printf("%d ",root->key);
    print(root->left,k,depth+1);
    print(root->right,k,depth+1);
}
int main(){
    char expr[500];
    fgets(expr,500,stdin);
    int x,k,pos=0;
    scanf("%d%d",&x,&k);
    node* root=buildTree(expr,&pos);
    node* X=search(root,x);
    print(X,k,0);
}
