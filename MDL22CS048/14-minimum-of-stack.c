#include <stdio.h>
#define maxsize 100
int push(int arr[],int top)
{
	int ele;
	if(top<maxsize-1)
	{
		printf("Enter element to be pushed\n");
		scanf("%d",&ele);
		arr[top+1]=ele;
		top=top+1;
	}
	else
	{
		printf("Stack full\n");
	}
	return top;
}
int pop(int arr[],int top)
{
	if(top!=-1)
	{
		printf("Element pop is %d\n",arr[top]);
		top--;
	}
	else
	{
		printf("Empty stack\n");
	}
	return top;
}
void peek(int arr[],int top)
{
	if(top!=-1)
	{
		printf("Top element is %d\n",arr[top]);
	}
	else
	{
		printf("Empty stack\n");
	}
}
void display(int arr[],int top)
{
	if(top!=-1)
	{
		for(int i=0;i<=top;i++)
		{
			printf("%d ",arr[i]);
		}
		printf("\n");
	}
	else
	{
		printf("Empty stack\n");
	}
}
void displaymin(int arr[],int min[],int top, int top_min)
{
	for(int i=0;i<=top;i++)
	{
		if(top_min=-1)
		{
			min[0]=arr[i];
			top_min++;
		}
		else if(min[0]>arr[i])
		{
			min[0]=arr[i];
			top_min++;
		}
	}
	printf("The minimum element is %d \n",min[0]);
}
void main()
{
	int arr[maxsize],min[1];
	int top=-1,top_min=-1;
	int choice;
	char ch='y';
	while(ch=='y')
	{
		printf("Enter 1 to push\n2to pop\n3 to peek\n4 to display\n5 to display minimum element\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			top=push(arr,top);
			break;
			case 2:
			top=pop(arr,top);
			break;
			case 3:
			peek(arr,top);
			break;
			case 4:
			display(arr,top);
			break;
			case 5:
			displaymin(arr,min,top,top_min);
			break;
			default:
			printf("Invalid choice \n");
		}
		
		printf("Wish to continue enter y to continue or enter n\n");
		
		scanf(" %c",&ch);
	}
}
/*
Enter 1 to push
2to pop
3 to peek
4 to display
5 to display minimum element
1
Enter element to be pushed
9
Wish to continue enter y to continue or enter n
y
Enter 1 to push
2to pop
3 to peek
4 to display
5 to display minimum element
1
Enter element to be pushed
8
Wish to continue enter y to continue or enter n
y
Enter 1 to push
2to pop
3 to peek
4 to display
5 to display minimum element
1
Enter element to be pushed
2
Wish to continue enter y to continue or enter n
y
Enter 1 to push
2to pop
3 to peek
4 to display
5 to display minimum element
1
Enter element to be pushed
0
Wish to continue enter y to continue or enter n
y
Enter 1 to push
2to pop
3 to peek
4 to display
5 to display minimum element
1
Enter element to be pushed
-2
Wish to continue enter y to continue or enter n
y
Enter 1 to push
2to pop
3 to peek
4 to display
5 to display minimum element
4
9 8 2 0 -2 
Wish to continue enter y to continue or enter n
y
Enter 1 to push
2to pop
3 to peek
4 to display
5 to display minimum element
5
The minimum element is -2 
Wish to continue enter y to continue or enter n
y
Enter 1 to push
2to pop
3 to peek
4 to display
5 to display minimum element
6
Invalid choice 
Wish to continue enter y to continue or enter n
n

*/






