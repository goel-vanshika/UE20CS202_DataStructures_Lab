#include"PES1UG20CS484_H.h"

void init(node *p[],int n)
{
	for(int i=0;i<n;i++)
		p[i]=NULL;
}

void init_queue(queue* pq)
{
	pq->f=0;
	pq->r=-1;
}

void init_stack(stack* ps)
{
	ps->top=-1;
}

void disp(int m[][10])
{
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
		{
			printf("%d\t",m[i][j]);
		}
		printf("\n");
	}

}

void create(int mat[][10], int *px1, int *py1, int *px2, int *py2,int *n,cdn *l)
{
	int i=0;
	int j=0;
	char ch;
	scanf("%d %d\n",px1,py1);
    	scanf("%d %d\n",px2,py2);
	while(i<10)
	{
        	while((ch=getchar())!=EOF && j<10)
        	{	
			if(ch=='0' || ch=='1')
            		{
				if(ch=='0')
				{
					l[*n].x=i;
					l[*n].y=j;
					*n=*n+1;
				}
 				mat[i][j]=ch-'0';
				j++;
			}
		}
		i++;
		j=0;
	}
}

int get_vid(cdn*l,int n,int x,int y)
{
	for(int i=0;i<n;i++)
		if(l[i].x==x && l[i].y==y) return i;
	return -1;
}

node* insertfront(node* q,cdn* l,int z)
{
	node *r=(node*)malloc(sizeof(node));
	r->x=l[z].x;
	r->y=l[z].y;
	r->n=z+1;
	r->next=q;
	return r;
}
	

void create_mat(node *p[],cdn *l,int n,int m[10][10])
{
	for(int i=0;i<n;i++)
	{
		if(l[i].x<9 && m[l[i].x+1][l[i].y]==0)
		{
			p[i]=insertfront(p[i],l,get_vid(l,n,l[i].x+1,l[i].y));
		}
		if(l[i].y<9 && m[l[i].x][l[i].y+1]==0)
		{
			p[i]=insertfront(p[i],l,i+1);
		}
	}
}

void disp_list(node *p[],int n)
{
	node *q;
	for(int i=0;i<n;i++)
	{
		if(p[i]!=NULL)
		printf("%d (%d,%d)\n",p[i]->n,p[i]->x,p[i]->y);
	}
}

void dfs(node *p[],int v,int d,int* visited,int* path,int r,cdn* l)
{
	visited[v]=1;
	path[r]=v;
	r=r+1;
	if(v==d)
	{
		printf("DFS Traversal: \n");
		printf("Start: \n");
		for(int i=0;i<r;i++)
		{
			printf("%d (%d,%d)\n",path[i],l[path[i]].x,l[path[i]].y);
		}
		printf("End.\n\n\n");
	}
	else
	{
		
		for(node* temp=p[v];temp!=NULL;temp=temp->next)
		{
			if(!visited[temp->n - 1]) dfs(p,temp->n-1,d,visited,path,r,l);
		}
	}

}

void bfs(node *p[],int n,int v,int d,int* visited,int* path,int c,cdn* l,queue* pq)
{
	pq->r++;
	pq->info[pq->r]=v;
	visited[v]=1;
	int a=v;
	
	while(pq->f<=pq->r)
	{
		a=pq->info[pq->f++];
		path[c++]=a;
		if(a==d) break;
		for(node* temp=p[a];temp!=NULL;temp=temp->next)
		{

			if(!visited[temp->n-1])
			{
				pq->r++;
				pq->info[pq->r]=temp->n-1;
				visited[temp->n-1]=1;
				
			}
		}
	}
	int b=c-1;
	while(b>0)
	{
		if(!(l[path[b]].x == l[path[b-1]].x || l[path[b]].y==l[path[b-1]].y))
		{
			path[b-1]=path[b];
			
		}
		b--;
	}
	printf("BFS Traversal: \n");		
	printf("Start: \n");
	b=-1;
	for(int i=0;i<c;i++)
	{
		if(b==-1 || path[b]!=path[i])
		{
			printf("%d (%d,%d)\n",path[i],l[path[i]].x,l[path[i]].y);
			b=i;
		}
	}
	printf("End.\n\n\n");
}	
