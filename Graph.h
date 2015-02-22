
#ifndef _GRAPH
/*
	Graph Class Declaration
	Dev By Allan Moore 04/2014
	21017984
	Buckinghamshire New University 
*/

#define _GRAPH 

#include "Stack.h"
#include "Node.h"
#include "DistantParent.h"

class Graph {
public:
	Graph(int Size); 
	void addNode(Node* Node); 
	void addEdge(int StartNode, int EndNode); 
	void addEdge(int startNode, int EndNode, int weight); 

	void adjustPath(); 
	void displayShortestPath(); 
	Stack<Node>* getPath(char start); 

	void display(); 
	void display(int Node);

	int getAdjUnvisitedNode(int Node);

	void dfs(); 
	void dfs(int Start); 
		void displayPaths(); 
	void path();

private:
	Graph();
	int getMin();


	int numNodes; 

	int nTree;
	int currentNode; 
	int startToCurrent; 

	Node** nodeList;
	int** adjMat; 
	Stack<int>* stack; 
	DistanceParent **shortestPath;

	int size;//the size of the graph.


	static const int INFINITY = 1000000;




};


#endif 