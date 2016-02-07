#include<iostream>
using namespace std;

class Stack
{
	public:
		int top;
		int size;
		int *stack;
		Stack(int s)
		{
			size = s;
			top = -1;
			stack = new int(size);	
		}

// function to check whether stack is full

		bool isFull()
		{
			return (top == size-1) ? true : false;
		}

// function to check whether stack is empty

		bool isEmpty()
		{
			return (top == -1) ? true : false;
		}

// function to push into the stack

		void push(int data)
		{
			if(isFull())
				cout<<"Stack is Overflowed\n";
			else
			{
				stack[++top] = data;
				cout<<data<<" is pushed into the stack\n";
			}
		}

// function to pop from the stack

		int pop()
		{
			int data;
			if(isEmpty())
				cout<<"Stack is Underflowed\n";
			else
			{
				data = stack[top--];
				cout<<data<<" is popped out from the stack\n";
			}
			return data;
		}

};

// main function

int main()
{

	Stack s(5);
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	s.push(6);
	s.pop();
	s.pop();
	s.pop();
	s.pop();
	s.pop();
	s.pop();

	return 0;
}
