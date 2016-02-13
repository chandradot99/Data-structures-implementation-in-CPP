#include<iostream>
#include<climits>
using namespace std;

class Queue
{
	public:
		int Front,Rear,size;
		int *queue;

		Queue(int s)
		{
			size = s;
			Front = 0;
			Rear = -1;
			queue = new int(size);
		}

		bool isFull()
		{
			return (Rear == size-1) ? true : false;
		}

		bool isEmpty()
		{
			return (Front == Rear+1) ? true : false;
		}

		void enqueue(int data)
		{
			if(isFull())
				cout<<"Queue is overflowed\n";
			else
			{
				queue[++Rear] = data;
				cout<<data<<" is enqueued\n";
			}
		}

		void dequeue()
		{
			if(isEmpty())
				cout<<"Queue is underflowed\n";
			else
			{
				int data = queue[Front++];
				cout<<data<<" is dequeued\n";
			}
		}

		int front()
		{
			if(!isEmpty())
				return queue[Front];
			return INT_MIN;
		}
		
		int rear()
		{
			if(!isEmpty())
				return queue[Rear];
			return INT_MIN;
		}
};


// main function

int main()
{
	Queue q(5);
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
	q.enqueue(5);
	q.enqueue(6);
	cout<<"front :"<<q.front()<<endl;
	cout<<"rear :"<<q.rear()<<endl;
	q.dequeue();

	cout<<"front :"<<q.front()<<endl;
	cout<<"rear :"<<q.rear()<<endl;
	q.dequeue();

	cout<<"front :"<<q.front()<<endl;
	cout<<"rear :"<<q.rear()<<endl;
	q.dequeue();

	cout<<"front :"<<q.front()<<endl;
	cout<<"rear :"<<q.rear()<<endl;
	q.dequeue();

	cout<<"front :"<<q.front()<<endl;
	cout<<"rear :"<<q.rear()<<endl;
	q.dequeue();

	cout<<"front :"<<q.front()<<endl;
	cout<<"rear :"<<q.rear()<<endl;
	q.dequeue();
	return 0;
}
