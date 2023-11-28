#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int data;
	struct node* next;
}nd;
nd* head=NULL;
void push()
{
	nd* new_node=(nd*)malloc(sizeof(nd));
	printf("Enter data to be pushed\n");
	scanf("%d",&new_node->data);
	if(head==NULL)
	{
		new_node->next=NULL;
		head=new_node;
	}
	else
	{
		new_node->next=head;
		head=new_node;
	}
}
void returnnode(nd* ptr)
{
	printf("Element deleted is %d\n",ptr->data);
	free(ptr);
}
void pop()
{
	nd* ptr;
	if(head==NULL)
	{
		printf("Empty list can't pop\n");
	}
	else
	{
		ptr=head;
		head=head->next;
		returnnode(ptr);
	}
}
void peek()
{
	if(head==NULL)
	{
		printf("Empty List\n");
	}
	else
	{
		printf("%d\n",head->data);
	}
}
void display()
{
	if(head==NULL)
	{
		printf("No elements\n");
	}
	else
	{
		nd* temp=head;
		while(temp!=NULL)
		{
			printf("%d\n",temp->data);
			temp=temp->next;
		}
	}
}
void main()
{
	char ch;
	ch='y';
	printf("to perform stack operations enter \n1 to push\n2 to pop\n3 to peek\n4 to display\n");
	while(ch=='y')
	{
		int choice;
		printf("Enter choice from 1 to 4\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			push();
			break;
			case 2:
			pop();
			break;
			case 3:
			peek();
			break;
			case 4:
			display();
			break;
			default:
			printf("Enter a valid choice\n");
		}
		printf("Do you wish to perform more operations y or n\n");
		
		scanf(" %c",&ch);
	}
}
/*
to perform stack operations enter 
1 to push
2 to pop
3 to peek
4 to display
Enter choice from 1 to 4
1
Enter data to be pushed
11
Do you wish to perform more operations y or n
y
Enter choice from 1 to 4
1
Enter data to be pushed
22
Do you wish to perform more operations y or n
y
Enter choice from 1 to 4
4
22
11
Do you wish to perform more operations y or n
y
Enter choice from 1 to 4
3
22
Do you wish to perform more operations y or n
y
Enter choice from 1 to 4
2
Element deleted is 22
Do you wish to perform more operations y or n
y
Enter choice from 1 to 4
4
11
Do you wish to perform more operations y or n
n

*/



