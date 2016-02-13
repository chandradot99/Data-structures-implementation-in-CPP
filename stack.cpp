#include<iostream>
#include<climits>
using namespace std;

class Stack
{
	public:
		int Top;
		int size;
		int *stack;
		Stack(int s)
		{
			size = s;
			Top = -1;
			stack = new int(size);	
		}

// function to check whether stack is full

		bool isFull()
		{
			return (Top == size-1) ? true : false;
		}

// function to check whether stack is empty

		bool isEmpty()
		{
			return (Top == -1) ? true : false;
		}

// function to push into the stack

		void push(int data)
		{
			if(isFull())
				cout<<"Stack is Overflowed\n";
			else
			{
				stack[++Top] = data;
				cout<<data<<" is pushed into the stack\n";
			}
		}

// function to pop from the stack

		void pop()
		{
			int data;
			if(isEmpty())
				cout<<"Stack is Underflowed\n";
			else
			{
				data = stack[Top--];
				cout<<data<<" is popped out from the stack\n";
			}
		}

// function to return top element of the stack

		int top()
		{
			if(!isEmpty())
				return stack[Top];
			return INT_MIN; // return min when stack is empty 

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
	cout<<s.top()<<endl;
	s.pop();
	cout<<s.top()<<endl;
	s.pop();
	cout<<s.top()<<endl;
	s.pop();
	cout<<s.top()<<endl;
	s.pop();
	cout<<s.top()<<endl;
	s.pop();
	cout<<s.top()<<endl;
	s.pop();

	return 0;
}
