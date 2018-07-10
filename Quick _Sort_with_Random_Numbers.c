#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int partition(int a[],int lb,int ub)
{
	int left,right,j,c=0,temp;
	j=left=lb;
	right=ub;
	while(c!=1)
	{
		while((a[j]<=a[right]) && j!=right)
			right--;
		if(j==right)
			c=1;
		else if(a[j]>a[right])
		{
			temp=a[j];clock_t t;
    t = clock();
			a[j]=a[right];
			a[right]=temp;
			j=right;
		}
		if(c!=1)
		{
			while((a[j]>=a[left]) && j!=left)
				left++;
			if(j==left)
				c=1;
			else if(a[left]>=a[j])
			{
				temp=a[j];
				a[j]=a[left];
				a[left]=temp;
				j=left;
			}
		}
	}
	return j;
}		
void quick_sort(int a[],int lb,int ub)
{
	int j;	
	if(lb<ub)
	{
		j=partition(a,lb,ub);
		quick_sort(a,lb,j-1);
		quick_sort(a,j+1,ub);
	}
}
void main()
{
	int a[50000],i;
	for(i=0;i<50000;i++)
		a[i]=rand();
	clock_t t;
	t=clock();
	quick_sort(a,0,49999);
	t = clock() - t;
    	double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds	
	printf("The sorted array is:");
	for(i=0;i<50000;i++)
		printf("%d ",a[i]);
	printf("Quick_sort took %f seconds to execute \n", time_taken);
}
