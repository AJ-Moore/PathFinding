/*
	Player Class Declaration
	Dev By Allan Moore 04/2014
	21017984
	Buckinghamshire New University 
*/

#ifndef _PLAYER 
#define _PLAYER

#include "Graph.h"
#include "Stack.h"
#include "Node.h"
#include "LinkedList.h"
#include "Spell.h"
#include "GameObject.h"

class Graph; 
class Node; 

class Player : public GameObject{
public: 
	Player();
	Player(Graph* graph); 
	~Player(); 
	virtual void load(); 
	virtual void unload();
	virtual bool initialise(); 
	virtual void update();
	virtual void render(); 

	void updateMovement(); 

	virtual void onCollision(Collider& ColliderObj, Collider& CollidedObj); 

	//A stack of nodes yet unreached by the player.  
	Stack<Node>* nodeStack; 
private: 
	Graph* graph; //a reference to the graph the player wil be following.
	AABB* boundingBox; 

	//whether the target node has been reached. 
	bool targetReached; 

	LinkedList<Spell> spells;

	//used to print the spells the player has picked up in the console. 
	void printSpells();

	//Units/secound traveled. 
	float speed;
};

#endif 