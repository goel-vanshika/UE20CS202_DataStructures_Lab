#include<stdio.h>
#include<stdlib.h>

typedef struct coord
{
	int x;
	int y;
}cdn;

typedef struct nod	e
{
	int x;
	int y;
	int n;
	struct node *next;
}node;

typedef struct stack
{
	int info[100];
	int top;
}stack;

typedef struct queue
{
	int info[100],f,r;
}queue;

void init(node *p[],int n);
void init_queue(queue* pq);
void init_stack(stack* ps);
void disp(int m[][10]);
void create(int mat[][10], int *px1, int *py1, int *px2, int *py2,int *n,cdn *l);
int get_vid(cdn*l,int n,int x,int y);
node* insertfront(node* q,cdn* l,int z);
void create_mat(node *p[],cdn *l,int n,int m[10][10]);
void disp_list(node *p[],int n);
void dfs(node *p[],int v,int d,int* visited,int* path,int r,cdn* l);
void bfs(node *p[],int n,int v,int d,int* visited,int* path,int c,cdn* l,queue* pq);

