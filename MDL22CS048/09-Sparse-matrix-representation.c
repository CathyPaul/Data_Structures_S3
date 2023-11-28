#include <stdio.h>
typedef struct
{
	int row;
	int column;
	int value;
}triplet;
void InputMatrix(int arr[][10],int r,int c)
{
	printf("Enter elements of sparse matrix\n");
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			scanf("%d",&arr[i][j]);
		}	
	}
}
void displayInputMatrix(int arr[][10],int r,int c)
{
	printf("The inputted matrix is \n");
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
}
int countElements(int arr[][10],int r,int c)
{
	int n=0;
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			if(arr[i][j]!=0)
			{
				n++;
			}
		}
	}
	return n;
}
void sparseRep(triplet rows[],int arr[][10],int nonZero,int r,int c)
{
	rows[0].row=r;
	rows[0].column=c;
	rows[0].value=nonZero;
	int m=1;
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			if(arr[i][j]!=0)
			{
				rows[m].row=i;
				rows[m].column=j;
				rows[m].value=arr[i][j];
				m++;
			}
		}
	}
}
void displaySparse(triplet rows[],int nonZero)
{
	printf("The sparse matrix representation is\n");
	for(int i=0;i<=nonZero;i++)
	{
		printf("%d  %d  %d\n",rows[i].row,rows[i].column,rows[i].value);
	}
}
void main()
{
	int r,c,arr[10][10];
	printf("Enter number of rows\n");
	scanf("%d",&r);
	printf("Enter number of columns\n");
	scanf("%d",&c);
	InputMatrix(arr,r,c);
	displayInputMatrix(arr,r,c);
	int nonZero=countElements(arr,r,c);
	triplet rows[nonZero+1];
	sparseRep(rows,arr,nonZero,r,c);
	displaySparse(rows,nonZero);
	float sparsity=(float)(r*c-nonZero)/(r*c);
	printf("Sparsity is %f",sparsity);
}
/*
Enter number of rows
2
Enter number of columns
3
Enter elements of sparse matrix
1 0 0
0 3 0
The inputted matrix is 
1 0 0 
0 3 0 
The sparse matrix representation is
2  3  2
0  0  1
1  1  3
Sparsity is 0.666667   
*/







