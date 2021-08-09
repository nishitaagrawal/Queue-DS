//Array representation of linear queue      1-front  2   3   4  5  6-rear
#include<stdio.h>
#define maxsize 6
int q[maxsize];
int front=-1,rear=-1;
int peek()  // Return front element without removing it
{
	return q[front];
}
int isfull()  // To check if the queue is full
{
	if(rear==maxsize-1)
	{
		return 1;
	}
    else
    {
    	return 0;
	}
}
int isempty()  // To check if the queue is empty
{
	if(front<0 || front>rear)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int enqueue(int data)  //Insertion of element from rear end
{
	if(isfull())
	{
		printf("Overflow");
		return 0;
	}
	else
	{
		rear+=1;
		q[rear]=data;
		return 1;
	}
}
int dequeue()  //To remove element from front ent
{
	if(isempty())
	{
		printf("Queue undreflow");
		return 0;
	}
	else
	{
		int data=q[front];
		front+=1;
		return data;
	}	
}
int display()
{
	int i;
	for(i=0;i<6;i++)
	{
		printf("%d\t",q[i]);
	}		
}	
int main()
{
	enqueue(10);
	enqueue(20);
	enqueue(30);
	enqueue(40);
	enqueue(50);
	enqueue(60);
	display();
	dequeue();
	display();
	return 0;
}
