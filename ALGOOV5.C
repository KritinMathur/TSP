#include <stdio.h>
#include <conio.h>
#include <math.h>

//first input is fixed as starting point

double d(float x1 , float y1 , float x2 , float y2)
{
	return(pow(pow(x2-x1,2)+pow(y2-y1,2),0.5));
}

void main()
{
	int n,i,j,k,path=0;
	float c[2][20],p[2][20];
	// c[2][20] represents 20 input cordinates and p[2][20] contains final path
	float acc= 10.0 ;    //later used to report more points for better accuracy.
	float min;
	clrscr();

	printf("enter number of cordinates\n");

	scanf("%d",&n);

	printf("enter cordinates\n");

	// taking input of cordinates

	for(i = 0 ; i < n ; i++)
	{
		scanf("%f",&c[0][i]);
		//x cordinate
		scanf("%f",&c[1][i]);
		//y cordinate
		printf("\n");
	}

	p[0][path] = c[0][0];
	p[1][path] = c[1][0];
	path++;

	// creating optimal path

	for(i = 0 ; i < n-1 ; i++)
	{
		min = d(c[0][0],c[1][0],c[0][1],c[1][1]);
		k = 1;

		for(j = 1 ; j < n - i ; j++)
		{
			if(d(c[0][0],c[1][0],c[0][j],c[1][j]) < min)
			{
				min = d(c[0][0],c[1][0],c[0][j],c[1][j]);
				k = j;
			}
		}

		c[0][0] =  c[0][k];
		c[1][0] =  c[1][k];

		p[0][path] = c[0][k];
		p[1][path] = c[1][k];
		path++;

		for(j = k ; j < n-1 - i ; j++)
		{
			c[0][j]=c[0][j+1];
			c[1][j]=c[1][j+1];
		}
	}

	//now reporting artificial points in between if distance between 2 points in original path is greater than variable 'acc'

	// * after cordinates report extra points
	for(path = 0 ; path < n ; path++)
	{
		if(acc > d(p[0][path-1],p[1][path-1],p[0][path],p[1][path]) || n == 0)
		{
			printf("%f,%f\n",p[0][path],p[1][path]);
		}
		else
		{
			min = (int)d(p[0][path-1],p[1][path-1],p[0][path],p[1][path]);
			i = min/((int)acc);
			i++;

			for(k = 1; k <= i; k++)
				printf("%f,%f*\n",((i-k)*p[0][path-1]+k*p[0][path])/(float)i,((i-k)*p[1][path-1]+ k*p[1][path])/(float)i);
		}
	}

	getch();
}