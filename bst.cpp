#include<iostream>
using namespace std;

class Node
{
	public:
		int data;
		Node *left,*right;

		Node(int d)
		{
			data = d;
			left = right = NULL;
		}
};

class BST
{
  Node *root;

  public:
    BST()
    {
      root = NULL;
    }


  // function to insert new node into bst
    
    Node* insert(Node *root, int data)
    {
      if(root == NULL)
        return new Node(data);
      else if(data < root->data)
        root->left = insert(root->left,data);
      else if(data > root->data)
        root->right = insert(root->right,data);
      else
        cout<<data<<" is already present";
      
      return root;
    }

  // function to create a bst

    void create()
    {
      int data;
      char ch;
      while(true)
      {
        cout<<"enter data for new node : ";
        cin>>data;

        if(root == NULL)
          root = new Node(data);
        else
          root = insert(root,data);
        
        cout<<"more nodes(y/n) ";
        cin>>ch;
        if(ch == 'n')
          break;
      }
    }

  // preorder traversal of bst

    void preorder(Node *root)
    {
      if(root == NULL)
        return;
      
      cout<<root->data<<" ";
      preorder(root->left);
      preorder(root->right);
    }

  // inorder traversal of bst

    void inorder(Node *root)
    {
      if(root == NULL)
        return;
      
      inorder(root->left);
      cout<<root->data<<" ";
      inorder(root->right);
    }

  // postorder traversal of bst

    void postorder(Node *root)
    {
      if(root == NULL)
        return;

      postorder(root->left);
      postorder(root->right);
      cout<<root->data<<" ";
    }

  // function to display bst

    void display()
    {
      preorder(root);
      cout<<endl;
      inorder(root);
      cout<<endl;
      postorder(root);
      cout<<endl;
    }
};

int main()
{
  BST t;
  t.create();
  t.display();

  return 0;
}
