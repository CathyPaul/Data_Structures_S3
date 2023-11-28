#include <stdio.h>
char infix[100],postfix[100],stack[100],top=-1;
int precedence(char operator)
{
	switch(operator)
	{
		case '+':
		case '-':
		return 1;
		break;
		case '*':
		case '/':
		return 2;
		break;
		case '^':
		return 3;
		break;
		case '(':
		return 0;
	}
}
void toPostfix()
{
	int j=0;
	for(int i=0;infix[i]!='\0';i++)
	{
		if(infix[i]=='+'||infix[i]=='-'||infix[i]=='*'||infix[i]=='/'||infix[i]=='^')
		{
			if(top==-1)
			{
				stack[++top]=infix[i];
			}
			else
			{
				if(precedence(infix[i])>precedence(stack[top]))
				{
					stack[++top]=infix[i];
				}
				else
				{
					postfix[j++]=stack[top--];
					if(precedence(stack[top])==precedence(infix[i]))
					{
						postfix[j++]=stack[top--];
					}
					stack[++top]=infix[i];				
				}
			}
		}
		else if(infix[i]=='(')
		{
			stack[++top]=infix[i];
		}
		else if(infix[i]==')')
		{
			while(stack[top]!='(')
			{
				postfix[j++]=stack[top--];
			}
			top--;
		}
		else
		{
			postfix[j++]=infix[i];
		}
	}
	while(top>-1)
	{
		postfix[j++]=stack[top--];
	}
}

void main()
{
	printf("Enter the expression\n");
	scanf("%s",&infix);
	toPostfix();
	printf("The postfix expression is:\n");
	for(int i=0;postfix[i]!='\0';i++)
	{
		printf("%c",postfix[i]);
	}
	printf("\n");
}












































