#include "stdafx.h"
#include "AABB.h"
#include "GameObject.h"
//#include "neMath.h"


	AABB::AABB(){
		this->colliderType = colliderType::BOUNDING_BOX; 
		this->vecMax = Vector3f(0.5,0.5,0.5); 
		this->vecMin = Vector3f(-0.5,-0.5,-0.5); 
	}
	AABB::AABB(Vector3f Min, Vector3f Max){
		this->colliderType = colliderType::BOUNDING_BOX;
		this->vecMax = Max; 
		this->vecMin = Min; 
	}

	AABB::~AABB(){
	}

	Vector3f AABB::getGlobalPosition(){
		if (this->parent != nullptr)
			return this->position +this->parent->position; 

		return this->position; 
	}

	///Returns true if there is a collision between the AABB and collider passed in.
	bool AABB::checkAABBCollision(Collider& collider){
		//check collider type 
		if (collider.colliderType != colliderType::BOUNDING_BOX)
			this->checkAABBCollision(collider); 

		//Seems safe enough D:
		AABB* AABBCollider = (AABB*)&collider; 

		Vector3f Position;
		
		Vector3f thisPosition = this->getGlobalPosition(); 
		Vector3f aabbPosition = AABBCollider->getGlobalPosition();

		if (thisPosition.x + this->vecMin.x < aabbPosition.x + AABBCollider->vecMax.x && 
			thisPosition.y + this->vecMin.y < aabbPosition.y + AABBCollider->vecMax.y && 
			thisPosition.z + this->vecMin.z < aabbPosition.z + AABBCollider->vecMax.z && 
			thisPosition.x + this->vecMax.x > aabbPosition.x + AABBCollider->vecMin.x && 
			thisPosition.y + this->vecMax.y > aabbPosition.y + AABBCollider->vecMin.y && 
			thisPosition.z + this->vecMax.z > aabbPosition.z + AABBCollider->vecMin.z)
		{

				return true;
		}
		else{
			return false; 
		}

	}
