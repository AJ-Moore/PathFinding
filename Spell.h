/*
	Spell Class Declaration
	Dev By Allan Moore 04/2014
	21017984
	Buckinghamshire New University 
*/
#ifndef _SPELL 
#define _SPELL

class Spell{
public:
	Spell(char* Name, char* Description){
		this->name = Name; 
		this->description = Description; 
		this->next = nullptr; 
	}

	void display(){
		std::cout<<"Spell Name: "<< this->name <<std::endl;
	}

	char* name; 
	char* description;

	Spell* next;
};

#endif 