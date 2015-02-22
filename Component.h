/*
	Component Class Declaration
	Dev By Allan Moore 04/2014
	21017984
	Buckinghamshire New University 
*/
//Componenet Class from which all components inherit.

#ifndef _COMPONENT
#define _COMPONENT

#include "Vector3.h"


class GameObject;

class Component{
public:
	//Constructors/ destructors 
	Component();
	~Component();

	//Other Public Member 
	virtual bool initialise();///<called to initialises the component
	virtual void update(); ///<Called to update the component
	virtual void render(); ///<called to render the component 
	virtual void debugRender();///<called by engine when in debug mode TODO!!!

	///returns the ID of the component
	int getID();

	Vector3f position;///<The components position in the scene 

	///Parent Game Object 
	GameObject* parent; 

	char* tag; ///Tag to identify the component 
	char* name; //the name of the compnent //

protected:
	//Holds the type of the component
	//ComponentType type; 

private:
	int ID;///<The components unique ID.
	static int componentCount;


};

#endif 