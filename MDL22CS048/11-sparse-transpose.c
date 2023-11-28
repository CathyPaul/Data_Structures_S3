#include <stdio.h>
typedef struct
{
	int rows;
	int columns;
	int values;
}triplet;
void inputSparse(triplet a[],int n,int r,int c)
{
	a[0].rows=r;
	a[0].columns=c;
	a[0].values=n;
	printf("Enter triplet as row column value\n");
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&a[i].rows,&a[i].columns,&a[i].values);
	}
}
void displayInput(triplet a[],int n)
{
	for(int i=0;i<=n;i++)
	{
		printf("%d  %d  %d\n",a[i].rows,a[i].columns,a[i].values);
	}
}
void arrangeSparse(triplet a[],int n)
{
	triplet temp[1];
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if((a[i].rows>a[j].rows&&a[j].columns==a[i].columns)||a[i].columns>a[j].columns)
			{
				temp[0]=a[i];
				a[i]=a[j];
				a[j]=temp[0];
			}
		}	
	}
}
void transSparse(triplet t[],int n)
{
	triplet temp[1];
	for(int i=0;i<=n;i++)
	{
		temp[0].rows=t[i].rows;
		t[i].rows=t[i].columns;
		t[i].columns=temp[0].rows;
	}
}
void main()
{
	triplet a[10];
	int nonZero,r1,c1;
	printf("Enter number of non zero elements\n");
	scanf("%d",&nonZero);
	printf("Enter number of rows\n");
	scanf("%d",&r1);
	printf("Enter number of columns\n");
	scanf("%d",&c1);
	inputSparse(a,nonZero,r1,c1);
	printf("The inputted sparse representation is\n");
	displayInput(a,nonZero);
	arrangeSparse(a,nonZero);
	//printf("After arranging\n");
	//displayInput(a,nonZero);
	transSparse(a,nonZero);
	
	printf("Transpose\n");
	displayInput(a,nonZero);
}
/*
Enter number of non zero elements
2
Enter number of rows
2  
Enter number of columns
3
Enter triplet as row column value
0 1 3
1 2 5
The inputted sparse representation is
2  3  2
0  1  3
1  2  5
Transpose
3  2  2
1  0  3
2  1  5

*/
