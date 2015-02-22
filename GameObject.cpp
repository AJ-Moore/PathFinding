// GameObject Class
// Game Objects are used to group together components.

//precompiled header 
#include "stdafx.h"

#include "GameObject.h" 

int GameObject::gameObjectCount = 0; 

//Constructor 
GameObject::GameObject(){
	this->componentCount = 0; 
	this->name = "GameObject"; 
	this->tag = "Default"; 
	this->gameObjectCount++;
	this->ID = this->gameObjectCount; 
}

GameObject::~GameObject(){
	///Itterates through components and destroys them. 
	for (std::map<int, Component*>::iterator iter = this->componentMap.begin(); iter != this->componentMap.end(); ++iter){
		delete iter->second;
		iter->second = nullptr;
	}
}

void GameObject::load(){

}

///Used for instialising the GameObject <<-- Virtual 
bool GameObject::initialise(){
	return true; 
}

//Update the gameobject 
void GameObject::update(){
}

//render the gameobject 
void GameObject::render(){
}

//pretty much a dummy function 
void GameObject::onCollision(Collider& ColliderObj, Collider& CollidedObj){
}

/// Intialises all Components attached to this GameObject 
bool GameObject::initialiseComponents(){
	bool success = true; 
	//Updates all components in map 
	for (std::map<int, Component*>::const_iterator component = this->componentMap.begin(); component != this->componentMap.end(); ++component){
		if (!component->second->initialise()){
			success = false;
		}
	}

	return success; 
}

//Update Components attached to this GameObject. 
void GameObject::updateComponents(){
	//Updates all components in map 
	for (std::map<int, Component*>::const_iterator component = this->componentMap.begin(); component != this->componentMap.end(); ++component){
		component->second->update();
	}
}

//render Components attached to this GameObject. 
void GameObject::renderComponents(){
	//Renders all components in map//I Know MAPS ARE SLOW right. It was supposed to just be used for indexing. 
	for (std::map<int, Component*>::const_iterator component = this->componentMap.begin(); component != this->componentMap.end(); ++component){
			component->second->render();
	}
		
}


//Adds a component to the GameObject. And generates an Id for the component. 
void GameObject::addComponent(Component* component){
	component->parent = this; 
	this->componentMap.insert(std::make_pair(component->getID(), component)); 
	this->componentCount++; 
}

//Remove A component from the gameObject using ID 
void GameObject::removeComponent(const int ComponentID){
	//Removes the component by ID.
	this->componentMap.erase(ComponentID);
}

std::map<int, Component*>& GameObject::getComponentMap(){
	return this->componentMap;
}



