#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int data;
	struct node* left;
	struct node* right;
}nd;
nd* front=NULL;
nd* end=NULL;
nd* create_node()
{
	nd* new_node=(nd*)malloc(sizeof(nd));
	new_node->left=NULL;
	new_node->right=NULL;
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
		new_node->right=front;
		front->left=new_node;
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
		new_node->left=end;
		end->right=new_node;
		end=new_node;
	}
}
void dd_front()
{
	if(front==NULL)
	{
		printf("No elements\n");
	}
	else
	{
		nd* ptr=front;
		front=front->right;
		printf("Deleting %d\n",ptr->data);
		free(ptr);
	}
}
void dd_end()
{
	if(front==NULL)
	{
		printf("No elements\n");
	}
	else
	{
		nd* ptr=end;
		if(front==end)
		{
			front=NULL;
			end=NULL;
		}
		else
		{
			end=end->left;
			end->right=NULL;
		}
		printf("Deleting %d \n",ptr->data);
		free(ptr);
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
		nd* ptr=front;
		while(ptr!=NULL)
		{
			printf("%d ",ptr->data);
			ptr=ptr->right;
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
