
//precompiled headers. 
#include "stdafx.h"

//Other headers.
#include "Graph.h" 

Graph::Graph(){

}

Graph::Graph(int Size){
	this->size = Size; 

	this->numNodes = 0; 

	this->nodeList = new Node*[size]; 

	//Create the 2d array. 
	adjMat = new int*[size];

	//Initialise the 2D array; 
	for (int i = 0; i < this->size; i++){
		this->adjMat[i] = new int[Size]; 
	}

	for (int p = 0; p < this->size; p++){
		for (int i = 0; i < this->size; i++){
			this->adjMat[p][i] = this->INFINITY;
		}
	}
	
	this->stack = new Stack<int>(Size);

	nTree = 0; 
	shortestPath = new DistanceParent*[size];


}

void Graph::addNode(Node* Node){
	this->nodeList[this->numNodes] = Node; 
	Node->load();
	this->numNodes++;
}

void Graph::addEdge(int StartNode, int EndNode){
	this->adjMat[StartNode][EndNode] = 1;
}

void Graph::addEdge(int StartNode, int EndNode, int Weight){
	this->adjMat[StartNode][EndNode] = Weight; 
}

void Graph::display(){
	for (int i = 0; i < this->numNodes; i++){
		this->nodeList[i]->display(); 
	}
}

void Graph::display(int Node){
	this->nodeList[Node]->display(); 
}

/*
**returns an unvisted node of the node passed in, 
**if there is any otherwise returns -1
*/
int Graph::getAdjUnvisitedNode(int Node){
	for (int unvisiedNode = 0; unvisiedNode < this->numNodes; unvisiedNode++){
		//If there is an ajacent node and it has yet to be visited.
		if (this->adjMat[Node][unvisiedNode] == 1 && this->nodeList[unvisiedNode]->wasVisited == false)
			return unvisiedNode;
		return -1; 	
	}
}

void Graph::dfs(){
	//Call dfs - set node 0 as start node..
	this->dfs(0);
}

void Graph::dfs(int Start){
	//Set the start node as the node passsed into the method.
	this->nodeList[Start]->wasVisited = true; 
	this->display(Start);//calls display on current node. 
	this->stack->push(Start);
	while (this->stack->getCount() > 0){
		int _node = this->getAdjUnvisitedNode(this->stack->peek());
		if (_node == -1)
			this->stack->pop(); 
		else{
			this->nodeList[_node]->wasVisited = true; 
			this->display(_node); 
			this->stack->push(_node); 
		}
	}

	for (int _node = 0; _node <this->numNodes; _node++)
		this->nodeList[_node]->wasVisited = false; 

}



int Graph::getMin(){
	
	int minDist = this->INFINITY; 
	int indexMin = 0; 

	for (int i = 1; i < this->numNodes; i++){
		//if the node is in the tree and has a lower weight than previous.
		if (!this->nodeList[i]->isInTree && this->shortestPath[i]->weight < minDist){
			minDist = this->shortestPath[i]->weight;
			indexMin = i;
		}
	}
	return indexMin;
}


// Display contents of sPath
void Graph::displayPaths(){
	for(int j = 0; j <this->numNodes; j++){
		std::cout << this->nodeList[j]->data << "=";
		if(this->shortestPath[j]->weight == INFINITY)
			std::cout << "inf";
		else
			std::cout << this->shortestPath[j]->weight;
		char parent = this->nodeList[shortestPath[j]->parentNodeIndex]->data;
		std::cout << "( Via : " <<  parent << ")" << std::endl;
	}
	std::cout << std::endl;
} 

// Updates sPath entries to reflect new information abtained from the node
// just inserted into the tree
void Graph::adjustPath() {
            // Skip starting node
            int column = 1;
            // Go across columns
			while (column < this->numNodes) {
                // If this column's node is already in the tree, skip it
                if (this->nodeList[column]->isInTree) {
                    column++;
                    continue;
                }
                // Calculate distance for one sPath entry
                // Get edge from current node to column
                int currentToFringe = this->adjMat[currentNode][column];
                // Add distance from start
                int startToFringe = startToCurrent + currentToFringe;
                // Get distance of current sPath entry
                int sPathDist = shortestPath[column]->weight;
                // Compare distance from start with sPath entry
                if (startToFringe < sPathDist) {
                    // Update sPath
                    shortestPath[column]->parentNodeIndex = currentNode;
                    shortestPath[column]->weight = startToFringe;
                }
                column++;
            }
 }

// Implements the shortest path algorithm
 // Finds all the shortest paths
 void Graph::path() {
	// Start at node 0
	int startTree = 0;

	// Put it in the tree
	nodeList[startTree]->isInTree = true;
	nTree = 1;
	// Transfer row of distances from adjacent matrix to sPath array
	for (int j = 0; j < this->numNodes; j++) {
		int tempDist = adjMat[startTree][j];
		shortestPath[j] = new DistanceParent(startTree, tempDist);
	}
	// Until all the nodes are in the tree
	while (nTree < this->numNodes) {
		// Get the minimum distance from sPath array
		int indexMin = this->getMin();
		int minDist = this->shortestPath[indexMin]->weight;
		// If all the distances are infinite
		if (minDist == INFINITY) { 
			std::cout << "There are possibly unreachable nodes" << std::endl;
			break;
		}
		else {
			// Reset current node to the closest node
			currentNode = indexMin;
			startToCurrent = shortestPath[indexMin]->weight;
		}
		// Put current node into tree
		nodeList[currentNode]->isInTree = true;
		nTree++;
		//Update sPath array
	
	
		this->adjustPath();
	}
            
	// Display contents of sPath
	//this->displayPaths(); meh 

	// Clear tree
	this->nTree = 0;
	for (int j = 0; j < this->numNodes; j++){
		nodeList[j]->isInTree = false;
	}
}



void Graph::displayShortestPath(){
	std::cout << std::endl;
	for (int j = 0; j < this->numNodes; j++)
         std::cout << shortestPath[j]->parentNodeIndex << " : ";
}

Stack<Node>* Graph::getPath(char start){
	Stack<Node> *route = new Stack<Node>(10);
	// Assumming last Node is our destination
	route->push(*nodeList[this->numNodes-1]);
	// Get the Destimation's parent - 
	route->push(*nodeList[shortestPath[this->numNodes - 1]->parentNodeIndex]);
	// Assign parent
	Node next = route->peek();
	int i = 0;
	// Starting at begining iterate through nodeList
	while(true){   
		// Is this the last Node that was pushed on Stack's parent.
		if (next.data == nodeList[i]->data){
            next = *nodeList[shortestPath[i]->parentNodeIndex];
            route->push(*nodeList[shortestPath[i]->parentNodeIndex]);
			// Start loop from beinging
            i = 0;
        }
        else {
			// Try next node in nodeList
            i++;
        }
		// If start Node reached then job done.
		if(next.data == start){
            break;
        }
    }

	next = 0;
        
    /*std::cout << "*** Route Start*** " << std::endl;
    while (route->getCount() > 0) {
        Node n = route->pop();
        std::cout << n.data  << std::endl;
    }
    std::cout << "*** Route End *** " << std::endl;*/

    return route;
}