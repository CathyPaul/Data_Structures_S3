#include <stdio.h>
typedef struct polynomial
{
	float coeff;
	int exp;
}
void readPolynomial(polynomial terms[],int n)
{
	printf("Follow decreasing order of degree\n");
	for(int i=0;i<n;i++)
	{
		printf("Enter the coefficient\n");
		scanf("%f",&terms[i].coeff);
		printf("Enter the exponent\n");
		scanf("%d",&terms[i].exp);
	}
}
void displayPolynomial(polynomial terms[],int n)
{
	//int i=0;
	int start=0;
	printf("%fx^%d",terms[start+1].coeff,terms[start+1].exp);
	for(int i=start+1;i<=end;i++)
	{
		printf("+%fx^%d",terms[i].coeff,terms[i].exp");
	}
	printf("\n");
}
int addPolynomial(polynomial terms1[],polynomial terms2[],polynomial terms3[],int n1,int n2)
{
	int i=0,j=0,k=0;
	while(i<n1&&j<n2)
	{
		if(terms1[i].exp==terms2[i].exp)
		{
			terms3[k].coeff=terms1[i].coeff+terms2[i].coeff;
			terms3[k].exp=terms1[i].exp;
			i++;
			j++;
			k++;
		}
		else if(terms1[i].exp>terms2[i].exp)
		{
			terms3[k].coeff=terms1[i].coeff;
			terms3[k].exp=terms1[i].exp;
			i++;
			k++;
		}
		else
		{
			terms3[k].coeff=terms2[j].coeff;
			terms3[k].exp=terms2[j].exp;
			j++;
			k++;
		}
	}
	while(i<n1)
	{
		terms3[k].coeff=terms1[i].coeff;
		terms3[k].exp=terms1[i].exp;
		i++;
		k++;
	}
	while(j<n2)
	{
		terms3[k].coeff=terms2[j].coeff;
		terms3[k].exp=terms2[j].exp;
		j++;
		k++;	
	}
	return k;
}
void main()
{
	polynomial terms1,terms2,terms3;
	int n1,n2;
	printf("Enter size of first polynomial\n");
	scanf("%d",&n1);
	printf("Enter size of second polynomial\n");
	scanf("%d",&n2);
	printf("Reading first polynomial\n");
	readPolynomial(terms1,n1);
	printf("Reading second polynomial\n");
	readPolynomial(terms2,n2);
	printf("First polynomial is \n");
	displayPolynomial(terms1,n1);
	printf("Second polynomial is\n");
	displayPolynomial(terms2,n2);
	printf("Result\n");
	int k=addPolynomial(terms1,terms2,terms3,n1,n2);
	displayPolynomial(terms3,k);
}















