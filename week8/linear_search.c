//linear search
#include<stdio.h>
#include<stdlib.h>
int linear_search(int *arr,int size,int search_value);
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
	int index=linear_search(arr,size,search_value);
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
int linear_search(int *arr,int size,int search_value){
	int i;
	for(i=0;i<size;i++){
		if(arr[i]==search_value)
		{
			return i;
		}
	}
	return -1;
}
