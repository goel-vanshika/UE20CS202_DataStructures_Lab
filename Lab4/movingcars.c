#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int lpn;
    int move;
    struct node* next;
}NODE;
typedef struct Garage
{
    NODE* top;
    int numcars;
}LL;
void init(LL *ps)
{
    ps->top=NULL;
    ps->numcars=0;
}
void push(LL *ps,int e)
{
    NODE* temp=(NODE*)malloc(sizeof(NODE));
    temp->lpn=e;
    temp->move=0;
    temp->next=ps->top;
    ps->top=temp;
    ps->numcars +=1;
    printf("The car %d has entered the garage\n",e);
}
void pop(LL *ps,int e)
{
    NODE* prev=NULL;
    NODE* temp;
    NODE *p=ps->top;
    while(p && (p->lpn!=e))
    {
        p->move +=1;
        prev=p;
        p=p->next;
    }
    if(!p)
    {
        printf("Car %d is not in the garage\n",e);
        return;
    }
    else if(!prev)
    {
        temp=ps->top;
        ps->top=temp->next;
    }
    else
    {
        temp=prev->next;
        prev->next=temp->next;
    }
    ps->numcars -=1;
    printf("Car %d moved %d times before leaving\n",temp->lpn,temp->move);
    free(temp);
}
int main()
{
    LL s;
    init(&s);
    char ch;
    int n;
    do
    {
        printf("Enter A for add a car\n");
        printf("Enter D to remove a car\n");
        printf("Enter X to Exit the program\n");
        scanf("%c",&ch);
        fflush(stdin);
        printf("Enter the license plate number of the car\n");
        scanf("%d",&n);
        fflush(stdin);
        switch(ch)
        {
            case 'A':if(s.numcars==8)
                        printf("The Garage is full sorry try later\n");
                     else
                        push(&s,n);
                     break;
            case 'D':if(s.top==NULL)
                        printf("The Garage is empty sorry\n");
                     else 
                        pop(&s,n);  
                     break;
            default : printf("Wrong choice try Again\n");
        }
    }
    while(ch!='X');
    return 0;
}