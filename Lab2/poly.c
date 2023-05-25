#include<stdio.h>
#include<stdlib.h>


typedef struct node
{
	int coeff;
	int px;
	int py;
	struct node* next;
}NODE;

typedef struct poly
{
	NODE *head;
}POLY;

void init(POLY* p);
void read(POLY* p);
void disp(POLY* p);
void add(POLY* p1, POLY* p2, POLY* sum);

int main()
{
	POLY p1;
	POLY p2;
	POLY sum;
	init(&p1);
	init(&p2);
	printf("Enter first polynomial expression:\n");
	read(&p1);
	disp(&p1);
	printf("***********************************************\n");
	printf("Enter second polynomial expression:\n");
	read(&p2);
	disp(&p2);
	printf("***********************************************\n");
	add(&p1,&p2,&sum);
	disp(&sum);
}

void init(POLY* p)
{
	p->head = NULL;
}

void read(POLY* p)
{
	NODE* temp = (NODE*)malloc(sizeof(NODE));
	p->head = temp;
	int wish;
	do
	{
		printf("Enter coefficient of term:\n");
		scanf("%d",&temp->coeff);
		printf("Enter power of x:\n");
		scanf("%d",&temp->px);
		printf("Enter power of y:\n");
		scanf("%d",&temp->py);
		printf("Do you want to add another term?(1/0)\n");
		scanf("%d",&wish);
		if(wish)
		{
			temp->next=(NODE*)malloc(sizeof(NODE));
			temp = temp->next;
			temp->next = NULL;
		}
	}while(wish);
}

void disp(POLY* p)
{
	NODE* q = p->head;
	printf("Polynomial Expression is:\n");
	while(q!=NULL)
	{
		printf("%dx^%dy^%d",q->coeff,q->px,q->py);
		q=q->next;
		if(q!=NULL)
		{
			printf(" + ");
		}
	}
	printf("\n");
}
void add(POLY* p1, POLY* p2, POLY* sum)
{
	NODE* temp = (NODE*)malloc(sizeof(NODE));
	NODE* first = p1->head;
	NODE* second = p2->head;
	NODE* s = sum->head;
	temp->next = NULL;
	sum->head = temp;
	while(first!=NULL && second!=NULL)
	{
		if((first->px == second->px) && (first->py == second->py))
		{
			temp->coeff = first->coeff + second->coeff;
 			temp->px = first->px;
 			temp->py = first->py;
 			first = first->next;
 			second = second->next;
		}

		else if((first->px+first->py)>(second->px+second->py))
		{
			temp->coeff = first->coeff;
 			temp->px = first->px;
 			temp->py = first->py;
 			first = first->next;
		}
		else if((first->px+first->py)<(second->px+second->py))
		{
			temp->coeff = second->coeff;
 			temp->px = second->px;
 			temp->py = second->py;
 			second = second->next;
		}
		if(first!=NULL && second!=NULL)
		{
			temp->next = (NODE*)malloc(sizeof(NODE));
			temp = temp->next;
			temp->next = NULL;
		}
	}
	while(first!=NULL || second!=NULL)
	{
		temp->next = (NODE*)malloc(sizeof(NODE));
		temp = temp->next;
		temp->next = NULL;
		if(first!=NULL)
		{
			temp->coeff = first->coeff;
			temp->px = first->px;
			temp->py = first->py;
			first = first->next;
		}
		else if(second!=NULL)
		{
			temp->coeff = second->coeff;
			temp->px = second->px;
			temp->py = second->py;
			second = second->next;
		}
	}
}





















