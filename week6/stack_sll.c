//linked list implementation of stack
#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node *next;
};
typedef struct Node node;
node* create();
void push(node **stack,node **top);
char pop(node **stack,node **top,int *val);
node* traverse(node *stack,node *top);
void peek(node *top);
int main()
{
	node* stack=NULL;
	node* top=NULL;
	while(1)
	{
		int choice;
		int exit=0;
		printf("\nEnter\n");
		printf("1 to push\n");
		printf("2 to pop\n");
		printf("3 to peek\n");
		printf("4 to exit\n");
		while(1)
		{
			printf("Enter the choice:");
			scanf("%d",&choice);
			if(choice>0 && choice<5)
			{
				break;
			}
			printf("!! Enter a valid choice !!\n");
		}
		switch(choice)
		{
			int val;
			char success;
			case 1:
				push(&stack,&top);
				break;
			case 2:
				success=pop(&stack,&top,&val);
				if(success=='f')
				{
					printf("\n!! Stack is empty Can't POP !!\n");
				}
				else
				{
					printf("The poped value is:%d",val);
				}
				break;
			case 3:
				peek(top);
				break;
			case 4:
				exit=1;
		}
		if(exit)
		{
			break;
		}
	}
	free(stack);
	free(top);
	return 0;	
} 

node* create()
{
	node * n=(node*)calloc(1,sizeof(node));
	printf("Enter the data to be pushed:");
	scanf("%d",&(n->data));
	n->next=NULL;
	return n;
}
void push(node **stack,node **top)
{
	if(*top==NULL)
	{
		*stack=create();
		*top=*stack;
		return;
	}
	(*top)->next=create();
	*top=(*top)->next;
	return;
}
char pop(node **stack,node **top,int *val)
{
	if(*stack==NULL)
	{
		return 'f';
	}
	*val=(*top)->data;
	if(*stack==*top)
	{	
		*top=NULL;
		*stack=NULL;
		return 's';
	}
	*top=traverse(*stack,*top);
	(*top)->next=NULL;
	return 's';
}
void peek(node *top)
{
	if(top==NULL)
	{
		printf("\n!! stack is empty !!\n");
		return;
	}
	printf("The value at top of stack is %d\n",top->data);
	
	
}
node* traverse(node *stack,node *top)
{
	if(stack==NULL)
	{
		return NULL;
	}
	node *temp=stack;
	while(temp->next!=top)
	{
		temp=temp->next;
	}
	free(temp->next);
	return temp;
}
