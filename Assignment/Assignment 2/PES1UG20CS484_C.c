#include "PES1UG20CS484_F.c"
int main()
{
	queue q;
	init_queue(&q);
	stack s;
	init_stack(&s);
	int travel[10][10],x1,y1,x2,y2;
	int n=0;
	cdn l[100];
	create(travel,&x1,&y1,&x2,&y2,&n,l);
	node *p[n];
	init(p,n);
	create_mat(p,l,n,travel);
	int *path=(int*)calloc(n,sizeof(int));
	int *visited=(int*)calloc(n,sizeof(int));
	int src=get_vid(l,n,x1,y1);
	int dst=get_vid(l,n,x2,y2);
	dfs(p,src,dst,visited,path,0,l);
	free(visited);
	visited=(int*)calloc(n,sizeof(int)); //creating new list with all 0
	bfs(p,n,src,dst,visited,path,0,l,&q);
	return 0;
}
	
	