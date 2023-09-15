/*
4.	An element is called a peak element if its value is not smaller than the value of its adjacent elements
(if they exists). 
Given an array arr[] of size N, Return the index of any one of its peak elements.

*/
#include<stdio.h>
#include<stdlib.h>
void input(int **arr,int *num);
int find_peak(int *arr,int num);
void print(int *arr,int num);
void main()
{
	int *arr;
	int num;
	input(&arr,&num);
	printf("the given array:");
	print(arr,num);
	int peak_index;
	peak_index=find_peak(arr,num);
	if(peak_index!=-1)
	{
		printf("The index of one of the peak element is:%d",peak_index);
	}
	else
	{
		printf("There is no peak element in the given array.");
	}
	free(arr);
}
void input(int **arr,int *num)
{
	printf("Enter the number of elements:");
	scanf("%d",num);
	*arr=(int *)calloc(*num,sizeof(int));
	int i;
	for(i=0;i<*num;i++)
	{
		int input_val;
		printf("Enter the element at index %d:",i);
		scanf("%d",*arr+i);
	}	
}
int find_peak(int *arr,int num)
{
	int i;
	for(i=0;i<num;i++)
	{
		if(i==0)
		{
			//printf("in c1\n");
			if (*(arr+i)>*(arr+i+1))
			{
				//printf("in c1\n");
				return i;
			}
		}
		else if(i==num-1)
		{
			//printf("in c2\n");
			if(*(arr+i)>*(arr+i-1))
			{
				//printf("in c2\n");
				return i;
			}
		}
		else
		{
			//printf("in c3\n");
			if((*(arr+i)>*(arr+i-1))&&(*(arr+i)>*(arr+i+1)))
			{
				//printf("in c3\n");
				return i;
			}
		}	
	}
	return -1;
}
void print(int *arr,int num)
{
	printf("[ ");
	int i;
	for (i=0;i<num;i++)
	{
		printf("%d ,",*(arr+i));
	}
	printf("\b]\n");
}
