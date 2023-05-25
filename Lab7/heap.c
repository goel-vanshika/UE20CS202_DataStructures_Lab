#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
        int info;
        int prio;
}node;
int main()
{
node h[50];
node ele;
int n,i,j,k,heap,p,c;
printf("Enter the number of elements in priority queue: ");
scanf("%d",&n);

for(i=0; i<n; i++)
{
       printf("Enter the information: ");
       scanf("%d",&h[i].info);
       printf("Enter the priority: ");
       scanf("%d",&h[i].prio);
}
//display
for(i=0; i<n; i++)
{
       printf("Data: ");
       printf("%d",h[i].info);
       printf("\nPriority: ");
       printf("%d",h[i].prio);
       printf("\n");
}




for(i=(n/2)-1; i>=0; i--)
{
       k=i;
       ele=h[k];
       heap=0;
       
       while(!heap&&(2*k+1<=n-1))
       {
               j=2*k+1;
               if(j+1<=n-1)
               {
                       if(h[j+1].prio>h[j].prio)
                       {
                               j+j+1;
                       }
               }
               if(ele.prio>h[j].prio)
               {
                       heap=1;
               }
               else
               {
                       h[k]=h[j];
                       k=j;
               }  
        }
        h[k]=ele;
}
for(i=n-1;i>0;i--)
{
       ele=h[i];
       h[i]=h[0];
       p=0;
       if(i==1)
               c=-1;
       else
               c=1;
       if((i>2)&&h[2].prio>h[1].prio)
               c=2;
       while(c>=0&&ele.prio<h[c].prio)
       {
               h[p]=h[c];
               p=c;
               c=2*p+1;
               if(c+1<=i-1&&h[c+1].prio>h[c].prio)
                       c=c+1;
               if(c>i-1)
                       c=-1;
       }
       h[p]=ele;
}
printf("Deletion of element of highest priority: ");
//display
for(i=0; i<1; i++)
{
       printf("Info: ");
       printf("%d",h[i].info);
       printf("\nPrio: ");
       printf("%d",h[i].prio);
       printf("\n");
}
}
