#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
void bubble_sort(int , int []);                                                               
int main()		                                                      
   {   
	   char str1[30],str2[30];
	   char *a1[30]={str2,"NULL"};
	   int arr[30];                                                        
       	   int i,size,status; 
		pid_t pid;  
do{                                               
       printf("Enter total no. of elements : ");
 	   scanf("%d",&size);
 	   printf("Enter the array\n ");
	 	for(i=0; i<size; i++)
	 	{
 	 		 printf("Enter %d element : ",i+1);
  	 		 scanf("%d",&arr[i]);
		 }                       
                                                               
      	bubble_sort(size, arr);                                        
       printf("after sorting\n");                        
       for(i = 0; i<size;i++)
		{
			sprintf(str1,"%d",arr[i]);                            	
			strcat(str1," ");
			strcat(str2,str1);		
		} 
		 printf("%s",str2);                            
       	 printf("\n");
if((pid=vfork())<0)
{
perror("fork");
exit(0);
}
if(pid==0)
{

		execve("./binary",a1,NULL);   
perror("str3");
exit(1); 
}
}while(wait(&status)!=pid);                                       
printf("\n");
return 0;
}                                                       
   void bubble_sort(int m, int arr[])
   {                                                           
       int i,j,t;                                            
                                                               
       for(i=1;i<= m-1;i++)                               
          for(j=1;j<=m-i;j++)                             
             if(arr[j-1]>=arr[j])                                
             {
                t =arr[j-1];                                    
                arr[j-1]=arr[j];                                 
                arr[j] = t;                                      
             }                                                 
   }                                                           
          
