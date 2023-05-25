#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct car
{
    char lp[50];
    char status;
    int count;
}car;

typedef struct stack
{
    car q[8];
    int top;
}stack;

void init(stack *ps);
int push_arrive(stack *ps, char *lp, char s,int c);
int departure(stack *ps, stack *stktemp,char *lp);
int pop(stack *ps);

int main()
{
    stack s,s2;
    init(&s);
    init(&s2);
    char lp[50];
    char st;
    int wish;

    do
    {
        int c=0;
        printf("License Plate Number: ");
        scanf("%s",lp);
        fflush(stdin);
        printf("Arrival/Departure(A/D): ");
        scanf("%c",&st);
        switch(st)
        {
            case 'A':
                if(push_arrive(&s,lp,st,c))
                    printf("Space is available. The car of number %s has entered the garage.\n",lp);
                else
                    printf("Garage is Full.Sorry.\n");
                break;

            case 'D':
                departure(&s,&s2,lp);
                break;
            
            default:
                printf("Invalid choice \n");
                break;
        }
        printf("-------------------------------------------------------------------------\n");
        printf("Choose 1 to continue and 0 to exit: ");
        scanf("%d",&wish);
   }while(wish);
}

void init(stack *ps)
{
    ps->top=-1;
}

int push_arrive(stack *ps, char *lp, char s,int c)
{
    if(ps->top==7) 
    {
        return 0;
    }
    
    car *temp = (car*)malloc(sizeof(car));
    temp->count=c;
    strcpy(temp->lp,lp);
    temp->status=s;

    ps->top++;
    ps->q[ps->top]=*temp;
    return 1;
}

int departure(stack *ps, stack *stktemp,char *lp)
{
    if(ps->top==-1)
    {
        printf("No cars in the garage \n\r");
        printf("Empty.\n");
    }
    else
    {
        int p = ps->top;
        while(p!=-1)
        {
            if(strcmp(ps->q[p].lp,lp)==0)
            {
                break;
            }         
            p--;
        }
        if(p==-1)
        {
            printf ("Sorry.License plate %s not found \n\r",ps->q[p].lp); 
            return 0;
        }

        if(p==ps->top)
        {
            pop(ps);
            return 1;
        }

        for(ps->top; ps->top>p; (ps->top)--)
        {
            push_arrive(stktemp,ps->q[ps->top].lp,ps->q[ps->top].status,ps->q[ps->top].count++);
        }
        pop(ps);
   
        for(int i=(stktemp->top); i>-1; i--)
        {
            push_arrive(ps,stktemp->q[i].lp,stktemp->q[i].status,++(stktemp->q[i].count));
        }
        init(stktemp);
        return 0;
    }
    return 0;
}

int pop(stack *ps)
{
    printf("License plate : %s\n",ps->q[ps->top].lp);
    printf("Number of times car number %s has moved out of garage: %d\n",ps->q[ps->top].lp,ps->q[ps->top].count);
    (ps->top)--;
    return 1; 
}

