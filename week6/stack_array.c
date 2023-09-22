#include<stdio.h>
#include<stdlib.h>
char push(int *top,int *stack,int size,int val);
char pop(int *top,int *stack,int *val);
void pop_all(int*top,int *stack);
void peek(int top,int *stack);
int main()
{
	int size;
	int top=-1;
	int *stack;
	printf("Enter the size of the stack:");
	scanf("%d",&size);
	stack=(int*)calloc(size,sizeof(int));
	while(1)
	{
		int choice;
		int exit=0;
		printf("\nEnter\n");
		printf("1 to push\n");
		printf("2 to pop\n");
		printf("3 to peek\n");
		printf("4 to pop all\n");
		printf("5 to exit\n");
		while(1)
		{
			printf("Enter your choice:");
			scanf("%d",&choice);
			if(choice>0 && choice<6)
			{
				break;
			}
			printf("!! Enter valid choice !!\n");	
		}
		switch(choice){
			int val;
			char c;
			case 1:	
				printf("Enter a value:");
				scanf("%d",&val);
				c=push(&top,stack,size,val);
				if(c=='f')
				{
					printf("!!stack is full Can't push!!\n'");
				}
				else
				{
					printf("!! pushed sucessfully !!\n");
				}
				break;
			case 2:	
				c=pop(&top,stack,&val);
				if(c=='f')
				{
					printf("!!stack is empty!!\n");
				}
				else
				{
					
					printf("!! poped sucessfully !!\n");
					printf("the poped value:%d",val);
				}
				break;
			case 3:
				peek(top,stack);
				break;
			case 4:	
				pop_all(&top,stack);
				break;
			case 5:
				exit=1;
		}
		if(exit)
		{
			break;
		}
	}
	free(stack);
	return 0;
}
void pop_all(int*top,int *stack)
{
	if(*top==-1)
	{
		printf("!!empty stack!!\n");
		return;
	}
	printf("The stack is:\n");
	int val;
	while(*top>-1)
	{
		pop(top,stack,&val);
		printf("%d\n",val);		
	}
}
char pop(int *top,int *stack,int *val)
{
	if(*top>-1)
	{
		*val=stack[(*top)--];
		//printf("t%d\n",*top);
		return 's';
	}
	return 'f';	
}
char push(int *top,int *stack,int size,int val)
{
	if(*top<size-1)
	{
		stack[++(*top)]=val;
		//printf("t%d\n",*top);
		return 's';
	}
	return 'f';	
}
void peek(int top,int *stack)
{
	if(top==-1)
	{
		printf("\n!! stack is empty !!\n");
		return;
	}
	printf("The value at the top of the stack is %d\n",stack[top]);
}








/*
void push(int *top,int *stack)
{
	stack=(int *)realloc(stack,(++(*top))*sizeof(int));
	stack[++(*top)]=val;
}
char call_pop(int *top,int *stack,int *val)
{
	if(*top!=-1)
	{
		*val=pop(top,stack);
		return 's';
	}
	return 'f';
	
}
int pop(int *top,int *stack)
{
	return stack[(*top)--];
}
*/


