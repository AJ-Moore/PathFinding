#include "stdafx.h"
#include "Component.h"



int Component::componentCount = 0; 

//constructor 
Component::Component(){
	this->parent = nullptr; 
	this->name = "Component";
	Component::componentCount++;
	this->ID = Component::componentCount; 
}

//destructor 
Component::~Component(){
}

//Should be called when we want to intialise the component...  
bool Component::initialise(){

	return true; 
}

//Renders the component 
void Component::render(){

}

void Component::debugRender(){

}

//Updates the component 
void Component::update(){

}

int Component::getID(){
	return this->ID;
}



