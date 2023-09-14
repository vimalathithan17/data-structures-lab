#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node *next;
};
typedef struct Node node;
node* create();
void add(node **head,int *num);
node * traverse(node *head,int display);
void find_greater(node **head,int num);
void main()
{
	node* head=NULL;
	int num=-1;
	int exit;
	while(1)
	{
		int choice=1;
		printf("\nEnter\n");
		printf("1 to add elements\n");
		printf("2 to display the linked list\n");
		printf("3 to do given task \n");
		printf("4 to exit\n");
		while(1)
		{
			printf("Enter your choice:");
			scanf("%d",&choice);
			if(choice>=1 && choice <=4)
			{
				break;
			}
			printf("!! Enter a valid choice !!\n");
		}
		
		switch(choice)
		{
			case 1:
				add(&head,&num);
				break;
			case 2:
				traverse(head,1);
				break;
			case 3:
				find_greater(&head,num);
				break;
			case 4:
				exit=1;
		}
		if(exit)
		{
			break;
		}
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
void add(node **head,int *num)
{
	if(*head==NULL)
	{
		*head=create();
		*num+=1;
	}
	else
	{
		node *last=traverse(*head,0);
		last->next=create();
		*num+=1;
	}
	printf("element added");
	
}
node * traverse(node *head,int display)
{
	if(head==NULL)
	{
		if(display)
		{
			printf("!! The linked list has no elements to display !!\n");
		}
		return NULL;
		
	}
	else
	{
		node* temp=head;
		if(display)
		{
			printf("the linked list :\n");
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
void find_greater(node **head,int num)
{
	int value,i,val_index;
	printf("Enter a value:");
	scanf("%d",&value);
	node* val_node=NULL,*temp=*head;
	for(i=0;i<num+1;i++)
	{
		if(temp->data==value)
		{
			printf("%p %d %d\n",temp,temp->data,i);
			val_node=temp;
			val_index=++i;
			break;
		}
		temp=temp->next;
	}

	if(val_node==NULL)
	{
		printf("!! No node contains the given value !!");
	}
	else
	{
		printf("shit");
		if(val_node->next==NULL)
		{
			return;
		}
		else
		{
			node *next_=val_node,*smaller=NULL;
			for(i=val_index;i<num;i++)
			{
				if(next_->next->data<value)
				{
					smaller=next_->next;
					next_->next=smaller->next;
					next_=next_->next;
					int j=0;
					temp=*head;
					for(j;j<val_index;j++)
					{
						if(j==0)
						{
							if(temp->data>=value && temp->data>=smaller->data)
							{
								*head=smaller;
								smaller->next=temp;
 								val_index+=1;
								break;
							}
						}
						else
						{
							if(temp->next->data>=value && temp->next->data>=smaller->data)
							{
								smaller->next=temp->next;
								temp->next=smaller;
								val_index+=1;
								break;
							}
							temp=temp->next;
						}
					}
				}
				else
				{
					next_=next_->next;
				}
			}	
		}	
	}	
}
