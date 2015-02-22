#include "stdafx.h"
#include "Game.h"
#include "Node.h"
#include "Vector3.h"

	Node::Node(char c):data(c){
		this->boundingBox = nullptr; 
		this->wasVisited = false; 
		this->isInTree = false; 
		this->position = Vector3f(0,0,0);
	}

	Node::Node(char c, Vector3f position):data(c){
		this->boundingBox = nullptr; 
		this->wasVisited = false; 
		this->isInTree = false; 
		this->position = position;
	}

	Node::~Node(){
		//std::cout<<this->data<<"Deleted"<<std::endl;	
		//if (!this->boundingBox){delete this->boundingBox; this->boundingBox = nullptr;} //Whos in charge of this.
	}


	Node::Node(const Node &Obj){
		this->boundingBox = Obj.boundingBox;
		this->data = Obj.data;
		this->wasVisited = Obj.wasVisited; 
		this->isInTree = Obj.isInTree; 
		this->position = Obj.position;
		this->spells = Obj.spells;
	}

	char Node::getData(){
		return this->data; 
	}

	void Node::display(){
		std::cout << this->data << std::endl;

	}

	//create the bounding box used by this node
	void Node::load(){
		//create the bounding box--> adds to the games physics system. 
		this->boundingBox = new AABB(); 
		///to make life simpler tag the AABB with the data-> node number, name, whatever.
		this->tag = "0";
		this->tag[0] = this->data; 

		Game::physicsSystem->addCollider(*this->boundingBox); 
		this->addComponent(this->boundingBox);//Add the component to the gameObject 
	}