#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct match
{
    char played[15];
    int runs[14];
};
typedef struct match MATCH;
struct ipl
{
    char player_name[50];
    char team_name[50];
    MATCH dets;
};
typedef struct ipl IPL;
int main()
{
    int c='y';
    int i=0;
    IPL *s=(IPL*)malloc(sizeof(IPL));
    while(c=='y')
    {
        printf("Enter the name of player: \n");
        scanf("%s",(s+i)->player_name);
        fflush(stdin);
        printf("Enter the name of team: \n");
        scanf("%s",(s+i)->team_name);
        fflush(stdin);
        for(int j=0;j<10;j++)
        {
            printf("Did the player play in match %d? \n",j+1);
            printf("Enter y/n: \n");
            scanf("%c",&((s+i)->dets.played[j]));
            fflush(stdin);
            if((s+i)->dets.played[j]=='y')
            {
                printf("Enter the runs scored by the player: \n");
                scanf("%d",&((s+i)->dets.runs[j]));
                fflush(stdin);
            }
            else
                (s+i)->dets.runs[j]=-1;
        }
        printf("Do you wish to enter more data: \n");
        printf("Enter y/n: \n");
        c=getchar();
        fflush(stdin);
        if(c=='y')
        {
            i++;
            s=(IPL*)realloc(s,sizeof(IPL)*(i+1));
        }
    }
    int max=-1;
    int match_n;
    printf("Enter the match number for calculation of max: \n");
    scanf("%d",&match_n);
    match_n--;
    int index=-1;
    for(int j=0;j<=i;j++)
    {
        if((s+j)->dets.runs[match_n]>max)
        {
            max=(s+j)->dets.runs[match_n];
            index=j;
        }
    
    }
    if(max==-1)
    {
        printf("No player played that match. \n");
    }
    else
    {
        printf("The player is %s who scored %d in match %d. \n",(s+index)->player_name,max,++match_n);
    }
    int count=0;
    for(int j=0;j<=i;j++)
    {   
        count=0;
        for(int k=0;k<14;k++)
        {
            if((s+j)->dets.played[k]=='y')
                count++;
        }
        printf("Player %s played %d matches. \n",(s+j)->player_name,count);
    }
    return 0;
}