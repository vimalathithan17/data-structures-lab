//binary search
#include<stdio.h>
#include<stdlib.h>
int binary_search(int *arr,int start,int end,int search_value);
void input(int *arr,int size);
void main(){
	int size;
	while(1){
		printf("Enter the size of the array:");
	    scanf("%d",&size);
		if(size>0)
		{
			break;
		}
		printf("!! Enter a valid size !!\n");	
	}
	
	int *arr=(int*)calloc(size,sizeof(int));
	input(arr,size);
	int search_value;
	printf("Enter the value to be searched:");
	scanf("%d",&search_value);
	int index=binary_search(arr,0,size-1,search_value);
	if(index>-1)
	{
		printf("index of element:%d",index);
	}
	else{
		printf("Element not found");
	}
}
void input(int *arr,int size){
	int i;
	for(i=0;i<size;i++)
	{
		printf("Enter the element at index %d:",i);
		scanf("%d",(arr+i));
	}	
}
int binary_search(int *arr,int start,int end,int search_value){
	int mid=(start+end)/2;
	if(arr[mid]==search_value)
	{
		return mid;
	}
	else if(start>end)
	{
		return -1;
	}
	else if(search_value<arr[mid])
	{
		int index=binary_search(arr,start,mid-1,search_value);
		return index;
	}
	else if(search_value>arr[mid])
	{
		int index=binary_search(arr,mid+1,end,search_value);
		return index;
	}
}
