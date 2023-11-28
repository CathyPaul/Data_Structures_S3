#include <stdio.h>
#define MAX 3
int arr[MAX],front=-1,rear=-1,choice,ele,item;
char ch;
void enqueue()
{
	printf("Enter element to be inserted\n");
	scanf("%d",&ele);
	if(front==-1)
	{
		front=0;
		rear=0;
		arr[rear]=ele;
	}
	else
	{
		if(((rear+1)%MAX)!=front)
		{
			rear=((rear+1)%MAX);
			arr[rear]=ele;
		}
		else
		{
			printf("Queue full can't push\n");
		}
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
		if(front==rear)
		{
			front=-1;
			rear=-1;
		}
		else
		{
			front=(front+1)%MAX;
		}
		printf("The element deleted is %d\n",item);
	}
}
void display()
{
	if(front==-1)
	{
		printf("Queue empty\n");
	}
	else if(rear>=front)
	{
		for(int i=front;i<=rear;i++)
		{
			printf("%d ",arr[i]);
		}
		printf("\n");
	}
	else
	{
		for(int i=front;i<MAX;i++)
		{
			printf("%d ",arr[i]);
		}
		for(int i=0;i<=rear;i++)
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
