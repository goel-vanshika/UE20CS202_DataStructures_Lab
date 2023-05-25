#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 5

typedef struct deets
{
        char name[100];
        int day;
        int month;
        int year;
        int time;
}details;
        
typedef struct queue
{
	details a[MAX];
	int front;
	int rear;
}queue_t;

void init(queue_t *q);
int isEmpty(queue_t *q);
int isFull(queue_t *q);
void enqueue(queue_t *q);
void dequeue(queue_t *q);
void disp(queue_t *q);

int main()
{
	queue_t q;
	init(&q);
	int ele;
	int ch;	
	printf("\nAppointments are booked on a daily basis.\nEnter choice or 0 to exit:\n1.Book an appointment\n2.Display next appointment\n3.Display list of appointment\n");
	scanf("%d",&ch);
	while(ch)
	{
	        switch(ch)
	        {
		        case 1: 
			        	enqueue(&q);
			        	break;
		        case 2:
						dequeue(&q);
			        	break;
		        case 3:
						disp(&q);
			        	break;	
		        default:
						printf("Invalid choice\n");
	        }
			printf("\nAppointments are booked on a daily basis.\nEnter choice or 0 to exit:\n1.Book an appointment\n2.Display next appointment\n3.Display list of appointment\n");
	        scanf("%d",&ch);
	}
	return 0;
}
	
void init(queue_t *q)
{
	q->front=0;
	q->rear=-1;	
}

int isEmpty(queue_t *q)
{
	return q->front>q->rear;	
}

int isFull(queue_t *q)
{

	return q->rear==MAX-1;
}

void enqueue(queue_t *q)
{
        char name[100];
        int dd, mm, yy, time;
	if(isFull(q))
	{
		printf("Appointment Slots  are Full.Sorry.\n");
	}
    else if(q->rear==-1)
    {
        q->rear++;
		printf("Enter name:\n");
		scanf("%s", name);
		printf("Enter date.\n");
		printf("Enter Day: ");
		scanf("%d", &dd);
		printf("Enter month: ");
		scanf("%d",&mm);
		printf("Enter year: ");
		scanf("%d",&yy);
		printf("Enter time in HHMM format (24 hour):\n");
		scanf("%d", &time);
        strcpy(q->a[q->rear].name,name);
		q->a[q->rear].day=dd;
		q->a[q->rear].month=mm;
		q->a[q->rear].year=yy;
		q->a[q->rear].time=time;
    }
	else
	{
		printf("Enter name:\n");
		scanf("%s", name);
		printf("Enter date.\n");
		printf("Enter Day: ");
		scanf("%d", &dd);
		printf("Enter month: ");
		scanf("%d",&mm);
		printf("Enter year: ");
		scanf("%d",&yy);
		printf("Enter time in HHMM format (24 hour):\n");
		scanf("%d", &time);
		if(q->a[q->rear].day<dd|| q->a[q->rear].day>dd || q->a[q->rear].month!=mm || q->a[q->rear].year!=yy)
		{
		        printf("Slots are available on a daily basis only. (Book slots for %d/%d/%d)", q->a[q->rear].day,q->a[q->rear].month,q->a[q->rear].year);
		}
		else
		{
		        if(q->a[q->rear-1].time>time)
		        {
		                printf("Time not available. Try a later slot.\n");
		        }
		        else
		        {
						  q->rear++;
		                  strcpy(q->a[q->rear].name,name);
		                  q->a[q->rear].day=dd;
		                  q->a[q->rear].month=mm;
		                  q->a[q->rear].year=yy;
		                  q->a[q->rear].time=time;
		        }
		}
	}
}

void dequeue(queue_t *q)
{
	if(isEmpty(q))
	{
		printf("Empty\n");
		
	}
	else
	{
		printf("\nName: %s\n", q->a[q->front].name);
		printf("Date: %d/%d/%d\n", q->a[q->front].day,q->a[q->front].month,q->a[q->front].year);
		printf("Time: %d\n", q->a[q->front].time);
		q->front++;
	}	
}

void disp(queue_t *q)
{

	if(isEmpty(q))
		printf("Empty\n");
	else
	{
		for(int i=q->front;i<=q->rear;++i)
		{
			printf("\nName: %s\nDate: %d/%d/%d\nTime: %d",q->a[i].name,q->a[i].day,q->a[i].month, q->a[i].year, q->a[i].time);
		}
	}	
	
}
	
