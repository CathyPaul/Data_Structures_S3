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
void main()
{
	int arr[maxsize];
	int top=-1;
	int choice;
	char ch='y';
	while(ch=='y')
	{
		printf("Enter 1 to push\n2to pop\n3 to peek\n4 to display\n");
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
1
Enter element to be pushed
2
Wish to continue enter y to continue or enter n
y
Enter 1 to push
2to pop
3 to peek
4 to display
1
Enter element to be pushed
3
Wish to continue enter y to continue or enter n
y
Enter 1 to push
2to pop
3 to peek
4 to display
1
Enter element to be pushed
4
Wish to continue enter y to continue or enter n
y
Enter 1 to push
2to pop
3 to peek
4 to display
1
Enter element to be pushed
5
Wish to continue enter y to continue or enter n
y
Enter 1 to push
2to pop
3 to peek
4 to display
4
2 3 4 5 
Wish to continue enter y to continue or enter n
y
Enter 1 to push
2to pop
3 to peek
4 to display
3
Top element is 5
Wish to continue enter y to continue or enter n
y
Enter 1 to push
2to pop
3 to peek
4 to display
2
Element pop is 5
Wish to continue enter y to continue or enter n
y
Enter 1 to push
2to pop
3 to peek
4 to display
4
2 3 4 
Wish to continue enter y to continue or enter n
n

*/






