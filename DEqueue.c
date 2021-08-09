#include<stdio.h>
#define maxsize 10
int front=-1,rear=-1;
int q[maxsize];
int isfull()  // To check if the Queue is full
{
	if((front==0 && rear==maxsize-1) || front==rear+1)
		return 1;
	else
		return 0;
}
int isempty()    // To check if the queue is empty
{
	if(front==-1)
		return 1;
	else
		return 0;
}
void insert_front(int data)   // To insert element from front end
{
	if(isfull())
	{
		printf("Overflow");
		return;
	}
	if(front==-1)
	{
		front=0;
		rear=0;
	}
	else if(front==0)
	{
		front=maxsize-1;
	}
	else
	{
		front=front-1;
	}
	q[front]=data;
}
void insert_rear(int data)   // To insert element from rear end
{
	if(isfull())
	{
		printf("Overflow");
		return;
	}
	if(front==-1)
	{
		front=0;
		rear=0;
	}
	else if(rear==maxsize-1)
	{
		rear =0;
	}
	else
	{
		rear+=1;
	}
	q[rear]=data;
}
void delete_front()   // To delete element from front end
{
	if(isempty())
	{
		printf("Underflow");
		return;
	}
	if(front==rear)
	{
		front=-1;
		rear=-1;
	}
	else
	{
		if(front=maxsize-1)
		{
			front=0;
		}
		else
		{
			front=front+1;
		}	
	}
}
void delete_rear()    // To delete element from rear end
{
	if(isempty())
	{
		printf("Underflow");
		return;
	}
	if(front==rear)
	{
		front=-1;
		rear=-1;
	}
	else if(rear==0)
	{
		rear=maxsize-1;
	}
	else
	{
		rear=rear-1;
	}
}
int getrear()    // To get element from rear end
{
	if(isempty() || rear<0)
	{
		printf("underflow");
		return -1;
	}
	return q[rear];
}
int getfront()    // To get element fron front end.
{
	if(isempty())
	{
		printf("underflow");
		return -1;
	}
	return q[front];
}
void display()
{                                     //display array
	int i= front;
	printf("Your array is: ");
	while(i!=rear)
	{
		printf("%d ",q[i]);
		i=(i+1)%maxsize;
	}
	printf("%d", q[rear]);
}

int main()
{
	int n,choice;
	printf("MENU \nPress 1 to enter elements from rear end. \nPress 2 to enter element from front end");
	printf("\nPress 3 to delete elements from rear end. \nPress 4 to delete element from front end");
	printf("\nPress 5 to display element from front end \nPress 6 to display element from rear end");
	printf(" \nPress 7 to exit");
	while(choice!=7)
	{
		printf("\nEnter your choice : ");
        scanf("%d",&choice);
		switch(choice)
		{
			case(1):printf("Insert element at rear end : ");
					scanf("%d",&n);
					insert_rear(n);
					display();
					break;
			case(2):printf("Insert element at front end : \n");
					scanf("%d",&n);
					insert_front(n);
					display();
					break;
			case(3):delete_rear();
					display();
					break;
			case(4):delete_front(); 
					display();
					break;
			case(5):printf("\nget front element : %d\n",getfront());
					display();
					break;
			case(6):printf("\nget rear element : %d\n",getrear());
					display();
			    	break;
			case(7):break;
			default:printf("Invalid Choice.");
	    }
	}
}

