#include <stdio.h>
#include<stdlib.h>
#include<string.h>
struct details
{
    float marks[5];
    char subcode[5][10];
};
typedef struct details DET;
struct student  {
    char srn[14];
    char name[50];
    int sem;
    DET d;
};
typedef struct student STUD;
int main()
{
    STUD *s=(STUD*)malloc(sizeof(STUD));
    int c='Y';
    int i=0;
    char code[10];
    while(c=='Y')
    {
        printf("Enter the SRN: ");
        scanf("%s",(s+i)->srn);
        fflush(stdin);
        printf("Enter the Name: ");
        scanf("%s",(s+i)->name);
        fflush(stdin);
        printf("Enter the sem: ");
        scanf("%d",&((s+i)->sem));
        fflush(stdin);
        for(int j=0;j<5;j++)
        {
            printf("Enter the marks: ");
            scanf("%f",&((s+i)->d.marks[j]));

            printf("Enter the subject code: ");
            scanf("%s",((s+i)->d.subcode[j]));
            //printf("%s",(s+i)->d.subcode[j]);
            fflush(stdin);
        }
        printf("Do you wish to enter more data(Y/N): ");
        c=getchar();
        fflush(stdin);
        if(c=='Y')
        {
            i++;
            s=(STUD*)realloc(s,sizeof(STUD)*(i+1));
        }
    }
    printf("Enter the subject code you want average for: ");
    scanf("%s",code);
    fflush(stdin);
    float sum=0.0;
    int count=0;
    for(int j=0;j<=i;j++)
    {
        for(int k=0;k<5;k++)
        if(!strcmp((s+j)->d.subcode[k],code))
        {
            sum=sum+(s+j)->d.marks[k];
            count++;
        }

    }
    char t[100];
    printf("%f\n",(float)(sum/count));
    for(int j=0;j<i;j++)
    {
        for(int k=0;k<(i-j);k++)
        {
            if((strcmp((s+k)->srn,(s+k+1)->srn))>0)
            {
                strcpy(t,(s+k)->srn);
                strcpy((s+k)->srn,(s+k+1)->srn);
                strcpy((s+k+1)->srn,t);
            }
        }
    }
    printf("After sorting the students are: ");
    for(int j=0;j<=i;j++)
    {
        printf("%s\n",(s+j)->srn);
    }
    
    return 0;
}
