#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node *next,*prev;
};

struct linked_list
{
	struct Node *head,*tail;
	int len;
};
typedef struct Node node;
typedef struct linked_list dll;
node* create();
void add(node **head,node **tail,int *len);
node * traverse(node *head,int display);
void delete_node(node **head,node **tail,int *len,int m,int n);
void main()
{
	dll l1;
	l1.head=NULL;
	l1.len=0;
	l1.tail=NULL;
	while(1)
	{
		int choice;
		int exit=0;
		int m,n;
		printf("\nEnter");
		printf("\n1 to add node");
		printf("\n2 to display list");
		printf("\n3 to delete m retain n nodes");
		printf("\n4 to exit");
		while(1)
		{
			printf("\nEnter your choice:");
			scanf("%d",&choice);
			if(choice>0 && choice <5)
			{
				break;
			}
			printf("\n!! Enter a valid choice !!");
		}
		switch(choice)
		{
			case 1:
				add(&(l1.head),&(l1.tail),&(l1.len));
				break;
			case 2:
				traverse(l1.head,1);
				break;
			case 3:
				if(l1.head==NULL)
				{
					printf("\n!! The list is empty.Cant delete!!\n");
					break;
				}
				while(1)
				{
					printf("enter the value of m(greater than 0):");
					scanf("%d",&m);
					printf("enter the value of n(greater then 0):");
					scanf("%d",&n);
					if(m>0 && n>0)
					{
						break;	
					}
					printf("\n!! the value must be greater than 0.Try again !!\n");	
				}
				delete_node(&(l1.head),&(l1.tail),&(l1.len),m,n);
				break;
			case 4:
				exit=1;
		}
		if(exit)
		{
			break;
		}
	}
	printf("tail %d",l1.tail->data);
}
node* create()
{
	node* n=(node *)calloc(1,sizeof(node));
	printf("Enter the value:");
	scanf("%d",&(n->data));
	n->next=NULL;
	n->prev=NULL;
	return n;
}
void add(node **head,node **tail,int *len)
{
	if(*len==0)
	{
		*head=create();
		*tail=*head;
	}
	else
	{	
		(*tail)->next=create();
		(*tail)->next->prev=*tail;
		*tail=(*tail)->next;
	}
	*len+=1;
	printf("\n!! Node added sucessfully !!\n");
}
node * traverse(node *head,int display)
{
	if(head==NULL)
	{
		if(display)
		{
			printf("\n!! the list is empty !!\n");
		}
		return NULL;
	}
	else
	{
		if(display)
		{
			printf("The linked list:");
		}
		node *temp=head;
		while(temp->next!=NULL)
		{
			if(display)
			{
				printf("%d,",temp->data);
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
void delete_node(node **head,node **tail,int *len,int m,int n)
{
		node *temp=*head,*to_delete=NULL;
		int i,m_count=0,n_count=0;
		for(i=0;i<*len;i++)
		{
			if(m_count<m)
			{
				if(m_count<m-1)
				{
					temp=temp->next;
				}
				m_count++;
			}
			else
			{
				if(n_count<n)
				{
					
					to_delete=temp->next;
					if(to_delete->next!=NULL)
					{
						to_delete->next->prev=temp;
					}
					else
					{
						*tail=to_delete->prev;
					}
					temp->next=to_delete->next;
					free(to_delete);
					*len-=1;
					i-=1;
					n_count++;
					if(n_count==n && m_count==m)
					{
						temp=temp->next;
						m_count=0;
						n_count=0;
					}
					
				}	
			}
		}
}
