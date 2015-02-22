/* The Game Will Continue to run until the player reaches the target node -> After outputting their inventory*/
#include "stdafx.h"

#include "Game.h" 

//Static Members 
bool Game::isRunning = false; 
PhysicsSystem* Game::physicsSystem = new PhysicsSystem();

Game::Game(){

}

Game::~Game(){

}

//Used for primarily allocating data 
void Game::load(){
	this->graph = new Graph(6);
	this->player = new Player(this->graph); 
	this->player->load();
	   
}

//Used for unloading data and cleaning up a little bit. the destructor should be used to clean up memory though!!  
void Game::unload(){

}

void Game::initialise(){
	//Create nodes 
	Node* node0 = new Node('0',Vector3f(0,0,0));
	Node* node1 = new Node('1',Vector3f(10,10,0));
	Node* node2 = new Node('2',Vector3f(10,-10,0));
	Node* node3 = new Node('3',Vector3f(20,-10,0));
	Node* node4 = new Node('4',Vector3f(20,10,0));
	Node* node5 = new Node('5',Vector3f(30,0,0));

	//add spells to nodes 
	node0->addSpell(new Spell("Fall in Love", ""));
	node1->addSpell(new Spell("Grow Old", ""));
	node2->addSpell(new Spell("Turn into frog", ""));
	node3->addSpell(new Spell("Acquire super human strength", ""));
	node4->addSpell(new Spell("Regain youth", ""));
	node5->addSpell(new Spell("Perform well in exams", ""));

	//add nodes to graph 
	this->graph->addNode(node0);
    this->graph->addNode(node1);
    this->graph->addNode(node2);
    this->graph->addNode(node3);
    this->graph->addNode(node4);
    this->graph->addNode(node5);

    this->graph->addEdge(0, 1, 2);
    this->graph->addEdge(0, 2, 4);

    this->graph->addEdge(1, 2, 1);
    this->graph->addEdge(1, 3, 4);
    this->graph->addEdge(1, 4, 2);

    this->graph->addEdge(2, 4, 3);

    this->graph->addEdge(3, 5, 2);

	this->graph->addEdge(4, 5, 2);
	
	this->player->initialise();

}

void Game::update(){

	//Checks for collisions// hint calls players onCollision when a node is hit->
	Game::physicsSystem->update(); 
	this->player->update();


}

void Game::render(){
	this->player->render();
}

