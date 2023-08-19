/*
3.	Given an array of size N containing only 0s, 1s, and 2s; sort the array in ascending order.
4.	An element is called a peak element if its value is not smaller than the value of its adjacent elements(if they exists). 
Given an array arr[] of size N, Return the index of any one of its peak elements.
5.	Given an array arr[] of size n, find the first repeating element. 
The element should occur more than once and the index of its first occurrence should be the smallest.
*/
#include<stdio.h>
#include<stdlib.h>
void input(int **arr,int *num);
void sort(int *arr,int num);
void print(int *arr,int num);
void main()
{
	int *arr;
	int num;
	input(&arr,&num);
	printf("The given array is:");
	print(arr,num);
	sort(arr,num);
	printf("The sorted array is:");
	print(arr,num);
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
		printf("Enter the element at index %d(only 0 or 1 or 2):",i);
		scanf("%d",&input_val);
		if(input_val<0 || input_val>2)
		{
			printf("Please enter eiter 0 or 1 or 2 only.\nReenter the value.\n");
			i--;
			continue;	
		}	
		*(*arr+i)=input_val;
	}	
}
void sort(int *arr,int num)
{
	int i;
	for(i=0;i<num;i++)
	{
		int current_val=*(arr+i);
		int j;
		for(j=i-1;j>=0;j--)
		{
			if(current_val<*(arr+j))
			{
				*(arr+j+1)=*(arr+j);
			}
			else
			{
				*(arr+j+1)=current_val;
				break;
			}
		}
	}
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
