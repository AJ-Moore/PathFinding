/*
	Collider Class Declaration
	Dev By Allan Moore 04/2014
	21017984
	Buckinghamshire New University 
*/

#ifndef _COLLIDER
#define _COLLIDER

#include "Component.h"

enum colliderType {
	BOUNDING_BOX
};

typedef void (*onCollisionFunc)(); 

class Collider : public Component{
public:
	//Constructors/ destructors 
	Collider();
	~Collider();

	//Other Public Member 
	virtual bool initialise();

	//Component Based updates <<-- declared in component 
	virtual void update(); 
	virtual void render(); 

	//Physics Based updates <<-- Called by Physics System 
	virtual void updatePhysics(); 
	virtual void debugRender();

	//Checks for collision between colliders//made public incase whomever is creating the game wants to explicitly check for a collision between colliders
	virtual bool checkCollision(Collider& collider);
	virtual bool checkAABBCollision(Collider& collider); 

	//Collider type <-- helps Identify what type of collider we are dealing with when checking for collisions.
	colliderType colliderType; 

	//whether the collider is colliding with anything.
	bool isColliding;
	//The angle of collision from the last recieved collision.
	float collisionAngle;

	//OnCollision function pointer --> Called when a collision is detected.
	onCollisionFunc onCollision;
	//onCollisionFuncParam onCollision; 

};


#endif 