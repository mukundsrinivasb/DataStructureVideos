// C++ program to print DFS traversal from
// a given vertex in a given graph
#include<iostream>
#include<list>
#include<time.h>
#include<stdlib.h>
#include<Windows.h>
using namespace std;

// Graph class represents a directed graph
// using adjacency list representation
class Graph
{
	int V; // No. of vertices

	// Pointer to an array containing
	// adjacency lists
	list<int> *adj;

	// A recursive function used by DFS
	void DFSUtil(int v, bool visited[]);
  public:
	Graph(int V); // Constructor

	// function to add an edge to graph
	void addEdge(int v, int w);

	// DFS traversal of the vertices
	// reachable from v
	void DFS(int v);
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w); // Add w to v’s list.
}

void Graph::DFSUtil(int v, bool visited[])
{
	// Mark the current node as visited and
	// print it
	visited[v] = true;
	cout <<v<<" \n" ;
    Sleep(100);


	// Recur for all the vertices adjacent
	// to this vertex
	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!visited[*i])
			DFSUtil(*i, visited);
}

// DFS traversal of the vertices reachable from v.
// It uses recursive DFSUtil()
void Graph::DFS(int v)
{
	// Mark all the vertices as not visited
	bool *visited = new bool[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;

	// Call the recursive helper function
	// to print DFS traversal
	DFSUtil(v, visited);
}

// Driver code
int main()
{
	// Create a graph given in the above diagram

    int numberOfEdges,numberOfVertices;
    cout<<"What is the number of vertices on the graph? \n";
    cin>>numberOfVertices;
    Graph g(numberOfVertices);
    cout<<"What is the number of edges on the graph ? \n";
    cin>>numberOfEdges;
    int edgeIndex = 0;
    while(edgeIndex < numberOfEdges){
        cout<<"Enter the edge : "<<edgeIndex;
        cout<<"\nFrom which (x) to (y) : ";
        int x,y;
        cin>>x>>y;
        g.addEdge(x,y);
        g.addEdge(y,x);
        edgeIndex++;
    }
    
    int startingNode;
    cout<<"Enter the Node where you would like to start the search";
    cin>>startingNode;
    if(startingNode<=numberOfVertices && startingNode>0)
    {
        cout<<"The traversal starting from the node with Index ";
        g.DFS(startingNode);
        cout<<endl;
    }

	return 0;
}