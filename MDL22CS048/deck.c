#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int data;
	struct node* next;
}nd;
nd* front=NULL;
nd* end=NULL;
nd* create_node()
{
	nd* new_node=(nd*)malloc(sizeof(nd));
	new_node->next=NULL;
	printf("Enter data to be inserted\n");
	scanf("%d",&new_node->data);
	return new_node;
}
void da_front()
{
	nd* new_node=create_node();
	if(front==NULL)
	{
		front=new_node;
		end=new_node;
	}
	else
	{
		new_node->next=front;
		front=new_node;
	}
}
void da_end()
{
	nd* new_node=create_node();
	if(front==NULL)
	{
		front=new_node;
		end=new_node;
	}
	else
	{
		end->next=new_node;
		end=new_node;
	}
}
void dd_front()
{
	nd* ptr=front;
	if(ptr==NULL)
	{
		printf("No elements for deleting\n");
	}
	else
	{
		front=front->next;
		printf("Deleting %d\n",ptr->data);
	}
	free(ptr);
}
void dd_end()
{
	nd* ptr=end;
	if(ptr==NULL)
	{
		printf("No elements for deleting\n");
	}
	else
	{
		nd* temp=front;
		if(front==end)
		{
			front=NULL;
			end=NULL;
		}
		else
		{
			while(temp->next!=end)
			{
				temp=temp->next;
			}
			end=temp;
			end->next=NULL;	
		}
	}
	free(ptr);
}
void display()
{
	if(front==NULL)
	{
		printf("Empty\n");
	}
	else
	{
		nd* ptr=front;
		while(ptr!=NULL)
		{
			printf("%d ",ptr->data);
			ptr=ptr->next;
		}
		printf("\n");
	}
}
void main()
{
	printf("Enter \n1 to insert at front of double ended queue\n2 to insert at end \n3 to delete from front\n4 to delete from end\n5 to display\n");
	int op;
	char ch='y';
	while(ch=='y')
	{
		printf("Enter an option from 1 to 5\n");
		scanf("%d",&op);
		switch(op)
		{
			case 1:
			da_front();
			break;
			case 2:
			da_end();
			break;
			case 3:
			dd_front();
			break;
			case 4:
			dd_end();
			break;
			case 5:
			display();
			break;
			default:
			printf("Invalid choice\n");
		}
		printf("Wish to continue y or n\n");
		scanf(" %c",&ch);
	}
}
