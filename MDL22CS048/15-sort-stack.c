/*
#include <stdio.h>
#define maxsize 100
int order(int arr[],int top,int ele)
{
	if((ele>arr[top])||top==-1)
	{
		arr[++top]=ele;
	}
	else
	{
		arr[++top]=ele;
	 	int j=top;
		for(int i=top-1;i>=0&&arr[i]>arr[j];i--)
		{
			int temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
			j=i;
		}
	}
	return top;
}
int push(int arr[],int top)
{
	int ele;
	if(top<maxsize-1)
	{
		printf("Enter element to be pushed\n");
		scanf("%d",&ele);
		top=order(arr,top,ele);
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
*/

#include <stdio.h>
#define MAX 100
int stck[MAX],srtd[MAX],ele,top=-1,tip=-1,item,ch;
char choice;
void push_srtd(int elem)
{
	srtd[++tip]=elem;
}
void pop_from_srt()
{
	stck[top++]=srtd[tip--];
}
void push()
{
	printf("Enter element to be inserted\n");
	scanf("%d",&ele);
	int n=top;
	while(ele<stck[n]&&n!=-1)
	{
		push_srtd(stck[n]);
		n--;
	}
	stck[++n]=ele;
	top=n;
	while(tip!=-1)
	{
		pop_from_srt();
	}
}
void pop()
{
	if(top!=-1)
	{
		item=stck[top];
		top--;
		printf("element deleted is %d\n",item);
	}
	else
	{
		printf("Stack is empty\n");
	}
}
void display()
{
	if(top==-1)
	{
		printf("Empty queue\n");
	}
	else
	{
		for(int i=0;i<=top;i++)
		{
			printf("%d ",stck[i]);
		}
		printf("\n");
	}
}
void main()
{
	choice='y';
	while(choice=='y')
	{
		printf("Enter\n1 to push\n2 to pop\n3 to display\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			push();
			break;
			case 2:
			pop();
			break;
			case 3:
			display();
			break;
			default:
			printf("Invalid choice \n");
		}
		printf("continue y or n\n");
		scanf(" %c",&choice);
	}
}









































