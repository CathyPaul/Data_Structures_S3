#include <stdio.h>
void printArray(int arr[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%d  ",arr[i]);
	}
	printf("\n");
}
void search(int arr[],int n,int ele)
{
	int flag=0;
	for(int i=0;i<n;i++)
	{
		if(arr[i]==ele)
		{
			printf("Element found at position %d\n",i+1);
			flag=1;
		}
	}
	if(flag==0)
	{
	 printf("Element not found\n");
	}
}
void main()
{
	int arr[10],n,ele;
	printf("Enter size of array\n");
	scanf("%d",&n);
	printf("Enter array elements\n");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("Enter element to be searched\n");
	scanf("%d",&ele);
	printf("The input is\n");
	printArray(arr,n);
	search(arr,n,ele);
}
/*
Enter size of array
4
Enter array elements
23
4
1
445
Enter element to be searched
1
The input is
23  4  1  445  
Element found at position 3

*/
