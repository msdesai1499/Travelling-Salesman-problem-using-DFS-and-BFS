#include<iostream> 
#include <list> 
using namespace std;
//Graph Class is used that contains methods for both DFS and BFS 
class Graph 
{ 
	int V;//Private variable P is taken ,it contains total number of nodes(cities) in Graph

	list<int> *adj;//list datatype is used to store edges for each node 
	void DFSUtil(int v, bool visited[],int m);

public: 
	//Constructor and Function Declaration
	Graph(int V); 
	void add(int v, int w); 
	void BFS(int s,int m); 
	void DFS(int v,int m);
}; 

//Constructor for Graph class
//In this constructor new list is created and V is initialized
Graph::Graph(int V) 
{ 
	this->V = V; 
	adj = new list<int>[V]; 
} 

//addEdge function 
//In this Function seperate list for each node is created and its connected edges are added in list
void Graph::add(int v, int w) 
{ 
	adj[v].push_back(w); 
} 

//BFS function for performing Breadth First Search operation
void Graph::BFS(int s,int m) 
{ 
	bool *visited = new bool[V]; //New boolean array is created
	for(int i = 0; i < V; i++) 
		visited[i] = false; //Array is initialized with false
 
	list<int> queue; //new list named queue is created

	visited[s] = true; //The current node is made true
	queue.push_back(s); //Starting node is added in queue

	list<int>::iterator i; //Iterator is used when we have to traverse a list

	while(!queue.empty()) //loop executes until queue becomes empty
	{ 
		s = queue.front();  //First element in queue is put into s(reffered to current node)
		cout<<" Visit city number "<<s+1<<endl; //display s(as S is now visited)
		if(s==m)       //if our current node is equal to node that we want to search than exit
		{
		
			return;
		} 
		cout<<"then "<<endl;
		queue.pop_front(); //Visited city is removed from queue

		for (i = adj[s].begin(); i != adj[s].end(); ++i) //iterator is looped through list of current node
		{ 
			if (!visited[*i]) // the node within list is not visited
			{ 
				visited[*i] = true; //make it visited
				queue.push_back(*i); //push it into queue
			} 
		} 
	} 
}

//DFSUtil function for performing Depth First Search operation
void Graph::DFSUtil(int v, bool visited[],int m)
{
    visited[v] = true; //Current node is now visited
    cout<<" Visit city number "<<v+1<<endl; //Current node is displayed
    if(v==m)//if our current node is equal to node that we want to search than exit
    {
    	cout<<"\n\n--------------------------Happy and Safe Journey----------------------------------"<<endl;
	cout<<"--------------------------Visit Soon------------------------------------------"<<endl;
	
    	exit(0);
	}
 	cout<<"then "<<endl;
    list<int>::iterator i; //Iterator is used when we have to traverse a list
    for (i = adj[v].begin(); i != adj[v].end(); ++i) //iterator is looped through list of current node
        if (!visited[*i]) // the node within list is not visited
            DFSUtil(*i, visited,m); //Recursively call DFSutil function and as pass not visited node as current one.
} 

//DFS function for performing Depth First Search operation
void Graph::DFS(int v,int m)
{
    bool* visited = new bool[V]; //New boolean array is created
    for (int i = 0; i < V; i++) 
        visited[i] = false; //Array is initialized with false
 
    DFSUtil(v, visited,m); //DFSUtil function is called
}

int main() 
{  

	cout<<"--------------------------Welcome Traveller--------------------------------\nWe will take you through "
	 <<"shortest path to reach your Destination \n\n";
	int c,e,n1,n2;
	cout<<"Enter Total number of cities"<<endl;
	cin>>c; //total number of nodes
	Graph g(c); //constructor gets called
	cout<<"Enter total number of connection(edges) between cities"<<endl;
	cin>>e;  //total number of edges in graph
	cout<<"Enter connection as follows : number of one city followed by number of city connected to it for "<<e<<" times"<<endl;
	for(int i=0;i<e;i++)
	{
	cin>>n1>>n2; //input each edge
	g.add(n1-1,n2-1); //call add function
	
	}
	int st,en;
	cout<<"Enter city number from where you want to start search\n";
	cin>>st;//Enter city number from where you want to start searching
	cout<<"Enter city number that you want to search\n";
	cin>>en;//Enter city number that you want to search
	cout << "Following is path you have to follow through Breadth First Search "
		<< "(starting from city "<<st<<" ) \n"; 
	g.BFS(st-1,en-1);//call BFS function
	cout<<endl<<endl<<endl;
	
	cout << "Following is path you have to follow through Depth First Search "
	<< "(starting from city "<<st<<" ) \n"; 
	g.DFS(st-1,en-1);  //call DFS function
	return 0; 
} 



