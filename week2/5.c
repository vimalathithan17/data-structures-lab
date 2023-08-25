/*

1.	Given an unsorted array of integers, sorr[0..n-1] :Given an unsorted array of integers, sort the array into a wave array. 
An array arr[0..n-1] is sorted in wave form if:
arr[0] >= arr[1] <= arr[2] >= arr[3] <= arr[4] >= …..


2.	Given an array and a value, find if there is a triplet in array whose sum is equal to the given value. 
If there is such a triplet present in array, then print the triplet and return true. Else return false.


3.	Given an array arr[] of integers and a number x, the task is to find the smallest subarray with a sum greater 
than the given value. 

4.	Given a sorted array of n distinct integers where each integer is in the range from 0 to m-1 and m > n. 
Find the smallest number that is missing from the array. 

5.	Find the majority element in the array. 
A majority element in an array A[] of size n is an element that appears more than n/2 times 
(and hence there is at most one such element).

*/
#include<stdio.h>
#include<stdlib.h>
void sort(int *arr,int num);
void print(int *arr,int num);
void input(int **arr,int *num);
void find_majority(int *arr,int num);


void main()
{
	int *arr;
	int num;
	input(&arr,&num);
	print(arr,num);
	sort(arr,num);
	print(arr,num);
	find_majority(arr,num);
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
	*num=(*num);
	*arr=(int *)calloc(*num,sizeof(int));
	//printf("arr %d %p\n",*arr,*arr);
	int i;
	for(i=0;i<*num;i++)
	{
		printf("enter the element at index %d:",i);
		scanf("%d",*arr+i);
		//printf("arr %d %p\n",*arr+i,*arr+i);
	}

}
void sort(int *arr,int num){
	//printf("insort\n");
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
		//printf("outer");
		//print(arr,num);
	}
	//printf("sotr aftr\n");
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
void find_majority(int *arr,int num)
{
		//printf("inrepeated");
		int i;
		int current_val=*arr;
		int count=1;
		int found=0;
		for(i=1;i<num;i++)//can add to check if mutiple elements are repeated
		{
				//printf("cv %d i %d count %d\n",current_val,i,count);
				
				if(current_val==*(arr+i))
				{
					count+=1;
					if (count>(num/2))
					{
						found=1;
						break;	
					}
				}
				else
				{
					current_val=*(arr+i);
					count=1;
				}
       }
       if(found==1)
       {
       	printf("the majority element is :%d\n",current_val);
       	//printf("%d",count);
	   }
       else
       {
       	printf("there is no majority element in the given array.");
	   }
}

