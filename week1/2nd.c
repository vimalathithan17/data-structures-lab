/*
2.	Given an array arr[] and an integer K where K is smaller than size of array, 
the task is to find the Kth smallest element in the given array. 
It is given that all array elements are distinct.
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
void is_repeated(int *arr,int num,int *repeated);
int find_smallest(int *arr,int num,int k, int sorted_asc);
void main()
{
	int *arr;
	int num;
	int sorted_asc=0;
	int sorted_desc=0;
	int repeated=0;
	while(1)
	{
		input(&arr,&num);//got input
		//print(arr,num);//1
		is_repeated(arr,num,&repeated);//check if repeated
		if(repeated==0)
		{
			break;
		}
		printf("The given array has duplicate elements.Please enter distinct values.\n");
		free(arr);
	}
	print(arr,num);//1
	int k;
	while(1)
	{
		printf("enter the value of k(less than %d):",num);
		scanf("%d",&k);
		if(k<num)
		{
			break;
		}
		printf("k must be less than %d Try again",num);
	}
	sorted(arr,num,&sorted_asc,&sorted_desc);
	//printf("asc %d desc %d\n",sorted_asc,sorted_desc);
	if(sorted_asc==0 && sorted_desc==0)
	{
		sort(arr,num);
		sorted_asc=1;
    }
    //printf("asc %d desc %d\n",sorted_asc,sorted_desc);
    //print(arr,num);//2
	//printf("repeated %d,repeated index %d\n",repeated,repeated_index);
	//print(arr,num);//3
	int smallest_element;
	smallest_element=find_smallest(arr,num,k,sorted_asc);
	printf("the %dth smallest element is %d",k,smallest_element);
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
	printf("insort\n");
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
void sorted(int *arr,int num,int *sorted_asc,int *sorted_desc)
{
	printf("insorted");
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
void is_repeated(int *arr,int num,int *repeated)
{
		//printf("inrepeated");
		int i;
		for(i=0;i<num-1;i++)//can add to check if mutiple elements are repeated
		{
			
			
				if(*(arr+i)==*(arr+i+1))
				{
					*repeated=1;
					return ;
				}
       }
       *repeated=0;
}
int find_smallest(int *arr,int num,int k, int sorted_asc)
{
	if(sorted_asc)
	{
		return *(arr+k-1);
	}
	else
	{
		return *(arr+num-k);
	}
}
