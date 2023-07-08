
// Bankers Algorithm

#include<stdio.h>

void main()
{
  int process, resource, i, j, instance, k=0, count=0, temp=0;
  printf("\n Enter No. of Process : ");
  scanf("%d", &process);
  printf(" Enter No. of Resources : ");
  scanf("%d",&resource);
  int available[resource], max[process][resource], allocated[process][resource], need[process][resource], completed[process];

  for(i=0; i<process; i++)
    completed[i] = 0;

  printf("\n Enter AVAILABLE resources for processes\n\n");
  for(i=0; i<resource;i++)
  {  
    printf(" Resources[%d] : ", i);
    scanf("%d", &instance);
    available[i] = instance;
  }

  printf("\n------------------------------------------------------------------------------\n");
  printf("\n Enter MAXIMUM matrix for process :\n");
  for(i=0; i<process; i++)
  {
    printf("\n For Process[%d] \n", i);
    for(j=0; j<resource; j++)
    {
        printf(" Resource[%d] : ", j);
        scanf("%d", &instance);
        max[i][j] = instance;
    }
  }

  printf("\n------------------------------------------------------------------------------\n");
  printf("\n Enter Allocation matrix :\n");
  for(i=0; i<process; i++)
  {
    printf("\n For Process[%d] \n", i);
    for(j=0; j<resource; j++)
    {
      printf(" Resource[%d] : ", i);
      scanf("%d", &instance);
      allocated[i][j] = instance;
      need[i][j] = max[i][j] - allocated[i][j];// need matrix
    }
  }

  printf("\n------------------------------------------------------------------------------\n");
  printf("\nSafe Sequence is : ");
  while(count != process)
  {
    count = temp;
    for(i=0; i<process; i++)
    {
      for(j=0; j<resource; j++)
      {
        if(need[i][j] <= available[j])
        {
          k++;
        }
      }
      if(k == resource && completed[i] == 0 )
      {
        printf(" > P[%d] ", i);
        completed[i] = 1;
        for(j=0; j<resource; j++)
        {
          available[j] = available[j] + allocated[i][j];
        }      
        count++;
      }
      k=0;
    }

    if(count == temp)
    {
      break;
    }
  }

  for(i=0; i<process; i++)
  {
    if(completed[i] != 1)
    {
      printf("\n\n P[%d] not able to allocate", i);
    }
  }
  printf("\n");
}





/* Output 
bvcoew@bvcoew-Lenovo:~/osl1$ gcc banker1.c
bvcoew@bvcoew-Lenovo:~/osl1$ ./a.out

 Enter No. of Process : 4
 Enter No. of Resources : 3

 Enter AVAILABLE resources for processes

 Resources[0] : 3
 Resources[1] : 3
 Resources[2] : 2

------------------------------------------------------------------------------

 Enter MAXIMUM matrix for process :

 For Process[0] 
 Resource[0] : 7
 Resource[1] : 5
 Resource[2] : 3

 For Process[1] 
 Resource[0] : 3
 Resource[1] : 2
 Resource[2] : 2

 For Process[2] 
 Resource[0] : 9
 Resource[1] : 0
 Resource[2] : 4

 For Process[3] 
 Resource[0] : 2
 Resource[1] : 2
 Resource[2] : 2

------------------------------------------------------------------------------

 Enter Allocation matrix :

 For Process[0] 
 Resource[0] : 0
 Resource[0] : 1
 Resource[0] : 0

 For Process[1] 
 Resource[1] : 2
 Resource[1] : 0
 Resource[1] : 0

 For Process[2] 
 Resource[2] : 4
 Resource[2] : 0
 Resource[2] : 1

 For Process[3] 
 Resource[3] : 2
 Resource[3] : 1
 Resource[3] : 1

------------------------------------------------------------------------------

Safe Sequence is :  > P[1]  > P[3]  > P[0]  > P[2] 
*/
