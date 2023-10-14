#include <stdio.h>

#include<string.h>

struct input

{

    char Pname[10];

    int bt,at,tbt,ft;

} tab [10];

struct gantt

{

    int start,end;

    char Pname[10];

} g[50],g1[10];

int n,i,k,time,prev;

void getinput()

{

    printf("\nEnter no of process: ");

    scanf("%d",&n);

    for(i=0;i<n;i++)
    {

        printf ("\n process Name :");

        scanf("%s",tab[i].Pname);

        printf("Burst time:");

        scanf("%d",& tab[i].bt);

        tab[i].tbt=tab[i].bt;
        printf ("arrived Time");
        scanf ("%d",& tab[i].at);

    }   

}

void printinput()

{

    printf("\nPname\tBT\tAT");

    for (i=0;i<n;i++)

      printf("n%s\t%d\t%d",tab[i].Pname,tab[i].tbt,tab[i].at);

}

void sort()

{

    struct input temp;

    int j;

       for (i=1; i<n; i++)

          for (j=0;j<n-1;j++)

            if (tab[j].at>tab[j+1].at)

            {

                temp=tab[j];

                tab[j]=tab[j+1];

                tab[j+1]=temp;

            }

}

int arrived (int time)

{

    for (i=0;i<n;i++)

    if (tab[i].at<=time && tab[i].tbt!=0)

         return(1);

      return(0);

}

void processinput()

{

    int j,finish=0;

    while(finish!=n)

         {

             if (arrived(time))

             {

                 for (j=0;j<tab[i].bt;j++)

                 {

                     time++;

                     tab[i].tbt--;

                     g[k].start=prev;

                     g[k].end=time;

                     prev = time;

                     tab[i].ft=time;

                     strcpy(g[k++].Pname,tab[i].Pname);

                     if(tab[i].tbt==0)

                     {

                         finish++;

                         break;

                     }

                 }

             }

             else

             {

                 time++;

                 g[k].start=prev;

                 g[k].end=time;

                 prev=time;

                 strcpy (g[k++].Pname,"idle");

             }

        }

}

void printoutput()

{

    int TTAT=0,TWT=0;

    float ATAT,AWT;

    printf("\n ****** Final Table ******");

    printf("\nPname\tAT\tBT\tFT\tTAT\tWT");

    for(i=0;i<n;i++)

    {

        printf ("\n%s\t%d\t%d\t%d\t%d\t%d",tab[i].Pname,tab[i].at,tab[i].bt,tab[i].ft,tab[i].ft-tab[i].at,tab[i].ft-tab[i].at-tab[i].bt);

        TTAT=TTAT+(tab[i].ft-tab[i].at);

        TWT=TWT+(tab[i].ft-tab[i].at-tab[i].bt);

    }

  ATAT=(float)TTAT/n;

  AWT=(float)TWT/n;

printf("\nTotal TAT=%d",TTAT);

printf("\nTotal WT=%d",TWT);

printf("\nAverage TAT =%f",ATAT);

printf("\nAverage WT= %f ",AWT);

}

void printganttchart()

{

    int j=0;

    g1[0]= g[0];

     for (i=1;i<k;i++)

       {

           if(strcpy (g1[j].Pname,g[i].Pname)==0)

             g1[j].end=g[i].end;

           else

           {

               j++;

               g1[j]=g[i];

           }

       }

    printf("\n******* Each Unit Gantt chart ******");

          for (i=0;i<k;i++)

             printf("\n%d\t%s\t%d",g[i].start,g[i].Pname,g[i].end);

             printf("\n******* Final Gantt chart ******");

             for (i=0;i<j;i++)

             printf("\n%d\t%s\t%d",g[i].start,g[i].Pname,g1[i].end);

}

int main()

{

    getinput();

    printf ("\n Entered data is:");

    printinput();

    sort();

    printf("\nData after sorting");

    printinput();

    processinput();

    printoutput();

    printganttchart();

}
