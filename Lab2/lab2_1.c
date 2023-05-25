#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int info;
    struct node *next;
}node;

typedef struct llist
{
    node* head;
}list;

void init(list *pl);
int read(list *pl,int e, int *s);
void display(list *pl,int *s);
void delete(list *pl);

int main()
{
    list l1;
    int e,wish,n1,n2,size =0;
    
    init(&l1);
    do
    {
        printf("Enter data: ");
        scanf("%d",&e);
        read(&l1,e,&size);
        printf("1. enter more terms: ");
        scanf("%d",&wish);
    }while(wish);

    printf("\n------------------------------\n");
    display(&l1,&size);
    printf("\n------------------------------\n");

    delete(&l1);
    printf("\n------------------------------\n");
    display(&l1,&size);
    
}

void init(list *pl)
{
    pl->head = NULL;
}

int read(list *pl,int e, int *s)
{
    node* temp = (node*)malloc(sizeof(node));
    temp->info = e;
    
    temp->next = pl->head;
    pl->head = temp;
    *s = *s +1;
    return 1; 
}

void display(list *pl,int *s)
{
    node* p  = pl->head;
    while(p != NULL)
    {
        printf("%d \t",p->info);
        p = p->next;
    }
    printf("size= %d",*s);
}


void delete(list *pl)
{
    node* p = pl->head;
    node* r;
    pl->head = p->next;
    while (p!=NULL)
    {
        r = p->next;
        printf("\n data deleted = %d \n",p->info);
        free(p);
        p = r->next;
        printf("loop");
    }
printf("out");
}
    
