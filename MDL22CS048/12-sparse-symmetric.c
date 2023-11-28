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
	int k=1;
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
	triplet a[10],c[10];
	int nonZero,r1,c1;
	int flag=0;
	printf("Enter number of non zero elements\n");
	scanf("%d",&nonZero);
	printf("Enter number of rows\n");
	scanf("%d",&r1);
	printf("Enter number of columns\n");
	scanf("%d",&c1);
	inputSparse(a,nonZero,r1,c1);
	for(int i=0;i<=nonZero;i++)
	{
		c[i]=a[i];
	}
	printf("The inputted sparse representation is\n");
	displayInput(a,nonZero);
	arrangeSparse(a,nonZero);
	//printf("After arranging\n");
	//displayInput(a,nonZero);
	transSparse(a,nonZero);
	printf("After transpose\n");
	displayInput(a,nonZero);
	//printf("c\n");
	//displayInput(c,nonZero);
	for(int i=0;i<=nonZero;i++)
	{
		if(a[i].columns!=c[i].columns||a[i].rows!=c[i].rows||a[i].values!=c[i].values)
		{
			flag=1;
			printf("not symmetric\n");
			break;
		}
	}
	
	if(flag==0)
	{
		printf("symmetric\n");
	}
}
/*
Enter number of non zero elements
2
Enter number of rows
3
Enter number of columns
3
Enter triplet as row column value
0 2 3
2 0 3
The inputted sparse representation is
3  3  2
0  2  3
2  0  3
After transpose
3  3  2
0  2  3
2  0  3
symmetric

*/

