/*
	Node Class Declaration
	Dev By Allan Moore 04/2014
	21017984
	Buckinghamshire New University 
*/

#ifndef _NODE 
#define _NODE

//precompiled headers 
#include "stdafx.h"
#include "AABB.h"
#include "GameObject.h"
#include "Spell.h"
#include "LinkedList.h"

class Node : public GameObject{
public:
	char data;

	bool wasVisited; 
	bool isInTree; 

	AABB* boundingBox; 

	Node(){
		
	}
	Node(char c);
	Node::Node(char c, Vector3f position);
	Node(const Node &Obj);//Copy Constructor//problematic without// based on current implementation.
	~Node();

	//adds a spell to the list of spells
	void addSpell(Spell* spell){
		this->spells.insert(spell);
	}

	LinkedList<Spell> spells;

	char getData();

	void display();

	//create the bounding box used by this node
	virtual void load();
	

};


#endif 