/*
	Physics System Class Declaration
	Dev By Allan Moore 04/2014
	21017984
	Buckinghamshire New University 
*/
//Physics System
//Holds a collection of colliders and checks for collisions between them.
//SIMPLE BRUTE FORCE COLLISION DETECTION SYSTEM. 

#ifndef _PHYSICS_SYS
#define _PHYSICS_SYS

#include <map>
#include "Collider.h"

class PhysicsSystem{
public:
	//Constructors/ destructors 
	PhysicsSystem();
	~PhysicsSystem();

	//Other Public Member 
	virtual bool initialise(); //Initialise physics system 
	virtual void update(); //calls all colliders to update 
	virtual void render(); //Calls all colliders to render 

	///Adds a collider to the physics system 
	int addCollider(Collider& collider);
	void removeCollider(int ID); 

	///pass in a collider to see if it's colliding with anything in the engine, used by rigidbodies to see whether they will collide with anything during the next timestep(Not in this application sorry, maybe next time).
	void checkForCollisions(Collider& collider);

	//keeps track of the number of colliders that have been added to this physics system 
	int colliderCount; 

private:
	void checkForCollisions(); //Checks to see whether any of the colliders attached to the physics system have collided 


	//Maps containing all colliders in physics system.SLOW TRY --> VECTOR's FOR ACTUAL CHECKING <--TODO. OCT TREES ALREADY!? 
	std::map<int,Collider*> colliderMap;

};

#endif 