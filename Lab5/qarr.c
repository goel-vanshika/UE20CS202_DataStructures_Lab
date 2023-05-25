#include<stdio.h>
#include<stdlib.h>
#define MAX 50

typedef struct queue
{
    int q[MAX];
    int f,r;
}QUEUE;

void init(QUEUE *pq);
int isEmpty(QUEUE *pq);
int enqueue(QUEUE *pq, int e);
int dequeue(QUEUE *pq, int *pe);
void disp(QUEUE *pq);

int main()
{
    int choice,e,k;
    QUEUE q;
    init(&q);
    do
    {
        printf("Enter choice: 1.Enqueue 2.Dequeue 3.isEmpty 4.Display: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter element: ");
                scanf("%d",&e);
                k=enqueue(&q,e);
                if(!k)
                {
                    printf("Overflow\n");
                }
                else
                {
                    printf("Success.\n");
                }
                break;
            case 2:
                printf("Enter element: ");
                scanf("%d",&e);
                k=dequeue(&q,&e);
                if(!k)
                {
                    printf("Overflow\n");
                }
                else
                {
                    printf("Success.\n");
                }
                break;
            case 3:
                isEmpty(&q);
                break;
            case 4:
                disp(&q);
                break;       
                    
        }
    }
    while(choice);
}

void init(QUEUE *pq)
{
    pq->f=0;
    pq->r=-1;
}

int isEmpty(QUEUE *pq)
{
    return(pq->f>pq->r);
}

int enqueue(QUEUE *pq, int e)
{
    if(pq->r==MAX-1)
        return 0;
    else
    {
        pq->r++;
        pq->q[pq->r]=e;
        return 1;
    }    
}

int dequeue(QUEUE *pq, int *pe)
{
    if(isEmpty(pq))
        return 0;
    else
    {
        *pe=pq->q[pq->f];
        pq->f++;
        if(isEmpty(pq))
        {
            init(pq);
        }
        return 1;       
    }    
}

void disp(QUEUE *pq)
{
    int i;
    for(int i=pq->f; i<=pq->r; i++)
    {
        printf("%d\t",pq->q[i]);
        
    }
    printf("\n");
}
