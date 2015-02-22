/*
	AABB Class Declaration
	Dev By Allan Moore 04/2014
	21017984
	Buckinghamshire New University 
*/
//Very Simple AABB CLASS 

#ifndef _AABB
#define _AABB

#include "Vector3.h"
#include "Collider.h"

class AABB : public Collider{
public:
	AABB();
	AABB(Vector3f min, Vector3f max);
	~AABB(); 


	///Returns true if there is a collision between the AABB and collider passed in.
	virtual bool checkAABBCollision(Collider& collider); 

	//simple function that adds the position to the parents position if there is one 
	Vector3f getGlobalPosition(); 

private:
	Vector3f vecMin; 
	Vector3f vecMax; 
		
};



#endif