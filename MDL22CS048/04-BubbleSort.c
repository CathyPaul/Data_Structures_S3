#include <stdio.h>
void printArray(int arr[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%d  ",arr[i]);
	}
	printf("\n");
}
void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
void bubbleSort(int arr[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				swap(&arr[j],&arr[j+1]);
			}
			printArray(arr,n);
		}
	}
}
void main()
{
	int arr[10],n;
	printf("Enter size of array\n");
	scanf("%d",&n);
	printf("Enter array elements\n");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	bubbleSort(arr,n);
	printf("The sorted array is\n");
	printArray(arr,n);
}
/*
Enter size of array
4 
Enter array elements
23
4
66
1
4  23  66  1  
4  23  66  1  
4  23  1  66  
4  23  1  66  
4  1  23  66  
1  4  23  66  
The sorted array is
1  4  23  66  
*/










