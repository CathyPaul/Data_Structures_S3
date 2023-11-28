#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int data;
	struct node* next;
}nd;
nd* front=NULL;
nd* rear=NULL;
void enqueue()
{
	nd* new_node=(nd*)malloc(sizeof(nd));
	printf("Enter node data\n");
	scanf("%d",&new_node->data);
	if(front==NULL&&rear==NULL)
	{
		new_node->next=NULL;
		front=new_node;
		rear=new_node;
	}
	else
	{
		rear->next=new_node;
		new_node->next=NULL;
		rear=new_node;
	}
}
void returnnode(nd* ptr)
{
	printf("Element deleted is %d\n",ptr->data);
	free(ptr);
}
void dequeue()
{
	if(front==NULL&&rear==NULL)
	{
		printf("No elements\n");
	}
	else
	{
		nd* ptr;
		ptr=front;
		front=front->next;
		ptr->next=NULL;
		returnnode(ptr);
	}
}
void display()
{
	if(front==NULL)
	{
		printf("Empty\n");
	}
	else
	{
		nd* temp=front;
		printf("%d<--front\n",temp->data);
		temp=temp->next;
		while(temp!=NULL)
		{
			printf("%d\n",temp->data);
			temp=temp->next;
		}
		//printf("\n");
	}
}
void main()
{
	int choice;
	char ch;
	ch='y';
	printf("Performing queue operations enter\n1 to enqueue\n2 to dequeue\n3 to display\n");
	while(ch=='y')
	{
		printf("Enter choice from 1 to 3\n");
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
			printf("Enter a valid option\n");
		}
		printf("Wish to continue performing queue operations ");
		
		scanf(" %c",&ch);
	}
}
/*
Performing queue operations enter
1 to enqueue
2 to dequeue
3 to display
Enter choice from 1 to 3
1
Enter node data
11
Wish to continue performing queue operations y
Enter choice from 1 to 3
1
Enter node data
22
Wish to continue performing queue operations y
Enter choice from 1 to 3
3
11<--front
22
Wish to continue performing queue operations y
Enter choice from 1 to 3
2
Element deleted is 11
Wish to continue performing queue operations y
Enter choice from 1 to 3
3
22<--front
Wish to continue performing queue operations n

*/
