#include<stdio.h>
#define max 10

void read_graph(int a[max][max], int n)
{
    for (int i=0; i<n; i++)
        for(int j=0; j<n;j++)
            scanf("%d", &a[i][j]);

}

void bfs(int a[max][max], int q[max], int v[max], int n, int f, int r)
{
    int x;
    while(f<=r)
    {
        x=q[f++];
        printf("BFS Traversal is: ");
        printf("%d \t", x);
        for(int i=0; i<n; i++)
            if(a[x][i] && !v[i])
            {
                q[++r]=i;
                v[i]=1;
            }
    }
}

int main()
{
    int a[max][max]={0}, visited[max]={0}, q[max], n, f=0, r=-1;
    printf("Enter the number of vertices\n");
    scanf("%d", &n);
    printf("Enter the edges\n");
    read_graph(a,n);

    q[++r]=0;
    visited[0]=1;
    bfs(a,q,visited,n, f,r);

}


