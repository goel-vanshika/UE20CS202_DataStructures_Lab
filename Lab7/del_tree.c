#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int info;
	struct node *llink;
	struct node *rlink;
}NODE;

typedef struct tree
{
	NODE *root;
}TREE;
void init(TREE *pt);
void create_t(TREE *pt);
void inorder_trav(NODE *p);
NODE* del(NODE *r,int el);

int main()
{
	TREE t;
	int el, choice;
	init(&t);
	create_t(&t);
	inorder_trav(t.root);
	printf("\nEnter choice 1:Display  2:Delete  0:Exit: ");
	scanf("%d",&choice);
	while(choice)
	{
	        switch(choice)
	        {
	                case 1:
	                        inorder_trav(t.root);
	                        break;
	                case 2:
	                        printf("Enter value of the element to be deleted(leaf level/sub-tree level/root level): ");
	                        scanf("%d",&el);
	                        t.root=del(t.root,el);
	                        printf("Post deletion:\n");
	                        inorder_trav(t.root);
	                        break;
	                case 0:
	                        exit(0);
	                        break;
	                default:
	                        printf("Invalid Choice.\n");
	                        break;
	        }
	        printf("\nEnter choice 1:Display  2:Delete  0:Exit: ");
			scanf("%d",&choice);
	}
	return 0;
}


void init(TREE *pt)
{
	pt->root=NULL;	
}

void create_t(TREE *pt)
{
	NODE *temp;
	NODE *pres;
	NODE *prev;
	int choice;
	pt->root=(NODE*)malloc(sizeof(NODE));
	pt->root->llink=pt->root->rlink=NULL;	
	printf("Enter root node: ");
	scanf("%d",&pt->root->info);
	do
	{
		temp=(NODE*)malloc(sizeof(NODE));
		temp->llink=temp->rlink=NULL;
		printf("Enter next node: ");
		scanf("%d",&temp->info);
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
		printf("Another node? 1:Yes  0:No: ");
		scanf("%d",&choice);
	}while(choice);	
}

void inorder_trav(NODE *p)
{
	if(p!=NULL)
	{
		inorder_trav(p->llink);
		printf("%d ",p->info);
		inorder_trav(p->rlink);
	}	
}


NODE* del(NODE *r,int el)
{
	NODE *temp, *p;
	if(r==NULL)
	{
		return r;
	} 
	else if(el<r->info)
	{
		r->llink=del(r->llink,el);
	}	
	else if(el>r->info)
	{
		r->rlink=del(r->rlink,el);
	}
	else
	{
		if(r->llink==NULL)
		{
			temp=r->rlink;
			free(r);
			return temp;
		}
		else if(r->rlink==NULL)
		{
			temp=r->llink;
		    free(r);
		    return temp;
		}
		else
		{        
			p=r->rlink;
			while(p->llink!=NULL)
			{
				p=p->llink;
			}
			r->info=p->info;
			r->rlink=del(r->rlink,p->info);
		}
	}
	return r;
}


