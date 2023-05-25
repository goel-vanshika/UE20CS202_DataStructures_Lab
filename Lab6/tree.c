#include<stdio.h>
#include<stdlib.h>
#include <string.h>

typedef struct node
{
    int info;
    struct node*left;
    struct node*right;
   
}NODE;

typedef struct tree
{
    NODE* root;
}TREE;

void init(TREE*pt)
{
    pt->root=NULL;
}

void create(TREE*pt,int n)
{
   
    NODE*temp;
    NODE*pres;
    NODE*prev;
   	printf("Value of Root Node: ");
    pt->root=(NODE*)malloc(sizeof(NODE));
    scanf("%d",pt->root->info);
    pt->root->left=pt->root->right=NULL;
       
    do
    {
        printf("Input value of nodes: ");
        temp=(NODE*)malloc(sizeof(NODE));
        scanf("%d",(temp->info));
        temp->left=temp->right=NULL;
        prev=NULL;
        pres=pt->root;
    } while(n>0);
   
}

void preorder(TREE* pt, int r)
{
    if(pt[r].used)
    {
        printf("%d ",bst[r].info);
        preorder(bst,2*r+1);
        preorder(bst,2*r+2);
    }
}

int maxHeight(TREE* bst, int r)
{
    if (bst[r].used==0)
        return 0;
    else {
        int lHeight = maxHeight(bst, 2*r+1);
        int rHeight = maxHeight(bst, 2*r+2);
 
        if (lHeight > rHeight)
            return (lHeight + 1);
        else
            return (rHeight + 1);
    }
}

int main()
{
    TREE bst[MAXNODES];
    init(bst);
    create(bst);
    preorder(bst,0);
    int n = maxHeight(bst,0);
    printf("\nHeight of tree is %d and level of tree is %d\n", n-1, n);
    return 0;
}
