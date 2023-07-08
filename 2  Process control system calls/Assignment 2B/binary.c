#include<stdio.h>
#include<string.h>
#include<string.h>
#include<stdlib.h>
void binser(int [],int ,int );
int main(int argc, char *argv[], char *envp[])
{
	int arr[30];
	char str1[30]={""},str2[30]={""};
	int i,size,ele,j=0,k=0,n;
	strcpy(str1,argv[0]);
	n=strlen(str1);
	printf("%d",n);
	 for(i=0; i<strlen(str1); i++)
	 {
		str2[k]=str1[i];
		k++;
		printf("\n%s removed from char array\n",str2);
		if(str1[i]==' ')
		{
			arr[j]=atoi(str2);
			printf("\n%d putted in int array\n",arr[j]);
			strcpy(str2,"");
			k=0;
			j++;
		}
	 }
	 printf("value of j is: %d\n",j); 	
	 for(i=0; i<j; i++)
	 {
 	 	printf("%d\t",arr[i]); 
	 }
	printf("\nEnter the elements to be search: \n");
	scanf("%d",&ele);
	binser(arr,j-1,ele);
	return 0;
}
void binser(int arr[30],int r,int ele)
{
	int l,mid;
	l=0;
	mid=(l+r)/2;
	while(l<=r){
			if(arr[mid]<ele)
				l=mid+1;
			else if(arr[mid]==ele)
			{
				printf("\nElement %d found at %d location\n",ele,mid+1);
				break;
			}
			else
				r=mid-1;
				mid=(l+r)/2;
			}
	if(l>r)
		printf("\nElement not Found\n");
}

