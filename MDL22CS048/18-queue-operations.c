#include <stdio.h>
#define MAX 4
int arr[MAX],front=-1,rear=-1,choice,item,ele;
char ch;
void enqueue()
{
	if(rear!=MAX-1)
	{
		printf("Enter element to be inserted\n");
		scanf("%d",&ele);
		if(front==-1&&rear==-1)
		{
			arr[++rear]=ele;
			front=0;
		}
		else
		{
			arr[++rear]=ele;
		}
	}
	else
	{
		printf("Element can't be inserted\n");
	}
}
void dequeue()
{
	if(front==-1)
	{
		printf("Queue empty\n");
	}
	else
	{
		item=arr[front];
		front++;
		printf("Element deleted is %d\n",item);
	}
}
void display()
{
	if(front==-1)
	{
		printf("Queue Empty\n");
	}
	else
	{
		for(int i=front;i<=rear;i++)
		{
			printf("%d ",arr[i]);
		}
		printf("\n");
	}
}
void main()
{
	ch='y';
	while(ch=='y')
	{
		printf("Enter\n1 for enqueue\n2 for dequeue\n3 to display\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			enqueue();
			break;
			case 2:
			dequeue();
			break;
			case 3:
			display();
			break;
			default:
			printf("Invalid choice \n");
			
		}
		printf("Enter your choice y to continue n to stop\n");
		scanf(" %c",&ch);
	}
}
