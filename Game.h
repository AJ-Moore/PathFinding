/*
	Game Class Declaration
	Dev By Allan Moore 04/2014
	21017984
	Buckinghamshire New University 

	Centeral Point for Application -> Called from main (:
*/
#ifndef _GAME
#define _GAME

#include "PhysicsSystem.h"
#include "Player.h"
#include "Graph.h"

class Player;
class Graph; 

class Game{
public:
	Game(); 
	~Game(); 

	virtual void load(); 
	virtual void unload(); 
	virtual void initialise(); 
	virtual void update(); 
	virtual void render();//not really used but...

	static bool isRunning; 

	//static physics system 
	static PhysicsSystem* physicsSystem; 

private:
	Graph* graph; //will hold a reference to the graph that will be used by the player. 
	Player* player; //The Player. 

};


#endif