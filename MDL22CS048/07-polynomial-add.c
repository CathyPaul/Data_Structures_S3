#include <stdio.h>
#define max 100
typedef struct
{
	float coeff;
	int exp;
}polynomial;
polynomial terms[max];
int avail=0;
int starta,startb,finisha,finishb,startd,finishd;
void attach(float coeff,int exp,int index)
{
	terms[index].coeff=coeff;
	terms[index].exp=exp;
}
void polyadd(int starta,int startb,int finisha,int finishb,int startd,int *finishd)
{
	while(starta<=finisha&&startb<=finishb)
	{
		if(terms[starta].exp==terms[startb].exp)
		{
			float coefficient=terms[startb].coeff+terms[starta].coeff;
			if(coefficient)
			{
				attach(coefficient,terms[startb].exp,startd);
			}
			starta++;
			startb++;
			startd++;
			*finishd=*finishd+1;
		}
		else if(terms[starta].exp>terms[startb].exp)
		{
			attach(terms[starta].coeff,terms[starta].exp,startd);
			starta++;
			startd++;
			*finishd=*finishd+1;
		}
		else
		{
			attach(terms[startb].coeff,terms[startb].exp,startd);
			startb++;
			startd++;
			*finishd=*finishd+1;	
		}
	}
	while(starta<=finisha)
	{
		attach(terms[starta].coeff,terms[starta].exp,startd);
		starta++;
		startd++;
		*finishd=*finishd+1;
	}
	while(startb<=finishb)
	{
		attach(terms[startb].coeff,terms[startb].exp,startd);
		startb++;
		startd++;
		*finishd=*finishd+1;	
	}
}
/*void readPoly(polynomial terms[],int begin,int end)
{
	printf("Give input in decreasing order of degrees\n");
	for(int i=begin;i<=end;i++)
	{
		printf("Enter the coefficient\n");
		scanf("%f",&terms[i].coeff);
		printf("Enter the exponent\n");
		scanf("%d",&terms[i].exp);
		avail++;
	}
}
void displayPoly(polynomial terms[],int start,int end)
{
	for(int i=start;i<=end;i++)
	{
		printf("+%fx^%d",terms[i].coeff,terms[i].exp);
	}
	printf("\n");	
}*/
void main()
{
	starta=avail;
	printf("Enter number of terms of first polynomial\n");
	scanf("%d",&finisha);
	finisha--;
	printf("Give input in decreasing order of degrees\n");
	for(int i=starta;i<=finisha;i++)
	{
		printf("Enter the coefficient\n");
		scanf("%f",&terms[i].coeff);
		printf("Enter the exponent\n");
		scanf("%d",&terms[i].exp);
		avail++;
	}
	//                                                                                         readPoly(terms,starta,finisha);
	int n2;
	printf("Enter number of terms of second polynomial\n");
	scanf("%d",&n2);
	finishb=finisha+n2;
	printf("Give input in decreasing order of degrees\n");
	for(int i=finisha+1;i<=finishb;i++)
	{
		printf("Enter the coefficient\n");
		scanf("%f",&terms[i].coeff);
		printf("Enter the exponent\n");
		scanf("%d",&terms[i].exp);
		avail++;
	}
	//readPoly(terms,finisha+=1,finishb);
	printf("The polynomials are\n");
	printf("%fx^%d",terms[0].coeff,terms[0].exp);
	for(int i=1;i<=finisha;i++)
	{
		printf("+%fx^%d",terms[i].coeff,terms[i].exp);
	}
	printf("\n");
	//displayPoly(terms,1,finisha);
	printf("%fx^%d",terms[finisha+1].coeff,terms[finisha+1].exp);
	for(int i=finisha+2;i<=finishb;i++)
	{
		printf("+%fx^%d",terms[i].coeff,terms[i].exp);
	}
	printf("\n");
	//displayPoly(terms,finisha+2,finishb);
	startd=avail;
	finishd=avail-1;
	startb=finisha+1;
	polyadd(starta,startb,finisha,finishb,startd,&finishd);
	printf("Result\n");
	printf("%fx^%d",terms[finishb+1].coeff,terms[finishb+1].exp);
	for(int i=startd+1;i<=finishd;i++)
	{
	
		printf("+%fx^%d",terms[i].coeff,terms[i].exp);
		
	}
	printf("\n");
}


