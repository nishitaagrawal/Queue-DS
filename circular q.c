#include<stdio.h>
#define maxsize 5
int front=-1, rear=-1;
int q[maxsize];
int enqueue(int data)   //  4 conditions are 2 be checked  (full Q , Entering 1st element, 2nd loop , next element to be inserted) 
{
	if((front==0 && rear==maxsize-1) || (rear==(front-1)))    // When q is full we cannot enter values so exit fn;
	{
		printf("Overflow");
		return;
	}
	else if(front==-1)    // When we are entering 1st element i.e when q has 0 ele(empty Q) then front is -1
	{
		front=rear=0;
		q[rear]=data;
		printf("Ihe inserted element is : %d",data);
	}
	else if(rear=maxsize-1 && front!=0)    // entering element when in between some spaces are there
	{                                      //(2nd loop of entering elements)   
		rear=0;
		q[rear]=data;
		printf("\nIhe inserted element is : %d",data);
	}
	else                  // finally entering next new elements in queue
	{
		rear++;
		q[rear]=data;
		printf("\nIhe inserted element is : %d",data);
	}
	return;
}
int dequeue()  // 4 conditions to be checked (empty Q, Last element, 2nd loop , next ele to be removed)
{
	if(front==-1)    // check if the queue is empty
	{
		printf("Underflow.");
		return 0;
	}
	printf("\nDeleted element is : %d\n",q[front]);
	int data=q[front];
	q[front]=-1;
	if(front==rear)  // check if it is the last element  after removing Q becomes empty
	{
		front=-1;
		rear=-1;
	}
	else
	{
		if(front==maxsize-1)   // front is at last position set it to zero	
		{
			front=0;                // to remove elements in (2nd loop) ie 1st element may exist
		}
		else    // finally increment front to remove next element
		{
			front++; 
		}
	}
	return data;
}
int display()   // It will check 3 conditions (empty Q, (ie when 2nd loop does not exist) when rear> front(1st loop elements) ,...
{                        //, when 2nd loop exists then print old ele then print new element)
	int i;
	if(front==-1 && rear==-1)    // Check if the queue is empty(we dont have anything to display)
	{
		printf("Underflow");
		return;
	}
	else
	{
		printf("The elements of queue are : ");
		if(rear>=front)          //when front is at 0 and some elements are inserted so that rear is at some other positsion.(1st loop)
		{                        // 0-front  1  2  3  4  5-rear   (= says the last element of the 1st loop)
			for(i=front;i<=rear;i++)   // Or if array is like : __  20-front  30  40  50-rear
			{
				printf("%d",q[i]);
			}
		}
		else               //2nd loop elements when front>rear
		{                                   // example our array is   60  70-rear  30-front  40  50
			for(i=front;i<maxsize;i++)  // It will print 30  40  50 
			{
				printf("%d",q[i]);
			}
			for(i=0;i<=rear;i++)     // It will print 60 and 70
			{
				printf("%d",q[i]);
			}
		
		}
	}
	return 0;
}
int main()
{
	enqueue(10);
	enqueue(20);
	enqueue(30);
	enqueue(40);
	enqueue(50);
	display();
	return 0;
}
