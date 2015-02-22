//precompiled header.
#include "stdafx.h"

#include "PhysicsSystem.h"
#include "GameObject.h" 

PhysicsSystem::PhysicsSystem(){
	this->colliderCount = 0; 
}

PhysicsSystem ::~PhysicsSystem(){

}

bool PhysicsSystem::initialise(){
	return true; 
}

//Adds a collider to the physics system.
int PhysicsSystem::addCollider(Collider& collider){
	int id = this->colliderCount; 
	this->colliderCount++; 
	this->colliderMap.insert(std::make_pair(id,&collider));
		
	//std::cout<<colliderCount<<std::endl;
	return id; 
}

void PhysicsSystem::removeCollider(int ID){
	Collider* collider = this->colliderMap.find(ID)->second;

	if (collider != NULL){delete collider; collider = nullptr;}

	this->colliderMap.erase(ID);
}


//checks for collision between colliders in this physics system. 
void PhysicsSystem::checkForCollisions(){

	/*
		ColliderObj --> The collider were checking 
		CollisionObj --> The collider were checking to see whether a collision has happened against.

	*/

		
	//iterates through  the map and checks for collisions 
	for (std::map<int, Collider*>::const_iterator ColliderObj = this->colliderMap.begin(); ColliderObj != this->colliderMap.end(); ++ColliderObj){

		//holding a bool value to try and determine whether the collider has collided with anything.
		//if not then we can set its isColliding attribute to false
		bool hasCollided = false; 

		for (std::map<int, Collider*>::const_iterator CollisionObj = this->colliderMap.begin(); CollisionObj != this->colliderMap.end(); ++CollisionObj){
			//We don't want it to check to see if its collided with itself 
			if (ColliderObj != CollisionObj){

				//returns true on collision.
				bool CollisionDetected = ColliderObj->second->checkCollision(*CollisionObj->second);
				if (CollisionDetected){
					hasCollided = true;
						
					if (ColliderObj->second->parent != NULL){
						ColliderObj->second->parent->onCollision(*ColliderObj->second, *CollisionObj->second); 
					}

					//Calls the on collision static callback --. pretty useless at the moment 
					ColliderObj->second->onCollision();

					//std::cout<<"Collision Detected"<<std::endl;
				}
				else{
						
				}

			}

			//if it hasn't collided with anything then we set the collider property isColliding to false.
			if (!hasCollided){
				ColliderObj->second->isColliding = false; 
			}
			else{
				ColliderObj->second->isColliding = true;
			}

		}

	}

}

void PhysicsSystem::checkForCollisions(Collider& ColliderObj){
	bool hasCollided = false; 

	for (std::map<int, Collider*>::const_iterator CollisionObj = this->colliderMap.begin(); CollisionObj != this->colliderMap.end(); ++CollisionObj){
		//We don't want it to check to see if its collided with itself 
		if (ColliderObj.getID() != CollisionObj->second->getID()){
			//returns true on collision.
			bool CollisionDetected = ColliderObj.checkCollision(*CollisionObj->second);
			if (CollisionDetected){
				hasCollided = true;
						
				if (ColliderObj.parent != NULL){
					ColliderObj.parent->onCollision(ColliderObj, *CollisionObj->second); 
				}

				//Calls the on collision static callback --. pretty useless at the moment 
				ColliderObj.onCollision();
			}

		}

		//if it hasn't collided with anything then we set the collider property isColliding to false.
		if (!hasCollided){
			ColliderObj.isColliding = false; 
		}
		else{
			ColliderObj.isColliding = true;
		}

	}
}

//Main update for the physics system. <-- Needs to be called...
void PhysicsSystem::update(){

	this->checkForCollisions(); 

}

void PhysicsSystem::render(){

}


