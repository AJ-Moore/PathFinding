#include "stdafx.h"
#include "Collider.h"


	void onCollisionDummy(){

	}

	Collider::Collider(){
		this->isColliding = false;
		this->onCollision = &onCollisionDummy;
		this->tag = "Collider";
	}

	Collider::~Collider(){

	}

	bool Collider::initialise(){
		return true; 
	}

	//Component based update & render 
	void Collider::update(){
	}

	void Collider::render(){
	}


	//Update all Physics stuff 
	void Collider::updatePhysics(){

	}

	//Debig rendering 
	void Collider::debugRender(){

	}

	bool Collider::checkCollision(Collider& collider){
		switch (collider.colliderType){
		case BOUNDING_BOX:
			return this->checkAABBCollision(collider);
		default:
			break;
		}
		
	
		return false;
	}



	bool Collider::checkAABBCollision(Collider& collider){
		return false;

	}

