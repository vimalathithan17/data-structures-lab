/*
2.	Given an array arr[] and an integer K where K is smaller than size of array, 
the task is to find the Kth smallest element in the given array. 
*/
#include<stdio.h>
#include<stdlib.h>

void print(int *arr,int num);
void input(int **arr,int *num);
void is_repeated(int *arr,int num,int *repeated);
int find_smallest(int *arr,int num,int k);
void main()
{
	int *arr;
	int num;
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

    //print(arr,num);//2
	int smallest_element;
	smallest_element=find_smallest(arr,num,k);
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

void is_repeated(int *arr,int num,int *repeated)
{
		//printf("inrepeated");
		int i;
		for(i=0;i<num;i++)//can add to check if mutiple elements are repeated
		{
			
			int j;
			for(j=i+1;j<num;j++)
			{
				if(*(arr+i)==*(arr+j))
				{
					*repeated=1;
					return ;
				}
		    }
       }
       *repeated=0;
}
int find_smallest(int *arr,int num,int k)
{
	int i;
	for(i=0;i<num;i++)
	{
		int index_of_smallest=i;
		int current_val=*(arr+i);
		int j;
		for(j=i+1;j<num;j++)
		{ 
			//printf("i %d ai %d j %d aj%d ios %d aios %d\n",i,*(arr+i),j,*(arr+j),index_of_smallest,*(arr+index_of_smallest));
			if(*(arr+index_of_smallest)>*(arr+j))
			{
				//printf("inif i %d ai %d j %d aj%d ios %d aios %d\n",i,*(arr+i),j,*(arr+j),index_of_smallest,*(arr+index_of_smallest));
				index_of_smallest=j;
			}
		}
		*(arr+i)=*(arr+index_of_smallest);
		*(arr+index_of_smallest)=current_val;
		//print(arr,num);
		if(i+1==k)
		{
			//printf("inif");
			print(arr,num);
			return *(arr+i);
		}
	}
}
