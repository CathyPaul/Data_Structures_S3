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
void selectionSort(int arr[],int n)
{
	int min;
	for(int i=0;i<n-1;i++)
	{
		min=i;
		for(int j=i+1;j<n;j++)
		{
			if(arr[j]<arr[min])
			{
				min=j;
			}
		}
		if(min!=i)
		{
			swap(&arr[i],&arr[min]);
			printArray(arr,n);
		}
		else
		{
			printArray(arr,n);
		}
	}
}
int main()
{
	int arr[10],n;
	printf("Enter size of array\n");
	scanf("%d",&n);
	printf("Enter array elements\n");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	selectionSort(arr,n);
	printf("The result is \n"); 
	
	printArray(arr,n);
	return 0;
}
/*
Enter size of array
5
Enter array elements
34
54
1
3
552
1  54  34  3  552  
1  3  34  54  552  
1  3  34  54  552  
1  3  34  54  552  
The result is 
1  3  34  54  552
*/















