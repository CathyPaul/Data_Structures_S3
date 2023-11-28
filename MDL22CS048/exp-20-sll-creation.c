#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int data;
	struct node* next;
}nd;
nd* head=NULL;
int n;
void create_new_node()
{
	nd* new_node=(nd*)malloc(sizeof(nd));
	new_node->data=n;
	new_node->next=NULL;
	if(head==NULL)
	{
		head=new_node;
	}
	else
	{
		nd* temp=head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		if(temp->next==NULL)
		{
			temp->next=new_node;
		}
	}
}
void display()
{
	if(head==NULL)
	{
		printf("No elements in list\n");
	}
	else
	{
		nd* temp=head;
		while(temp!=NULL)
		{
			printf("%d ",temp->data);
			temp=temp->next;
		}
		printf("\n");
	}
}
void Insert_After()
{
	int dat;
	printf("Enter the data after which node is to be inserted\n");
	scanf("%d",&dat);
	if(head==NULL)
	{
		printf("No element in list \n");
	}
	else
	{
		nd* temp=head;
		nd* prev=NULL;
		nd* new_node=(nd*)malloc(sizeof(nd));
		int n;
		printf("Enter the data to be inserted\n");
		scanf("%d",&n);
		new_node->data=n;
		while(temp!=NULL&&temp->data!=dat)
		{
			
			prev=temp;
			temp=temp->next;
		}
		if(temp==NULL)
		{
			printf("No such data\n");
		}
		else
		{
			new_node->next=temp->next;
			temp->next=new_node;	
		}
			
	}
}
void insert_Before()
{
	nd *t=head;
	int node_data;
	int n;
	nd* prev_node=NULL;
	printf("Enter the node data\n");
	scanf("%d",&node_data);
	printf("Enter data of new node\n");
	scanf("%d",&n);
	if(head==NULL||head->data==node_data)
	{
		nd* new_node=(nd*)malloc(sizeof(nd));
		new_node->data=n;
		new_node->next=head;
		head=new_node;
	}
	else
	{
		while(t->data!=node_data&&t->next!=NULL)
		{
		prev_node=t;
		t=t->next;
		}
		if(t->data==node_data)
		{
		nd* new_node=(nd*)malloc(sizeof(nd));
		new_node->data=n;
		new_node->next=t;
		prev_node->next=new_node;
		}
		else if(t->next==NULL)
		{
			printf("No such element\n");
		}	
	}
}
void insert_Position()
{
	int pos;
	printf("Enter the position at which element is to be inserted\n");
	scanf("%d",&pos);
	int n;
	printf("Enter data of new node\n");
	scanf("%d",&n);
	int cnt=0;
	nd* temp=head;
	nd* prev=NULL;
	while(temp!=NULL)
	{
		cnt++;
		nd* new_node=(nd*)malloc(sizeof(nd));
		new_node->data=n;
		if(cnt==1&&pos==1)
		{
			new_node->next=head;
			head=new_node;
			return;
		}
		else if(cnt==pos)
		{
			new_node->next=temp;
			prev->next=new_node;
			return;
		}
		prev=temp;
		temp=temp->next;
	}
	if(temp==NULL)
	{
		printf("No such position\n");
	}
}
void delete_key()
{
	int key;
	printf("Enter key to be delelted\n");
	scanf("%d",&key);
	if(head==NULL)
	{
		printf("No elements\n");
	}
	else if(head->data==key)
	{
		nd* ptr;
		ptr=head;
		head=head->next;
		free(ptr);
	}
	else
	{
		nd* temp=head;
		nd* prev=NULL;
		while(temp!=NULL)
		{
			if(temp->data==key)
			{
				prev->next=temp->next;
			}
			else
			{
				prev=temp;
				temp=temp->next;
			}
		}
		if(temp==NULL)
		{
			printf("No such key\n");
		}
	}
}
void main()
{
	char ch;
	printf("Do you wish to add elements to list\n");
	scanf(" %c",&ch);
	while(ch=='y')
	{
		printf("Enter node data\n");
		scanf("%d",&n);
		create_new_node();
		printf("Do you wish to continue y or n\n");
		scanf(" %c",&ch);
	}
	printf("The inserted list is\n");
	display();
	int choice;
	char decision='y';
	while(decision=='y')
	{
		printf("Enter\n1 Given a node insert a new node after it\n2 Given a node insert a new node before it\n3 Insert a node in a given position\n4 Delete a node given the key data\n5 Delete a node given the position\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			Insert_After();
			display();
			break;
			case 2:
			insert_Before();
			display();
			break;
			case 3:
			insert_Position();
			display();
			break;
			case 4:
			delete_key();
			display();
			break;
			/*case 5:
			delete_position();
			break;
			default:
			printf("Invalid choice\n");*/
		}
		printf("Do you wish to continue\n");
		scanf(" %c",&decision);
	}
}

