#include<stdio.h>
#include<stdio.h>
#define max 10

void read_graph(int a[max][max], int n)
{
    for (int i=0; i<n; i++)
        for(int j=0; j<n;j++)
            scanf("%d", &a[i][j]);

}

void dfs(int src, int a[max][max], int v[max], int n)
{
   printf("DFS Traversal: ");
   printf("%d\t", src);
   v[src]=1;
   for (int i=0; i<n; i++)
        if(a[src][i] && !v[i])
                dfs(i,a,v,n);
   }

int main()
{
    int a[max][max]={0}, visited[max]={0}, n;
    printf("Enter the number of vertices\n");
    scanf("%d", &n);
    printf("Enter edges:\n");
    read_graph(a,n);

    
    int i;
    dfs(0, a, visited, n);
    
    for(i=0; i<n; i++)
        if(!visited[i])
            break;
    if(i<n)
        printf("Unconnected\n");
    else    
        printf("Connected\n");
    

}






