//array implementation of Queue
#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node *next;
};
typedef struct Node node;
node* create();
void enqueue(node **queue,node **rear);
void dequeue(node **queue,node **rear);
int main()
{
	node *queue=NULL;
	node *rear=NULL;
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
				enqueue(&queue,&rear);
				break;
			case 2:	
				dequeue(&queue,&rear);
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
node* create()
{
	node * n=(node*)calloc(1,sizeof(node));
	printf("Enter the data to be enqueued:");
	scanf("%d",&(n->data));
	n->next=NULL;
	return n;
}
void enqueue(node **queue,node **rear)
{
	if(*queue==NULL)
	{
		*queue=create();
		*rear=*queue;
		return;
	}
	(*rear)->next=create();
	(*rear)=(*rear)->next;
}
void dequeue(node **queue,node **rear)
{
	if(*queue==NULL)
	{
		printf("\n!! Queue is empty Can't Dequeue !!\n");
		return;
	}
	printf("The dequed element is:%d",(*queue)->data);
	if(*queue==*rear)
	{
		*queue=NULL;
		*rear=NULL;
	}
	else
	{
		*queue=(*queue)->next;	
	}
	
}
