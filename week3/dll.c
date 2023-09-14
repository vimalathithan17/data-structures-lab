#include<stdio.h>
#include<stdlib.h>
struct Node{
  int data;
  struct Node *next,*previous;
};
int val;
typedef struct Node node;
node *  create();
node* traverse(node **head,node **tail,int index,int display);
void add_last(node **head,node **tail,int*num);
void add_first(node **head,node **tail,int *num);
void insert_middle(node **head,node **tail,int *num);
void insert(node **head,node **tail,int*num,int index);
void delete_first(node **head,node **tail,int *num);
void delete_last(node **head,node **tail,int *num);
void delete_middle(node **head,node **tail,int *num);
void delete_(node **head,node **tail,int*num,int index);
void delete_by_value(node **head,node **tail,int *num,int val);
int main(){
  node *head=NULL,*tail=NULL;
  int num=0;
  printf("A doubly linked list is going to be created!\n");
  add_last(&head,&tail,&num);
  printf("A doubly linked list is ceated.\n");
  int choice,exit=0,val,index;
  while(1)
  {
  	while(1)
  	{
  		printf("\nEnter\n");
  		printf("1 to add elements to last\n");
  		printf("2 to add elements to the first\n");
  		printf("3 to add elements at the middle\n");
  		printf("4 to add elements at a particular index\n");
  		printf("5 to delete first element\n");
  		printf("6 to delete last element\n");
  		printf("7 to delete middle element\n");
  		printf("8 to delete element at a index\n");
  		printf("9 to delete element by value\n");
  		printf("10 to display the linked list\n");
  		printf("11 to exit\n");
  		printf("Enter your choice:");
  		scanf("%d",&choice);
		if(choice>=1 && choice<=11)
		{
			break;
		}
		printf("Enter a valid choice!.\n");
	}
  	
  	switch(choice)
  	{
  		case 1:
			add_last(&head,&tail,&num);
			break;
		case 2:
			add_first(&head,&tail,&num);
			break;
		case 3:
			insert_middle(&head,&tail,&num);
			break;
		case 4:
			while(1)
			{
				printf("enter the index at which you want to insert(less than %d):",num+1);
				scanf("%d",&index);
				if(index<num+1)
				{
					break;
				}
				printf("Enter a valid index as instructed.Try again.\n");
			}
			insert(&head,&tail,&num,index);
			break;
		case 5:
			delete_first(&head,&tail,&num);
			break;
		case 6:
			delete_last(&head,&tail,&num);
			break;
		case 7:
			delete_middle(&head,&tail,&num);
			break;
		case 8:
			while(1)
			{
				printf("enter the index which you want to delete(less than %d):",num);
				scanf("%d",&index);
				if(index<num+1)
				{
					break;
				}
				printf("Enter a valid index as instructed.Try again.\n");
			}
			delete_(&head,&tail,&num,index);
			break;
		case 9:
			printf("enter the value to be deleted:");
			scanf("%d",&val);
			delete_by_value(&head,&tail,&num,val);
			break;
		case 10:
			printf("\nThe doubly liked list is:\n");
			traverse(&head,&tail,-1,1);
			break;
		case 11:
			exit=1;
	}
	if(exit)
	{
		break;
	}
  }
  return 0;
}
node * create()
{
  node * s=(node *)calloc(1,sizeof(node));
  printf("Enter the data:");
  scanf("%d",&(s->data));
  val++;
  s->next=NULL;
  s->previous=NULL;
  return s;
}
void add_first(node **head,node **tail,int *num)
{
  if(*head==NULL)
  {
    *head=create();
    *tail=*head;
  }
  else
  {
    node *temp=*head;
    *head=create();
    (*head)->next=temp;
    temp->previous=*head;
  }
  *num+=1;
  printf("Element added succesfully!");
}

void add_last(node **head,node **tail,int*num)
{
  if(*head==NULL)
  {
    add_first(head,tail,num);
  }
  else
  {
    node *new_;
    new_=create();
    (*tail)->next=new_;
    new_->previous=*tail;
    *tail=new_;
    *num+=1;
    printf("Element added succesfully!");
  }
  
}
node* traverse(node **head,node **tail,int index,int display)
{
  if(*head==NULL)
  {
    if(display)
    {
      printf("no element to diplay.\n");
    }
    return *head;
  }
  else
  {
    int i=0;
    node *temp=*head;
    while(1)
    {
      if(display)
      {
        printf("the value at index %d is %d\n",i,temp->data);
      }
      if(temp->next==NULL || i==index )
      {
        return temp;
      }
      temp=temp->next;
      i++;
    }
  }
}

void insert_middle(node **head,node **tail,int *num)
{
  if((*num)%2==0)
  {
    insert(head,tail,num,(*num)/2);
  }
  else
  {
    insert(head,tail,num,((*num)/2)+1);
  }
 
}
void insert(node **head,node **tail,int*num,int index)
{
  if(index==0)
  {
    add_first(head,tail,num);
  }
  else if(index==*num)
  {
    add_last(head,tail,num);
  }
  else
  {
    node* prev=traverse(head,tail,index-1,0);
    node* new_=create();
    new_->next=prev->next;
    prev->next=new_;
    new_->previous=prev;
    new_->next->previous=new_;
    *num+=1;
    printf("Element added succesfully!");
  }
}
void delete_first(node **head,node **tail,int *num)
{
  if(num==0)
  {
  	printf("the linked list is empty.Can't perform deletion.\n");
  }
  else if(*num==1)
  {
  	free(*head);
  	*head=NULL;
  	*tail=NULL;
  	*num-=1;
  	printf("deleted succesfully!");
  }
  else
  {
  	node *temp=*head;
  	*head=(*head)->next;
  	(*head)->previous=NULL;
  	free(temp);
  	*num-=1;
  	printf("deleted succesfully!");

  }
  
}
void delete_last(node **head,node **tail,int *num)
{
	if(num==0)
  	{
  		printf("the linked list is empty.Can't perform deletion.\n");
  	}
  	else if(*num==1)
  	{
  		*head=NULL;
  		*tail==NULL;
  		*num-=1;
  		printf("deleted succesfully!");
	}
 	else
 	{
 		node *temp;
 		temp=*tail;
 		*tail=temp->previous;
 		(*tail)->next=NULL;
  		free(temp);
  		*num-=1;
  		printf("deleted succesfully!");	
	}
}
void delete_middle(node **head,node **tail,int *num)
{
  
    delete_(head,tail,num,((*num)/2));
 
}
void delete_(node **head,node **tail,int*num,int index)
{
  if(index==0||*num==1)
  {
    delete_first(head,tail,num);
  }
  else if(index==*num-1)
  {
    delete_last(head,tail,num);
  }
  else
  {
    node *prev,*temp;
    prev=traverse(head,tail,index-1,0);
    temp=prev->next;
    prev->next=temp->next;
    temp->next->previous=prev;
    free(temp);
    *num-=1;
    printf("deleted succesfully!");
  }
}
void delete_by_value(node **head,node **tail,int *num,int val)
{
	if((*head)->data==val)
	{
		delete_first(head,tail,num);
	}
	else
	{
		node *temp=(*head)->next;
		int index=1;
		while(1)
		{
			if(temp->data==val)
			{
				delete_(head,tail,num,index);
				return;
			}
			temp=temp->next;
			index++;
		}
	}
}
