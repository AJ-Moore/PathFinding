


#include "stdafx.h"
#include <math.h> 
#include "Vector3.h"
	
//default constructor 
Vector3f::Vector3f()
{
	this->x = 0; 
	this->y = 0; 
	this->z = 0; 
}

//Constrcutor
Vector3f::Vector3f(float X, float Y, float Z){
	this->x = X;
	this->y = Y; 
	this->z = Z; 
}

Vector3f& Vector3f::operator=(const Vector3f& val){
	
	//check for self assignment
	if(this == &val)
	{
		return *this;
	}

	this->x = val.x;
	this->y = val.y; 
	this->z = val.z;

	return *this;
}

Vector3f& Vector3f::operator()(const float& valx, const float& valy, const float& valz){

	this->x = valx;
	this->y = valy; 
	this->z = valz;

	return *this;
}

const Vector3f Vector3f::operator+(const Vector3f& val) const{

	Vector3f newVector(0,0,0); 
	newVector.x = this->x + val.x; 
	newVector.y = this->y + val.y; 
	newVector.z = this->z + val.z; 

	return newVector; 
}

Vector3f Vector3f::operator+=(const Vector3f& val){

	this->x += val.x; 
	this->y += val.y; 
	this->z += val.z; 

	return *this; 
}

Vector3f Vector3f::operator+=(const float& val){

	this->x += val; 
	this->y += val; 
	this->z += val; 

	return *this; 
}

Vector3f Vector3f::operator-=(const Vector3f& val){

	this->x -= val.x; 
	this->y -= val.y; 
	this->z -= val.z; 

	return *this; 
}

Vector3f Vector3f::operator-=(const float& val){

	this->x -= val; 
	this->y -= val; 
	this->z -= val; 

	return *this; 
}

Vector3f& Vector3f::operator*=(const Vector3f& val){
	this->x *= val.x;
	this->y *= val.y;
	this->z *= val.z;

	return *this;
}

Vector3f& Vector3f::operator*=(const float& val){
	this->x *= val; 
	this->y *= val; 
	this->z *= val;

	return *this; 
}

Vector3f& Vector3f::operator/=(const Vector3f& val){
	this->x /= val.x;
	this->y /= val.y; 
	this->z /= val.z;

	return *this; 
}

//will uniformally add a given value to the vector
const Vector3f Vector3f::operator+(const int& val) const{

	Vector3f newVector(0,0,0); 
	newVector.x = this->x + val; 
	newVector.y = this->y + val; 
	newVector.z = this->z + val; 

	return newVector; 

}

const Vector3f Vector3f::operator++() const{

	Vector3f newVector(0,0,0); 
	newVector.x = this->x + 1; 
	newVector.y = this->y + 1; 
	newVector.z = this->z + 1; 

	return newVector; 

}

const Vector3f Vector3f::operator-(const Vector3f& val) const{

	Vector3f newVector(0,0,0); 
	newVector.x = this->x - val.x; 
	newVector.y = this->y - val.y; 
	newVector.z = this->z - val.z; 

	return newVector; 
}

//uniformally subtracts a value 
const Vector3f Vector3f::operator-(const int& val) const{
	
	Vector3f newVector(0,0,0); 
	newVector.x = this->x - val; 
	newVector.y = this->y - val; 
	newVector.z = this->z - val; 

	return newVector; 

}

const Vector3f Vector3f::operator/(const Vector3f& val) const{
	
	Vector3f newVector(0,0,0); 
	newVector.x = this->x / val.x; 
	newVector.y = this->y / val.y; 
	newVector.z = this->z / val.z; 

	return newVector; 
}

const Vector3f Vector3f::operator/(const int& val) const{
	
	Vector3f newVector(0,0,0); 
	newVector.x = this->x / val; 
	newVector.y = this->y / val; 
	newVector.z = this->z / val; 

	return newVector; 

}

const Vector3f Vector3f::operator/(const float& val) const{
	Vector3f newVector(0,0,0); 
	newVector.x = this->x / val; 
	newVector.y = this->y / val; 
	newVector.z = this->z / val; 

	return newVector; 
}

const Vector3f Vector3f::operator*(const Vector3f& val) const{
	Vector3f newVector(0,0,0); 
	newVector.x = this->x * val.x; 
	newVector.y = this->y * val.y; 
	newVector.z = this->z * val.z; 

	return newVector; 
}

const Vector3f Vector3f::operator*(const int& val) const{
	
	Vector3f newVector(0,0,0); 
	newVector.x = this->x * val; 
	newVector.y = this->y * val; 
	newVector.z = this->z * val; 

	return newVector; 

}

const Vector3f Vector3f::operator*(const float& val) const{
	
	Vector3f newVector(0,0,0); 
	newVector.x = this->x * val; 
	newVector.y = this->y * val; 
	newVector.z = this->z * val; 

	return newVector; 

}

std::ostream& operator<< (std::ostream &out, Vector3f &val){
	out << "Vector3f: " << val.x <<","<<val.y<<","<<val.z<<std::endl; 
    return out;
}

const bool Vector3f::operator>(const Vector3f& val) const{
	if (this->x > val.x && 
		this->y > val.y && 
		this->z > val.z)
	{
			return true; 
	}
	else{
		return false; 
	}
}
const bool Vector3f::operator<(const Vector3f& val) const{
	if (this->x < val.x && 
		this->y < val.y && 
		this->z < val.z)
	{
			return true; 
	}
	else{
		return false; 
	}
}

float Vector3f::getDistance(Vector3f val){
	Vector3f diff = *this;
	diff -= val;

	return sqrt(((diff.x * diff.x) + (diff.y * diff.y))+(diff.z*diff.z));
}

Vector3f Vector3f::cross(Vector3f& vector){

	Vector3f cross;
	cross.x = this->y * vector.z - this->z * vector.y;
	cross.y = this->z * vector.x - this->x * vector.z;
	cross.z = this->x * vector.y - this->y * vector.x;

	return cross;
}

///Static method... can't remember why? oh yeh of course duh...but is it necessary... <--Ignore this whole additional comment <-- and this :/
Vector3f Vector3f::cross(Vector3f vector1, Vector3f vector2){
	Vector3f cross;
	cross.x = vector1.y * vector2.z - vector1.z * vector2.y;
	cross.y = vector1.z * vector2.x - vector1.x * vector2.z;
	cross.z = vector1.x * vector2.y - vector1.y * vector2.x;

	return cross;
}

float Vector3f::average(){
	return((this->x + this->y + this->z)/3);
}

float Vector3f::getMagnitude(){
	return (float)sqrt((this->x * this->x) + (this->y * this->y) + (this->z * this->z));
}

Vector3f Vector3f::normalize(){

	if (this->getMagnitude() == 0){
		return Vector3f(0,0,0);
	}
	Vector3f vec(this->x,this->y,this->z);
	return (vec/this->getMagnitude()); 


}