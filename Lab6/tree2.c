#include<stdio.h>
typedef struct tree_node
{
    int info;
    int used;
}TREE;

#define MAXNODES 50

void init(TREE t[MAXNODES])
{
    for(int i=0;i<MAXNODES;i++)
    t[i].used=0;
}

void create(TREE *bst)
{
    int ele, wish;
    printf("Enter the root element\n");
    scanf("%d",&bst[0].info);
    bst[0].used=1;
    do
    {
        printf("Enter an element\n");
        scanf("%d",&ele);
        int p=0;
        while(p<MAXNODES && bst[p].used)
        {
            if(ele<bst[p].info)
                p=2*p+1;
            else
                p=2*p+2;
        }
        if(p>=MAXNODES)
            printf("Insertion not possible\n");
        else
        {
            bst[p].info=ele;
            bst[p].used=1;
        }
        printf("Do you wish to add another\n");
        scanf("%d",&wish);
    }while(wish);
}
int search(TREE*bst,char* ele,int*pe)
{
    int found=0;
    if(p!=NULL)
    {
        search(bst,ele,pe);
        if(strcmp(p->srn,ele)==0)
        {

            found=1;
            *pe=1;
            return(found);
        }
        search(bst,ele,pe);
    }
    //return(found);

}
void preorder(TREE* bst, int r)
{
    if(bst[r].used)
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
