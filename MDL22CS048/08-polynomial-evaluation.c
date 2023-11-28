#include <stdio.h>
#include <math.h>
typedef struct
{
	float coeff;
	int exp;
}polynomial;
void readPolynomial(polynomial terms[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("Enter the coefficient\n");
		scanf("%f",&terms[i].coeff);
		printf("Enter the exponents\n");
		scanf("%d",&terms[i].exp);
	}
}
void printPolynomial(polynomial terms[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		printf("%fx^%d+",terms[i].coeff,terms[i].exp);
	}
	printf("%fx^%d",terms[n-1].coeff,terms[n-1].exp);
	printf("\n");
}
float evalPolynomial(polynomial terms[],int n,int x)
{
	float result=0;
	for(int i=0;i<n;i++)
	{
		int power=1;
		for(int j=1;j<=terms[i].exp;j++)
		{
			power*=x;
		}
		result=result+(terms[i].coeff*power);
	}
	return result;
}
void main()
{
	
	polynomial terms[100];
	int n,x;
	printf("Enter number of terms of polynomial\n");
	scanf("%d",&n);
	readPolynomial(terms,n);
	printPolynomial(terms,n);
	printf("Enter the value of x\n");
	scanf("%d",&x);
	float result=evalPolynomial(terms,n,x);
	printf("Result is %f\n",result);
}
