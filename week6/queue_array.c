//array implementation of Queue
#include<stdio.h>
#include<stdlib.h>
void enqueue(int *queue,int *rear,int *front,int size);
void dequeue(int *queue,int *rear,int *front,int size);
int main()
{
	int size;
	int *queue=NULL;
	printf("Enter the size of the queue:");
	scanf("%d",&size);
	queue=(int *)calloc(size,sizeof(int));
	int front=-1;
	int rear=-1;
	while(1)
	{
		int choice;
		int exit=0;
		printf("\nEnter\n");
		printf("1 to Enqueue\n");
		printf("2 to Dequeue\n");
		printf("3 to exit\n");
		while(1)
		{
			printf("Enter your choice:");
			scanf("%d",&choice);
			if(choice>0 && choice<4)
			{
				break;
			}
			printf("!! Enter valid choice !!\n");	
		}
		switch(choice){
			case 1:	
				enqueue(queue,&rear,&front,size);
				break;
			case 2:	
				dequeue(queue,&rear,&front,size);
				break;
			case 3:
				exit=1;
		}
		if(exit)
		{
			break;
		}
		//printf("f %d r %d",front,rear);
	}
	return 0;
}
void enqueue(int *queue,int *rear,int *front,int size)
{
	int val;
	if(*rear==size-1)
	{
		printf("\n!! Queue is full Can't enqueue !!\n");
		return;
	}
	if(*rear==-1)
	{
		(*front)++;
	}
	printf("Enter the value:");
	scanf("%d",&val);	
	queue[++(*rear)]=val;
}
void dequeue(int *queue,int *rear,int *front,int size)
{
	if(*rear==-1)
	{
		printf("\n!! The Queue is empty Can't dequeue !!\n");
		return;
	}
	printf("the dequed value :%d",queue[*front]);
	if(*front==*rear)
	{
		*front=-1;
		*rear=-1;
	}
	else
	{
		*front+=1;
	}
}
