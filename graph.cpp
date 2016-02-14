#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;


class Node
{
  public:
    int des;
    Node *next;

    Node(int d)
    { 
      des = d;
      next = NULL;
    }
};

class Graph
{
  int vert,edge;
  Node **adjList;

  public:
    Graph(int v, int e)
    {
      vert = v;
      edge = e;
      adjList = new Node*[vert];
			for(int i=0;i<vert;i++)
				adjList[i] = NULL;
    }

  // function to add edges

    void addEdges(int src, int des)
    {
      Node *ptr = new Node(des);

      if(adjList[src] != NULL)
      {
        ptr->next = adjList[src];
        adjList[src] = ptr;
      } 
      else
        adjList[src] = ptr;
    }

  // function to create adjacency list

    void create()
    {
      int src,des;
      for(int i=0;i<edge;i++)
      {
        cout<<"enter source and destination vertices : ";
        cin>>src>>des;

        addEdges(src,des);
      //  addEdges(des,src); // uncomment this for undirected graphs
      }

    }

  // function to dispaly adjacency list

    void display()
    {
      Node *temp;
      for(int i=0;i<vert;i++)
      {
        temp = adjList[i];
        cout<<"vertex "<<i<<" : ";

        while(temp!=NULL)
        {
          cout<<temp->des<<" ";
          temp = temp->next;
        }
        cout<<endl;
      }
    }

  // breadth first traversal for connected graphs

    void bfsUtil(int start, bool visited[])
    {
      queue<int> pq;

      pq.push(start);
      visited[start] = true;

      while(!pq.empty())
      {
        int current = pq.front();
				pq.pop();
        cout<<current<<" ";
        Node *temp = adjList[current];

        while(temp!=NULL)
        {
          if(!visited[temp->des])
          {
            visited[temp->des] = true;
            pq.push(temp->des);
          } 
          temp = temp->next; 
        } 
      }
      cout<<endl;
    }

  // additional function for bfs of disconnected graphs

    void bfs()
    {
      bool visited[vert];
			fill_n(visited,vert,false);

      for(int i=0;i<vert;i++)
      {
        if(!visited[i])
          bfsUtil(i,visited);
      }
    }

  // depth first search for connected graphs

    void dfsUtil(int current, bool visited[])
    {
      cout<<current<<" ";
      visited[current] = true;

      Node *temp = adjList[current];

      while(temp!=NULL)
      {
        if(!visited[temp->des])
          dfsUtil(temp->des,visited);

        temp = temp->next;
      }
    }

  // additional function for dfs of disconnected graphs

    void dfs()
    {
      bool visited[vert];
			fill_n(visited,vert,false);
      for(int i=0;i<vert;i++)
      {
        if(!visited[i])
          dfsUtil(i,visited);
      }
      cout<<endl;
    }


};

int main()
{
  int vert,edge;
  cout<<"enter the no of vertices and edges : ";
  cin>>vert>>edge;
  
  Graph g(vert,edge);
  g.create();
  g.display();

 	g.bfs();
  g.dfs();

  return 0;
}
