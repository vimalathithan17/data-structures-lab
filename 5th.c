/*
4.	An element is called a peak element if its value is not smaller than the value of its adjacent elements
(if they exists). 
Given an array arr[] of size N, Return the index of any one of its peak elements.
5.	Given an array arr[] of size n, find the first repeating element. 
The element should occur more than once and the index of its first occurrence should be the smallest.
*/
#include<stdio.h>
#include<stdlib.h>
void input(int **arr,int *num);
int find_repeating(int *arr,int num);
void print(int *arr,int num);
void main()
{
	int *arr;
	int num;
	input(&arr,&num);
	printf("the given array:");
	print(arr,num);
	int first_repeating_element_index;
	first_repeating_element_index=find_repeating(arr,num);
	if(first_repeating_element_index!=-1)
	{
		printf("The first repeating element id %d and the index of its first occurance is :%d",*(arr+first_repeating_element_index),first_repeating_element_index);
	}
	else
	{
		printf("There is no repeating element in the given array.");
	}
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
int find_repeating(int *arr,int num)
{
	int i;
	for (i=0;i<num;i++)
	{
		int current_val=*(arr+i);
		int j;
		for(j=i+1;j<num;j++)
		{
			if(*(arr+j)==current_val)
			{
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