/*Output:
Test Case 1:
--------------------------Welcome Traveller--------------------------------
We will take you through shortest path to reach your Destination

Enter Total number of cities
5
Enter total number of connection(edges) between cities
6
Enter connection as follows : number of one city followed by number of city connected to it for 6 times
1 2
1 4
2 3
2 5
3 4
3 5
Enter city number from where you want to start search
1
Enter city number that you want to search
5
Following is path you have to follow through Breadth First Search (starting from city 1 )
 Visit city number 1
then
 Visit city number 2
then
 Visit city number 4
then
 Visit city number 3
then
 Visit city number 5



Following is path you have to follow through Depth First Search (starting from city 1 )
 Visit city number 1
then
 Visit city number 2
then
 Visit city number 3
then
 Visit city number 4
then
 Visit city number 5


--------------------------Happy and Safe Journey----------------------------------
--------------------------Visit Soon------------------------------------------
Test Case 2:
--------------------------Welcome Traveller--------------------------------
We will take you through shortest path to reach your Destination

Enter Total number of cities
4
Enter total number of connection(edges) between cities
6
Enter connection as follows : number of one city followed by number of city connected to it for 6 times
1 2
1 3
2 3
3 1
3 4
4 4
Enter city number from where you want to start search
3
Enter city number that you want to search
2
Following is path you have to follow through Breadth First Search (starting from city 3 )
 Visit city number 3
then
 Visit city number 1
then
 Visit city number 4
then
 Visit city number 2



Following is path you have to follow through Depth First Search (starting from city 3 )
 Visit city number 3
then
 Visit city number 1
then
 Visit city number 2


--------------------------Happy and Safe Journey----------------------------------
--------------------------Visit Soon------------------------------------------
Test Case 3:
--------------------------Welcome Traveller--------------------------------
We will take you through shortest path to reach your Destination

Enter Total number of cities
4
Enter total number of connection(edges) between cities
6
Enter connection as follows : number of one city followed by number of city connected to it for 6 times
1 2
1 3
2 3
3 1
3 4
4 4
Enter city number from where you want to start search
1
Enter city number that you want to search
4
Following is path you have to follow through Breadth First Search (starting from city 1 )
 Visit city number 1
then
 Visit city number 2
then
 Visit city number 3
then
 Visit city number 4



Following is path you have to follow through Depth First Search (starting from city 1 )
 Visit city number 1
then
 Visit city number 2
then
 Visit city number 3
then
 Visit city number 4


--------------------------Happy and Safe Journey----------------------------------
--------------------------Visit Soon------------------------------------------


Test Case 4:
--------------------------Welcome Traveller--------------------------------
We will take you through shortest path to reach your Destination

Enter Total number of cities
5
Enter total number of connection(edges) between cities
5
Enter connection as follows : number of one city followed by number of city connected to it for 5 times
1 2
1 3
1 4
2 3
3 5
Enter city number from where you want to start search
1
Enter city number that you want to search
5
Following is path you have to follow through Breadth First Search (starting from city 1 )
 Visit city number 1
then
 Visit city number 2
then
 Visit city number 3
then
 Visit city number 4
then
 Visit city number 5



Following is path you have to follow through Depth First Search (starting from city 1 )
 Visit city number 1
then
 Visit city number 2
then
 Visit city number 3
then
 Visit city number 5


--------------------------Happy and Safe Journey----------------------------------
--------------------------Visit Soon------------------------------------------
*/


