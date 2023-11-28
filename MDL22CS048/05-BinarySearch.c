#include <stdio.h>
int binarySearch(int arr[],int n,int ele)
{
	int l=0;
	int r=(n-1);
	int mid;
	while(l<=r)
	{
		mid=l+(r-l)/2;
		if(arr[mid]==ele)
		{
			return mid;
		}	
		else if(arr[mid]>ele)
		{
			r=mid-1;
		}
		else
		{
			l=mid+1;
		}
	}
	return -1;
}
void main()
{
	int arr[10],n,ele;
	printf("Enter size of array\n");
	scanf("%d",&n);
	printf("Enter aray elements\n");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("Enter element to be searched\n");
	scanf("%d",&ele);
	int result=binarySearch(arr,n,ele);
	if(result==-1)
	{
		printf("Element not found\n");
	}
	else
	{
		printf("Element found at position %d\n",result+1);
	}
}
/*
Enter size of array
5
Enter aray elements
23 44 54 61
62
Enter element to be searched
54
Element found at position 3

*/
















