/*
1. Given an array of size N-1 such that it only contains distinct integers in the range of 1 to N. 
Find the missing element.
2.	Given an array arr[] and an integer K where K is smaller than size of array, 
the task is to find the Kth smallest element in the given array. It is given that all array elements are distinct.
3.	Given an array of size N containing only 0s, 1s, and 2s; sort the array in ascending order.
4.	An element is called a peak element if its value is not smaller than the value of its adjacent elements(if they exists). 
Given an array arr[] of size N, Return the index of any one of its peak elements.
5.	Given an array arr[] of size n, find the first repeating element. 
The element should occur more than once and the index of its first occurrence should be the smallest.
*/
#include<stdio.h>
#include<stdlib.h>
void sort(int *arr,int num);
void print(int *arr,int num);
void input(int **arr,int *num);
void sorted(int *arr,int num,int *sorted_asc,int *sorted_desc);
void is_repeated(int *arr,int num,int* repeated_index,int *repeated);
int missing_element(int *arr,int num,int repeated_index,int sorted_asc,int sorted_desc);
void main()
{
	int *arr;
	int num;
	int sorted_asc=0;
	int sorted_desc=0;
	int repeated=0;
	int repeated_index=0;
	input(&arr,&num);
	printf("the given array:");
	print(arr,num);//1
	sorted(arr,num,&sorted_asc,&sorted_desc);
	//printf("asc %d desc %d\n",sorted_asc,sorted_desc);
	if(sorted_asc==0 && sorted_desc==0)
	{
		sort(arr,num);
		sorted_asc=1;
    }
    //printf("asc %d desc %d\n",sorted_asc,sorted_desc);
    //print(arr,num);//2
	is_repeated(arr,num, &repeated_index,&repeated);
	//printf("repeated %d,repeated index %d\n",repeated,repeated_index);
	//print(arr,num);//3
	if(repeated==0)
	{
		printf("no element is missing.");
		
	}
	else
	{
		int missing_val=missing_element(arr,num,repeated_index,sorted_asc,sorted_desc);
		printf("the repeated element is: %d the\n missing value: %d",*(arr+repeated_index),missing_val);
	}
	free(arr);
	
}
void input(int **arr,int *num)
{
	while(1)
	{
		printf("enter the number of elements:");
		scanf("%d",num);
		if (*num==1)
		{
			printf("enter a value greater than 1\n",*num);
			continue;
		}	
		break;
	}
	*num=(*num)-1;
	*arr=(int *)calloc(*num,sizeof(int));
	//printf("arr %d %p\n",*arr,*arr);
	int i;
	for(i=0;i<*num;i++)
	{
		printf("enter the element at index %d:",i);
		int input_num;
		scanf("%d",&input_num);
		if(input_num>=*num+1)
		{
			printf("enter a value less than %d\n",*num);
			i--;
			continue;
		}
		*(*arr+i)=input_num;
		//printf("arr %d %p\n",*arr+i,*arr+i);
	}

}
void sort(int *arr,int num){
	int i;
	for(i=0;i<num;i++)
	{
		int current_val=*(arr+i);
		int j;
		for(j=i-1;j>=0;j--)
		{
			if(current_val<*(arr+j))
			{
				int dummy=*(arr+j+1);
				*(arr+j+1) = *(arr+j);
				*(arr+j) = dummy;
				printf("inf i %d j %d\n",i, j);
				print(arr,num);
			}
		}
	}
	//print(arr,num);
}
void print(int *arr,int num)
{
	printf("[ ");
	int i;
	for(i=0;i<num;i++)
	{
		printf("%d ,",*(arr+i));;
	}
	printf("\b]\n");
}
void sorted(int *arr,int num,int *sorted_asc,int *sorted_desc)
{
	int asc=0,desc=0,i,is_sorted=1;
	for (i=0;i<num-1;i++)
	{
		if(*(arr+i)<*(arr+i+1))
		{
			asc=1;
			if(asc==1 && desc==1)
			{
				is_sorted=0;
				break;
			}
		}
		else
		{
			if(*(arr+i)>*(arr+i+1))
			{
				desc=1;
				if(asc==1 && desc==1)
				{
					is_sorted=0;
					break;
				}
			}
		}
		
	}
	if(is_sorted)
	{
		if(asc==1)
		{
			*sorted_asc=1;
		}
		else if(desc==1)
		{
			*sorted_desc=1;
		}
	}
}
void is_repeated(int *arr,int num,int* repeated_index,int *repeated)
{
		//printf("inrepeated");
		int i;
		for(i=0;i<num-1;i++)//can add to check if mutiple elements are repeated
		{
			
			
				if(*(arr+i)==*(arr+i+1))
				{
					*repeated=1;
					*repeated_index=i;
					return ;
				}
		
       }
       
}
int missing_element(int *arr,int num,int repeated_index,int sorted_asc,int sorted_desc)
{
	if(sorted_asc==1)
	{
		int i,present;
		
		for(i=*(arr+repeated_index);i<num;i++)
		{
			present=0;
			int j;
			for(j=repeated_index;j<num;j++)
			{
				if(*(arr+j)==i)
				{
					present=1;
				}
			}
			if(present==0)
			{
				return i;
			}
		}
	}
	else if(sorted_desc==1)
	{
		int i,present;
		
		for(i=*(arr+repeated_index);i>0;i--)
		{
			present=0;
			int j;
			for(j=repeated_index;j<num;j++)
			{
				if(*(arr+j)==i)
				{
					present=1;
				}
			}
			if(present==0)
			{
				return i;
			}
		}
	}
}
