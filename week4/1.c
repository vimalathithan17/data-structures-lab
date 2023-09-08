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
node* swap_adjacent(node *head,int num);
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
		printf("3 to swap adjacent elements\n");
		printf("4 to exit\n");
		while(1)
		{
			printf("Enter your choice:");
			scanf("%d",&choice);
			if(choice>=1 || choice <=4)
			{
				break;
			}
			printf("!! Enter a valid choice !!");
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
				head=swap_adjacent(head,num);
				break;
			case 4:
				exit=1;
		}
		if(exit)
		{
			break;
		}
	}
	free(head);
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
		return NULL;
	}
	else
	{
		node* temp=head;
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
node* swap_adjacent(node *head,int num)
{
	if(num==-1)
	{
		return NULL;
	}
	else
	{
		int i=0;
        node *current,*next_,*first,*prev=NULL;
        current=head;
        
        //first=next;
        
        for(i;i<(num+1)/2;i++)
        {
            next_=current->next;
            current->next=next_->next;
            next_->next=current;
            if(i==0)
            {
                first=next_;
                prev=current;
            } 
            if(i!=0)
            {
              prev->next=next_;
            }
            prev=current;
            current=current->next;
            
            
        }
		return first;
		
	}
}

