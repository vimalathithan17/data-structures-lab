#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node *next;
};

typedef struct Node node;

struct linked_list
{
	node *head;
	int len;
};
typedef struct linked_list sll;
node* create();
void add(node **head,int *len);
node* traverse(node *head,int display);
node* remove_(node *head,int *len);
void main()
{
	sll l1;
	l1.head=NULL;
	l1.len=0;
	while(1)
	{
		int exit=0,choice;
		printf("Enter\n");
		printf("1 to add node\n");
		printf("2 to display list\n");
		printf("3 to remove\n");
		printf("4 to exit\n");
		while(1)
		{
			printf("enter your choice:");
			scanf("%d",&choice);
			if(choice>=1 && choice<=4)
			{
				break;
			}
			printf("\n!! Enter a valid choice Try again !!\n");
		}
		switch(choice)
		{
			case 1:
				add(&(l1.head),&(l1.len));
				break;
			case 2:
				traverse(l1.head,1);
				break;
			case 3:
				l1.head=remove_(l1.head,&(l1.len));
				break;
			case 4:
				exit=1;
				break;
		}
		if(exit)
		{
			break;
		}
		printf("\n");
	
	}
} 

node* create()
{
	node* s=(node *)malloc(sizeof(node));
	printf("enter the value:");
	scanf("%d",&(s->data));
	s->next=NULL;
	return s;	
}

void add(node **head,int *len)
{
	if(*len==0)
	{
		*head=create();
		*len+=1;
	}
	else
	{
		node *last=traverse(*head,0);
		last->next=create();
		*len+=1;
	}
	printf("\nnode added !\n");
}
node* traverse(node *head,int display)
{
	if(head==NULL)
	{
		if(display)
		{
			printf("the list is empty");
		}
		return NULL;
	}
	else
	{
		node* temp=head;
		if(display)
		{
			printf("\nthe linked list is:\n");
		}
		while(temp->next!=NULL)
		{
			if(display)
			{
				printf("%d\n",temp->data);
			}
			temp=temp->next;
		}
		if(display)
		{
			printf("%d\n",temp->data);
		}
		return temp;
	}
}
node* remove_(node *head,int *len)
{
	if(head==NULL)
	{
		printf("list is empty");
		return head;
	}
	node *first=NULL,*temp=head;
	int n;
	while(1)
	{
		printf("Enter value of n(less than %d and greater then 0):",*len+1);
		scanf("%d",&n);
		if(n>0 && n<=*len)
		{
			break;
		}
		printf("!! Enter a valid number Try again !!\n");	
	}
	if(n==*len)
	{
		first=temp->next;
		free(temp);
		*len-=1;
		printf("\n!! removed sucessfully !!\n");
		return first;
	}
	else
	{
		int i;
		temp=temp;
		for(i=1;i<*len-n;i++)
		{
			temp=temp->next;
		}
		node *rmv=temp->next;
		if(n==1)
		{
			temp->next=NULL;
		}
		else
		{
			temp->next=temp->next->next;
		}
		free(rmv);
		*len-=1;
		printf("\n!! removed sucessfully !!\n");
		return head;
	}
}
