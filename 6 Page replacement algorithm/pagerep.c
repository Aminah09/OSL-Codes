#include<stdio.h>
int n,nf;
int in[100];
int p[50];
int hit=0;
int i,j,k;
int pgfaultcnt=0;

void getData()
{
    printf("\nEnter length of page reference sequence (string):");
    scanf("%d",&n);
    printf("\nEnter the page reference sequence(string):");
    for(i=0; i<n; i++)
        scanf("%d",&in[i]);
    printf("\nEnter no of frames:");
    scanf("%d",&nf);
}

void initialize()
{
    pgfaultcnt=0;
    for(i=0; i<nf; i++)
        p[i]=9999;
}

int isHit(int data)
{
    hit=0;
    for(j=0; j<nf; j++)
    {
        if(p[j]==data)
        {
            hit=1;
            break;
        }

    }

    return hit;
}

int getHitIndex(int data)
{
    int hitind;
    for(k=0; k<nf; k++)
    {
        if(p[k]==data)
        {
            hitind=k;
            break;
        }
    }
    return hitind;
}

void dispPages()
{
    for (k=0; k<nf; k++)
    {
        if(p[k]!=9999)
            printf(" %d",p[k]);
    }

}

void dispPgFaultCnt()
{
    printf("\nTotal no of page faults:%d",pgfaultcnt);
}

void fifo()
{
    initialize();
    for(i=0; i<n; i++)
    {
        printf("\nFor %d :",in[i]);

        if(isHit(in[i])==0)
        {

            for(k=0; k<nf-1; k++)
                p[k]=p[k+1];

            p[k]=in[i];
            pgfaultcnt++;
            dispPages();
        }
        else
            printf("No page fault");
    }
    dispPgFaultCnt();
}


void optimal()
{
    initialize();
    int near[50];
    for(i=0; i<n; i++)
    {

        printf("\nFor %d :",in[i]);

        if(isHit(in[i])==0)
        {

            for(j=0; j<nf; j++)
            {
                int pg=p[j];
                int found=0;
                for(k=i; k<n; k++)
                {
                    if(pg==in[k])
                    {
                        near[j]=k;
                        found=1;
                        break;
                    }
                    else
                        found=0;
                }
                if(!found)
                    near[j]=9999;
            }
            int max=-9999;
            int repindex;
            for(j=0; j<nf; j++)
            {
                if(near[j]>max)
                {
                    max=near[j];
                    repindex=j;
                }
            }
            p[repindex]=in[i];
            pgfaultcnt++;

            dispPages();
        }
        else
            printf("No page fault");
    }
    dispPgFaultCnt();
}

void lru()
{
    initialize();

    int least[50];
    for(i=0; i<n; i++)
    {

        printf("\nFor %d :",in[i]);

        if(isHit(in[i])==0)
        {

            for(j=0; j<nf; j++)
            {
                int pg=p[j];
                int found=0;
                for(k=i-1; k>=0; k--)
                {
                    if(pg==in[k])
                    {
                        least[j]=k;
                        found=1;
                        break;
                    }
                    else
                        found=0;
                }
                if(!found)
                    least[j]=-9999;
            }
            int min=9999;
            int repindex;
            for(j=0; j<nf; j++)
            {
                if(least[j]<min)
                {
                    min=least[j];
                    repindex=j;
                }
            }
            p[repindex]=in[i];
            pgfaultcnt++;

            dispPages();
        }
        else
            printf("No page fault!");
    }
    dispPgFaultCnt();
}


int main()
{
    int choice;
    while(1)
    {
        printf("\nPage Replacement Algorithms\n1.Enter page reference string\n2.FIFO\n3.Optimal\n4.LRU\n5.Exit\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            getData();
            break;
        case 2:
            fifo();
            break;
        case 3:
            optimal();
            break;
        case 4:
            lru();
            break;      
        default:
            return 0;
            break;
        }
    }
}

/*bvcoew@bvcoew-Lenovo:~$ gcc pagerep2update.c
bvcoew@bvcoew-Lenovo:~$ ./a.out

Page Replacement Algorithms
1.Enter page reference string
2.FIFO
3.Optimal
4.LRU
5.Exit
Enter your choice:1

Enter length of page reference sequence (string):20

Enter the page reference sequence(string):1 2 3 4 2 5 3 4 2 6 7 8 7 9 7 8 2 5 4 9

Enter no of frames:3

Page Replacement Algorithms
1.Enter page reference string
2.FIFO
3.Optimal
4.LRU
5.Exit
Enter your choice:2

For 1 : 1
For 2 : 1 2
For 3 : 1 2 3
For 4 : 2 3 4
For 2 :No page fault
For 5 : 3 4 5
For 3 :No page fault
For 4 :No page fault
For 2 : 4 5 2
For 6 : 5 2 6
For 7 : 2 6 7
For 8 : 6 7 8
For 7 :No page fault
For 9 : 7 8 9
For 7 :No page fault
For 8 :No page fault
For 2 : 8 9 2
For 5 : 9 2 5
For 4 : 2 5 4
For 9 : 5 4 9
Total no of page faults:14
Page Replacement Algorithms
1.Enter page reference string
2.FIFO
3.Optimal
4.LRU
5.Exit
Enter your choice:4

For 1 : 1
For 2 : 1 2
For 3 : 1 2 3
For 4 : 4 2 3
For 2 :No page fault!
For 5 : 4 2 5
For 3 : 3 2 5
For 4 : 3 4 5
For 2 : 3 4 2
For 6 : 6 4 2
For 7 : 6 7 2
For 8 : 6 7 8
For 7 :No page fault!
For 9 : 9 7 8
For 7 :No page fault!
For 8 :No page fault!
For 2 : 2 7 8
For 5 : 2 5 8
For 4 : 2 5 4
For 9 : 9 5 4
Total no of page faults:16
Page Replacement Algorithms
1.Enter page reference string
2.FIFO
3.Optimal
4.LRU
5.Exit
Enter your choice:3

For 1 : 1
For 2 : 2
For 3 : 2 3
For 4 : 2 3 4
For 2 :No page fault
For 5 : 5 3 4
For 3 :No page fault
For 4 :No page fault
For 2 : 5 2 4
For 6 : 5 2 6
For 7 : 5 2 7
For 8 : 8 2 7
For 7 :No page fault
For 9 : 8 9 7
For 7 :No page fault
For 8 :No page fault
For 2 : 2 9 7
For 5 : 5 9 7
For 4 : 4 9 7
For 9 :No page fault
Total no of page faults:13
Page Replacement Algorithms
1.Enter page reference string
2.FIFO
3.Optimal
4.LRU
5.Exit
Enter your choice:5
*/

