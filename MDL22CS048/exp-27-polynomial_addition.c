#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int coeff;
	int exp;
	struct node* next;
}nd;
nd *head1,*head2,*head3,*ptr1,*ptr2,*ptr3;
nd* input(nd* head)
{
	char ch='y';
	while(ch=='y')
	{
		nd* new_node=(nd*)malloc(sizeof(nd));
		printf("Enter the coefficient\n");
		scanf("%d",&new_node->coeff);
		printf("Enter the exponent\n");
		scanf("%d",&new_node->exp);
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
		printf("Do you wish to add more terms\n");
		scanf(" %c",&ch);
	}
	return head;
}
void display(nd* head)
{
	if(head==NULL)
	{
		printf("No terms\n");
	}
	else
	{
		nd* temp=head;
		printf("%dx^%d ",temp->coeff,temp->exp);
		temp=temp->next;
		while(temp!=NULL)
		{
			printf("+ %dx^%d ",temp->coeff,temp->exp);
			temp=temp->next;	
		}
		printf("\n");
	}
}
nd* poly_Add(nd *head1,nd *head2)
{
	ptr1=head1;
	ptr2=head2;
	ptr3=head3;
	while(ptr1!=NULL||ptr2!=NULL)
	{
		nd* new_node=(nd*)malloc(sizeof(nd));
		if(ptr1!=NULL&&ptr2!=NULL)
		{
			if(ptr1->exp==ptr2->exp)
			{
				new_node->exp=ptr1->exp;
				new_node->coeff=ptr1->coeff+ptr2->coeff;
				ptr1=ptr1->next;
				ptr2=ptr2->next;
			}
			else if(ptr1->exp>ptr2->exp)
			{
				new_node->exp=ptr1->exp;
				new_node->coeff=ptr1->coeff;
				ptr1=ptr1->next;
			}
			else if(ptr1->exp<ptr2->exp)
			{
				new_node->exp=ptr2->exp;
				new_node->coeff=ptr2->coeff;
				ptr2=ptr2->next;
			}
		}
		else if(ptr1!=NULL)
		{
			new_node->exp=ptr1->exp;
			new_node->coeff=ptr1->coeff;
			ptr1=ptr1->next;
		}
		else if(ptr2!=NULL)
		{
			new_node->exp=ptr2->exp;
			new_node->coeff=ptr2->coeff;
			ptr2=ptr2->next;
		}
		if(head3==NULL)
		{
			head3=new_node;
			ptr3=head3;
		}
		else
		{
			ptr3->next=new_node;
			ptr3=ptr3->next;
		}
	}
	return head3;
}
void main()
{
	printf("Inputting Polynomials\n");
	printf("Polynomial 1\n");
	head1=input(head1);
	printf("Polynomial 2\n");
	head2=input(head2);
	printf("Polynomial 1 is\n");
	display(head1);
	printf("Polynomial 2 is\n");
	display(head2);
	printf("Performing Addition\n");
	head3=poly_Add(head1,head2);
	display(head3);
}
/*
Inputting Polynomials
Polynomial 1
Enter the coefficient
3
Enter the exponent
3
Do you wish to add more terms
y
Enter the coefficient
4
Enter the exponent
2
Do you wish to add more terms
n
Polynomial 2
Enter the coefficient
5
Enter the exponent
2
Do you wish to add more terms
y
Enter the coefficient
1
Enter the exponent
1
Do you wish to add more terms
n
Polynomial 1 is
3x^3 + 4x^2 
Polynomial 2 is
5x^2 + 1x^1 
Performing Addition
3x^3 + 9x^2 + 1x^1 

*/

