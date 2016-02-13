#include<iostream>
using namespace std;

class Node
{
	public:
		int data;
    Node *next;

		Node(int d)
		{
			data = d;
			next = NULL;
		}
};

class List
{
	Node *head;

	public:
		List()
		{
			head = NULL;
		}

//functon to create a linked list

		void create()
		{
			int data;
			Node *ptr;
			char ch;
			while(true)
			{
				cout<<"enter the data for the new node : ";
				cin>>data;

				ptr = new Node(data);

				if(head == NULL)
				{
					head = ptr;	
				}
				else
				{
					ptr->next = head;
					head = ptr;
				}

				cout<<"more nodes(y/n) : ";
				cin>>ch;
				if(ch == 'n')
					break;
			}
		}
// function to display a linked list

		void display()
		{
			Node *temp = head;

			while(temp!=NULL)
			{
				cout<<temp->data<<" ";
				temp = temp->next;
			}
	  }

// Recursive function to display linked list in reverse order

		void dReverse(Node *temp)
		{
			if(temp == NULL)
				return;
			dReverse(temp->next);
			cout<<temp->data<<" ";
		}

		void reverseDisplay()
		{
			dReverse(head);
		}

// Recursive function to reverse the linked list 

		Node* lReverse(Node *temp)
		{
			if(temp->next == NULL)
			{
				head = temp;
				return temp;
			}
				Node *previous = lReverse(temp->next);
				previous->next = temp;
				temp->next = NULL;

				return temp;

		}

		Node* reverseList()
		{
			lReverse(head);
		}

};

//main function

int main()
{
	List l;

	l.create();
	l.display();
	cout<<endl;
	//l.reverseDisplay();
	//cout<<endl;
	l.reverseList();
	cout<<endl;
	l.display();
}
