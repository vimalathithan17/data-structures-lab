/*

1.	Given an unsorted array of integers, sorr[0..n-1] :
Given an unsorted array of integers, sort the array into a wave array. 
An array arr[0..n-1] is sorted in wave form if:
arr[0] >= arr[1] <= arr[2] >= arr[3] <= arr[4] >= …..


2.	Given an array and a value, find if there is a triplet in array 
whose sum is equal to the given value. 
If there is such a triplet present in array, 
then print the triplet and return true. Else return false.


3.	Given an array arr[] of integers and a number x, 
the task is to find the smallest subarray with a sum greater 
than the given value. 

4.	Given a sorted array of n distinct integers 
where each integer is in the range from 0 to m-1 and m > n. 
Find the smallest number that is missing from the array. 

5.	Find the majority element in the array. 
A majority element in an array A[] of size n is an element that appears more than n/2 times 
(and hence there is at most one such element).

*/
#include<stdio.h>
#include<stdlib.h>
void input(int **arr,int *num,int *m);
void print(int *arr,int num);
void smallest_missing(int *arr,int num);
void main()
{
	int *arr,num,m;
	input(&arr,&num,&m);
	print(arr,num);
	smallest_missing(arr,num);
}
void input(int **arr,int *num,int *m)
{
	while(1)
	{
		printf("Enter the number of elements:");
		scanf("%d",num);
		if(*num>1)
		{
			break;
		}
		printf("the number of elements must be greater than 1.Try Aagain\n");
	}
	*arr=(int*)calloc(*num,sizeof(int));
	int i;
	while(1)
	{
		printf("enter the value of m:");
		scanf("%d",m);	
		if(*m>*num)
		{
			break;
		}
		printf("value of m must be greater than %d.Try again\n",*num);
	}

	printf("Enter a sorted array\n");
	for(i=0;i<*num;i++)
	{
		while(1)
		{
			printf("Enter the value at index %d(less than %d):",i,*m);
			scanf("%d",*arr+i);
			if(*(*arr+i)<*m)
			{
				break;
			}
			printf("The value entered must be less than %d.Enter again\n",*m);
		}
		
	}
}
void print(int *arr,int num)
{
	printf("[ ");
	int i=0;
	for(i;i<num;i++)
	{
		printf("%d ,",*(arr+i));
	}
	printf("\b]\n");
}
void smallest_missing(int *arr,int num)
{
	int i;
	int missing=0;
	for(i=0;i<num;i++)
	{
		if(i!=*(arr+i))
		{
			printf("the smallest missing element is %d",i);
			missing=1;
			break;
		}
	}
	if(missing==0)
	{
		printf("the smallest missing element is %d",i);
	}
}
