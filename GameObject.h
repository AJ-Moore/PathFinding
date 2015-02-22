/*
	GameObject Class Declaration
	Dev By Allan Moore 04/2014
	21017984
	Buckinghamshire New University 
*/

//Developed by Allan Moore 


#ifndef _GAME_OBJECT_HEADER
#define _GAME_OBJECT_HEADER 

#include <map>
#include "Component.h"
#include "Collider.h"
#include "AABB.h"
#include "Vector3.h"

class GameObject{
public:
	GameObject(); 
	~GameObject(); 

	std::string name; 
	std::string tag; 

	virtual void load(); 
	virtual void unload(){} 
	virtual bool initialise(); 
	virtual void update();
	virtual void render(); 

	//OnCollision Callback// called by physics system when a collision between two colliders is detected. 
	//Its purposefully not dynamic didn't want to bloat the project too much with a parent collider class 
	//I could but I struggle to draw the line on whats too much. Its a sacrifice :(, would rather just return the colliders
	//On secound thoughts... (edit)
	virtual void onCollision(Collider& ColliderObj, Collider& CollidedObj); 


	//Initialise/ Update/ Render all Components attached to this gameobject.
	bool initialiseComponents(); 
	void updateComponents(); 
	void renderComponents();

	//Adds a component to the gameobject.
	void addComponent(Component* component);

	//Remove a component from the gameobject 
	void removeComponent(const int ComponentID);

	int getID(){
		return this->ID; 
	}

	//GameObject attributes 
	Vector3f position; 
	Vector3f rotation; 

	//for indexing primarily. 
	std::map<int, Component*>& getComponentMap();

private:
	//Keeps track of the number of components that have been added to the gameObject 
	int componentCount;
		
	///The GameObjects ID 
	int ID; 

	static int gameObjectCount; 
		
	//map of children --> Component ID, Component 
	std::map<int,Component*> componentMap;


};



#endif