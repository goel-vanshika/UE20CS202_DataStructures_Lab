#include<stdio.h>
#include<stdlib.h>
#include <string.h>

typedef struct node
{
    char srn[13];
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
    scanf("%s",(pt->root->srn));
    pt->root->left=pt->root->right=NULL;
       
    do
    {
        printf("Input value of nodes: ");
        temp=(NODE*)malloc(sizeof(NODE));
        scanf("%s",(temp->srn));
        temp->left=temp->right=NULL;
        prev=NULL;
        pres=pt->root;
       
        while(pres!=NULL)
        {  
            prev=pres;
            if(strcmp(temp->srn,pres->srn)<0)
                pres=pres->left;
            else
                pres=pres->right;
        }
        if(strcmp(temp->srn,prev->srn)<0)
            prev->left=temp;
        else
            prev->right=temp;
         	--n;
    } while(n>0);
   
}

void inorder_traversal(NODE*p)
{
    if(p!=NULL)
    {
       
       
        inorder_traversal(p->left);
        printf("%s\n",p->srn);
        inorder_traversal(p->right);
    }
}


int search(NODE*p,char* ele,int*pe)
{
    int found=0;
    if(p!=NULL)
    {
        search(p->left,ele,pe);
        if(strcmp(p->srn,ele)==0)
        {

            found=1;
            *pe=1;
            return(found);
        }
        search(p->right,ele,pe);
    }
    //return(found);

}

int main()
{  
    TREE t;
    init(&t);
    printf("Number of nodes: ");
    int len,pe;
    scanf("%d",&len);
    create(&t,len-1);
    inorder_traversal(t.root);
    printf("SRN to be searched: ");
    char ele[13];
    scanf("%s",ele);
    search(t.root,ele,&pe);
    if(pe==1)
        printf("%s is found.\n",ele);
    else
        printf("Node not found\n");
   return 0;
   
}

