/*
1. Given an array of size N-1 such that it only contains distinct integers in the range of 1 to N. 
Find the missing element.
*/

//O(n)
#include<stdio.h>
#include<stdlib.h>
void sort(int *arr,int num);
void print(int *arr,int num);
void input(int **arr,int *num);
void is_repeated(int *arr,int num,int *repeated);
int missing_element(int *arr,int num);
void main()
{
	int *arr;
	int num;
	int sorted_asc=0;
	int sorted_desc=0;
	int repeated=0;
	while(1)
	{
		input(&arr,&num);
		printf("the given array:");
		print(arr,num);
		is_repeated(arr,num,&repeated);
		if(repeated==0)
		{
			break;	
		}
		printf("The given array has duplicate elements.Please enter distinct values.\n");
		free(arr);
	}
	int missing_val=missing_element(arr,num);
	printf("the missing value is: %d",missing_val);
	free(arr);
}
void input(int **arr,int *num)//O(n)
{
	while(1)
	{
		printf("enter the number of elements:");
		scanf("%d",num);
		if (*num==1)
		{
			printf("enter a value greater than 1\n");
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
		printf("enter the element at index %d(less than %d):",i,*num+2);
		int input_num;
		scanf("%d",&input_num);
		if(input_num>*num+1)
		{
			printf("Please enter a value less than %d.\nEnter again\n",*num+2);
			i--;
			continue;
		}
		*(*arr+i)=input_num;
		//printf("arr %d %p\n",*arr+i,*arr+i);
	}

}

void print(int *arr,int num)//O(n)
{
	printf("[ ");
	int i;
	for(i=0;i<num;i++)
	{
		printf("%d ,",*(arr+i));;
	}
	printf("\b]\n");
}

void is_repeated(int *arr,int num,int *repeated)//O(n^2)
{
		//printf("inrepeated");
		int i;
		for(i=0;i<num-1;i++)
		{
			int j;
			for(j=i+1;j<num;j++)
			{
				//printf("i %d ival %d j %d jval %d\n",i,*(arr+i),j,*(arr+j));
				if(*(arr+i)==*(arr+j))
				{
					//printf("in if");
					*repeated=1;
					return ;
				}	
			}		
       }
       *repeated=0;
       
}
int missing_element(int *arr,int num)//O(n)
{
	int i,missing_val=0;
	for(i=1;i<=num;i++)
	{
		
		missing_val+=i-(*(arr+i-1));
		//printf("i %d arr %d val %d misval %d\n",i,*(arr+i-1),i-*(arr+i-1),missing_val);
	}
	return missing_val+i;
	
}
