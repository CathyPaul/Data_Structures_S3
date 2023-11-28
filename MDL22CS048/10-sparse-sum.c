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
int sparseSum(triplet a[],triplet b[],triplet c[],int n1,int n2)
{
	int i=1,j=1,k=1;
	if(a[0].rows==b[0].rows&&a[0].columns==b[0].columns)
	{
		while(i<=n1&&j<=n2)
		{
			if((a[i].rows==b[j].rows&&a[i].columns==b[j].columns))
			{
				c[k].rows=a[i].rows;
				c[k].columns=a[i].columns;
				c[k].values=a[i].values+b[j].values;
				i++;j++;k++;
			}
			else if((a[i].rows==b[j].rows&&a[i].columns>b[j].columns)||a[i].rows>b[j].rows)
			{
				c[k].rows=b[j].rows;
				c[k].columns=b[j].columns;
				c[k].values=b[j].values;
				j++;k++;
			}
			else if((a[i].rows==b[j].rows&&a[i].columns<b[j].columns)||a[i].rows<b[j].rows)
			{
				c[k].rows=a[i].rows;
				c[k].columns=a[i].columns;
				c[k].values=a[i].values;
				i++;k++;
			}
		}
		while(i<=n1)
		{
			c[k].rows=a[i].rows;
			c[k].columns=a[i].columns;
			c[k].values=a[i].values;
			i++;k++;
		}
		while(j<=n2)
		{
			c[k].rows=b[j].rows;
			c[k].columns=b[j].columns;
			c[k].values=b[j].values;
			j++;k++;
		}	
	}
	else
	{
		printf("Can't add the given matrices\n");
	}
	return k;
	
}
void main()
{
	triplet a[10],b[10],c[20];
	int r1,c1,r2,c2,nonZero1,nonZero2;
	printf("Enter number of rows in first matrix\n");
	scanf("%d",&r1);
	printf("Enter number of columns in first matrix\n");
	scanf("%d",&c1);
	printf("Enter number of rows in second matrix\n");
	scanf("%d",&r2);
	printf("Enter number of columns in second matrix\n");
	scanf("%d",&c2);
	printf("Enter number of non zero elements in first matrix\n");
	scanf("%d",&nonZero1);
	printf("Enter number of non zero elements  in second matrix\n");
	scanf("%d",&nonZero2);
	c[0].rows=r1;
	c[0].columns=c1;
	printf("Enter triplets of matrix 1\n");
	inputSparse(a,nonZero1,r1,c1);
	printf("Enter triplets of matrix 2\n");
	inputSparse(b,nonZero2,r2,c2);
	printf("triplets of matrix 1\n");
	displayInput(a,nonZero1);
	printf("triplets of matrix 2\n");
	displayInput(b,nonZero2);
	printf("Computing result\n");
	int k=sparseSum(a,b,c,nonZero1,nonZero2);
	c[0].values=k-1;
	displayInput(c,k-1);
}
/*
Enter number of rows in first matrix
2
Enter number of columns in first matrix
3
Enter number of rows in second matrix
2
Enter number of columns in second matrix
3
Enter number of non zero elements in first matrix
1
Enter number of non zero elements  in second matrix
2
Enter triplets of matrix 1
Enter triplet as row column value
0 0 2
Enter triplets of matrix 2
Enter triplet as row column value
0 0 9
0 1 4
triplets of matrix 1
2  3  1
0  0  2
triplets of matrix 2
2  3  2
0  0  9
0  1  4
Computing result
2  3  2
0  0  11
0  1  4

*/















