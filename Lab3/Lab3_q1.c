#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node
{
        char name[100];
        int phone_number;
        char address[500];
        char area[100];
        struct Node *next, *prev;
} Node;


typedef struct CustomerDetails
{
        Node *head;
} CustomerDetails;

void init(CustomerDetails *p);
void disp(CustomerDetails *p);
Node *create_node(char *name, int pn, char *address, char *area);
void insert_rec(CustomerDetails *p,char *name, int pn, char *address, char *area);

int main()
{
        CustomerDetails l;
        init(&l);
        int ch;
        char name[100];
        char address[500];
        char area[100];
        int phn;
        printf("Enter your choice:1. Insert new record 2. Display or 0 to exit: ");
        scanf("%d", &ch);
        while(ch)
        {
        switch(ch)
        {
                case 1:
                        printf("Enter name: ");
                        scanf("%s", name);
                        printf("Enter phone number: ");
                        scanf("%d", &phn);
                        printf("Enter address: ");
                        scanf("%s",address);
                        printf("Enter area: ");
                        scanf("%s",area);
                        insert_rec(&l, name, phn, address, area);
                        break;
                case 2:
                        disp(&l);
                        break;
                case 0:
                       exit(0);
                       break;
               default:
                        printf("Invalid choice\n");
                        break;
        }
        printf("Enter your choice:1. Insert new record 2. Display or 0 to exit: ");
        scanf("%d", &ch);
        }
        return 0;
        
}


void init(CustomerDetails *p)
{
    p->head=NULL;
}


void disp(CustomerDetails *p)
{
    Node *pres=p->head;
    if(p->head==NULL)
    {
        printf("Empty List\n");
    }
    else
    {
    while(pres!=NULL)
    {
        printf("Name: %s\nPhone number: %d\nAddress: %s\nArea: %s\n\n", pres->name, pres->phone_number, pres->address, pres->area);
        pres=pres->next;
    }
    }
}


Node *create_node(char *name, int pn, char *address, char *area)
{
	Node *temp=(Node*)malloc(sizeof(Node));	
	strcpy(temp->name,name);
	temp->phone_number=pn;
	strcpy(temp->address,address);
	strcpy(temp->area,area);
	temp->next=NULL;
        temp->prev=NULL;
	return temp;
}

void insert_rec(CustomerDetails *p,char *name, int pn, char *address, char *area)
{
    Node *temp=create_node(name, pn, address, area);
    if(p->head==NULL) //when list is empty
        p->head=temp;
    else //list is not empty
    {
        Node *present=p->head;
        Node *bef=NULL;
        while(present!=NULL && strcmp(present->name, name)<0)
        {
            bef=present;
            present=present->next;
        }
        if(bef==NULL) //front insertion
        {
            p->head=temp;
            temp->next=present;
            present->prev=temp;
        }
        else //middle and end insertion
        {
            temp->next=present;
            present->prev=temp;
            bef->next=temp;
            temp->prev=bef;
        }
    }
}

