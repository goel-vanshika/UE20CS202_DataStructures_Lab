#include <stdio.h>
#include <stdlib.h>
#include <string.h>
    typedef struct Department
    {
        char name[100];
        int number;
    } Department;
    // struct defition for doubly linked list node
    typedef struct Node
    {
        char ssn[100];
        char name[100];
        Department department;
        char designations[100];
        int salary;
        int phone_number;
        int age;
        struct Node *next, *prev;
    } Node;
    // struct definition for employee
    typedef struct Employees 
    {
        Node *head;
    } Employees;

    void init(Employees *p);
    void disp(Employees *p);
    Node *create_node(char *ssn, char *name, char *dep_name, int dep_no, char *designation, int salary, int phn, int age);
    void insert_rec(Employees *p,char *ssn, char *name, char *dep_name, int dep_no, char *designation, int salary, int phn, int age);
    void disp_dept(Employees *p, char *dept);
    void age_grt_58(Employees *p);

int main()
{
    Employees l;
    init(&l);
    int ch;
    Department d[5]={{"Research", 1},{"HR",2},{"Accounts",3},{"Development",4},{"IT",5}};
        char name[100];
        char ssn[100];
        char dep_name[100];
        int dep_code;
        char designations[100];
        int salary;
        int phn;
        int age;
        int flag=0;
        printf("Enter your choice:\n1. Insert new record\n2. Display\n3. Display employees of a Department\n4. Delete all employee records with age above 58\nor 0 to exit: ");
        scanf("%d", &ch);
        while(ch)
        {
            flag=0;
        switch(ch)
        {
                case 1:
                        printf("Enter SSN: ");
                        scanf("%s", ssn);
                        printf("Enter Name: ");
                        scanf("%s", name);
                        printf("Enter Dept Name: ");
                        scanf("%s", dep_name);
                        printf("Enter Dept Code: ");
                        scanf("%d", &dep_code);
                        printf("Enter Designation: ");
                        scanf("%s", designations);
                        printf("Enter Salary: ");
                        scanf("%d", &salary);
                        printf("Enter Phone Number: ");
                        scanf("%d", &phn);
                        printf("Enter Age: ");
                        scanf("%d", &age);
                        for(int i=0;i<5;i++)
                        {
                            if(strcmp(d[i].name,dep_name)==0 && d[i].number==dep_code)
                            {
                                printf("Verified.");
                                flag=1;
                                break;
                            }
                        }
                        if(flag)
                        {
                            insert_rec(&l, ssn, name, dep_name, dep_code, designations, salary, phn, age);
                        }
                        else
                        {
                            printf("Department invalid.");
                        }
                        break;
                case 2:
                        disp(&l);
                        break;
                case 3:
                        printf("Enter Dept Name to display employees: ");
                        scanf("%s", dep_name);
                        disp_dept(&l,dep_name);
                        break;
                case 4:
                        age_grt_58(&l);
                        printf("The List after deleting records: ");
                        disp(&l);
                        break;
                case 0:
                       exit(0);
                       break;
               default:
                        printf("Invalid choice.");
                        break;
        }
       	printf("Enter your choice:\n1. Insert new record\n2. Display\n3. Display employees of a Department\n4. Delete all employee records with age above 58\nor 0 to exit: ");
        scanf("%d", &ch);
        }
        return 0;
}

void init(Employees *p)
{
    p->head=NULL;
}


void disp(Employees *p)
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
            printf("SSN: %s\nName: %s\nDept name: %s\nDept No: %d\nDesignation: %s\nSalary: %d\nPhone Number: %d\nAge: %d\n\n", pres->ssn, pres->name, pres->department.name, pres->department.number,pres->designations, pres->salary, pres->phone_number, pres->age);
            pres=pres->next;
        }
    }
}

Node *create_node(char *ssn, char *name, char *dep_name, int dep_no, char *designation, int salary, int phn, int age)
{
	Node *temp=(Node*)malloc(sizeof(Node));	
    strcpy(temp->ssn,ssn);
	strcpy(temp->name,name);
    strcpy(temp->department.name,dep_name);
    temp->department.number=dep_no;
    strcpy(temp->designations,designation);
    temp->salary=salary;
	temp->phone_number=phn;
    temp->age=age;
    temp->next=NULL;
    temp->prev=NULL;
	return temp;
}

void insert_rec(Employees *p,char *ssn, char *name, char *dep_name, int dep_no, char *designation, int salary, int phn, int age)
{
    Node *temp=create_node( ssn, name, dep_name, dep_no, designation, salary, phn, age);
    if(p->head==NULL)
    {
         //when list is empty
        p->head=temp;
    }
    else if(p->head->age>=age)
    {
        temp->next=p->head;
        p->head=temp;
    }
    else //list is not empty
    {
        Node *present=p->head;
        Node *bef=NULL;
        while(present->next!=NULL && present->next->age<age)
        {
            present=present->next;
        }
        temp->next=present->next;
        if(present->next!=NULL)
        {
            temp->next->prev=temp;
        }
        present->next=temp;
        temp->prev=present;
        
    }
}
/*
void age_grt_58(Employees *p)
{
    Node *pres=p->head;
    Node *front=NULL;
    int flag=0;
    if(p->head==NULL)
    {
        printf("Empty List\n");
    }
    else
    {
        while(pres!=NULL)
        {
            if (pres->age>=58)
                break;
            pres=pres->next;
        }
        while(pres!=NULL)
        {
            front=pres->next;
            pres->prev->next=NULL;
            free(pres);
            front->prev=NULL;
            pres=front;

        }       
    }
}
*/
void age_grt_58(Employees *p)
{
  Node *temp=p->head;
  while(temp!=NULL)
  {
    if(temp->age>58)
    {
      if(temp->prev==NULL)
      {
        temp=temp->next;
        p->head=temp;
        free(temp->prev);
        temp->prev=NULL;
      }
      else if(temp->next==NULL)
      {
        temp->prev->next=NULL;
        free(temp);
      }
      else{
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        free(temp);
      }
    }
    temp=temp->next;
  }
}
void disp_dept(Employees *p, char *dept)
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
            printf("SSN: %s\nName: %s\nDept name: %s\nDept No: %d\nDesignation: %s\nSalary: %d\nPhone Number: %d\nAge: %d\n\n", pres->ssn, pres->name, pres->department.name, pres->department.number,pres->designations, pres->salary, pres->phone_number, pres->age);
            pres=pres->next;
        }
    }
}
