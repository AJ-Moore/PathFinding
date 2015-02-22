//precompiled headers 
#include "stdafx.h"

#include "Player.h"
#include "Game.h"

Player::Player(){
	this->name = "PLAYER"; 
	this->tag = "PLAYER";
	this->graph = nullptr; 
	this->speed = 0.1; 
	this->targetReached = false; 
}

Player::Player(Graph* graph){
	this->name = "PLAYER"; 
	this->tag = "PLAYER";
	this->graph = graph; 
	this->speed = 0.1; 
	this->targetReached = false; 
}

Player::~Player(){

}

void Player::load(){
	this->boundingBox = new AABB(); 
	this->addComponent(this->boundingBox);
	Game::physicsSystem->addCollider(*this->boundingBox); 
}

void Player::unload(){
}

bool Player::initialise(){
	//get the players path and store it players stack.  
	this->graph->path();
	this->nodeStack = this->graph->getPath('0');
	return true;
}

void Player::update(){
	//update player movement. 
	this->updateMovement();

	if(this->targetReached){
		this->printSpells(); 
		Game::isRunning = false; 
	}
}

///Does the job.. 
void Player::updateMovement(){
	//If there are nodes in the stack 
	if (!this->nodeStack->isEmpty()){
		Vector3f direction = (this->nodeStack->peek().position - this->position);
		direction = direction.normalize();
		this->position += direction * this->speed; 
	}
}

void Player::printSpells(){
	std::cout<<"================PLAYER SPELLS================="<<std::endl;
	this->spells.display();
	std::cout<<"=============================================="<<std::endl;
}

//unused. 
void Player::render(){
}

void Player::onCollision(Collider& ColliderObj, Collider& CollidedObj){
	if (!this->nodeStack->isEmpty()){
		if (CollidedObj.parent->tag[0] == this->nodeStack->peek().getData()){
			std::cout<<"Node Reached Node Num: "<< this->nodeStack->peek().getData()<<std::endl; 
			//remove the node from the stack as it has been reached 

			//potencially unsafe.
			Node p = this->nodeStack->pop(); 
			//Add spells to player. 
			this->spells.insert(p.spells.remove(0));
		}
	}
	else{
		//reached target.
		this->targetReached = true; 
	}
}
