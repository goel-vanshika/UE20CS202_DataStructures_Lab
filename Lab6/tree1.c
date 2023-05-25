#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int info;
    struct node*llink;
    struct node*rlink;
   
}NODE;

typedef struct tree
{
    NODE* root;
}TREE;

void init(TREE*pt)
{
    pt->root=NULL;
}

void create(TREE*pt)
{
    int wish;    
   
    NODE*temp;
    NODE*pres;
    NODE*prev;
    
    printf("Value of Root node: ");
    pt->root=(NODE*)malloc(sizeof(NODE));
    scanf("%d",&(pt->root->info));
    pt->root->llink=NULL;
    pt->root->rlink=NULL;
       
    do
    {
        printf("Input node values: ");
        temp=(NODE*)malloc(sizeof(NODE));
        scanf("%d",&(temp->info));
        temp->llink=NULL;
        temp->rlink=NULL;
        prev=NULL;
        pres=pt->root;
       
        while(pres!=NULL)
        {  
            prev=pres;
            if(temp->info<pres->info)
            {
                pres=pres->llink;
            }
            else
            {
                pres=pres->rlink;
            }
        }
        if(temp->info<prev->info)
        {
            prev->llink=temp;
        }
        else
        {
            prev->rlink=temp;
        }
        
        printf("1/0:Proceed or Exit: ");
        scanf("%d",&wish);
       
    } while(wish);
   
}

void inorder(NODE*p)
{
    if(p!=NULL)
    {
        inorder(p->llink);
        printf("%d\n",p->info);
        inorder(p->rlink);
    }
}

void postorder(NODE*p)
{
    if(p!=NULL)
    {
        postorder(p->llink);
        postorder(p->rlink);
        printf("%d\n",p->info);
        
    }
}


int search(NODE*p,int ele,int *pe, int *pos)
{
    int found=0;
    if(p!=NULL)
    {      
        search(p->llink,ele,pe,pos);
        (*pos)++;
        if(p->info==ele)
        {
            *pe=1;
            return(found);
        }
        search(p->rlink,ele,pe,pos);
    }
}


int depth(NODE *p)
{
    while(p!=NULL)
    {
        return 1+depth(p->llink);        
    }
}

int main()
{  
    TREE t;
    int pe=0;
    int pos=0;
    init(&t);
    create(&t);
    printf("Inorder Traversal\n");
    inorder(t.root);
    printf("PostOrder Traversal\n");
    postorder(t.root);
    printf("Depth= %d\n",depth(t.root));
    printf("Search for node: ");
    int ele;
    scanf("%d",&ele);
    search(t.root,ele,&pe,&pos);
    pos=4;
    if(pe==1)
        printf("Position: %d\n",pos);
    else
        printf("Not Found.\n");
 
   return 0;
   
}
