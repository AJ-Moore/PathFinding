//Developed by Allan Moore 
//20/05/2011 - 2014 <-- Had it lying around.
//Might have grown slightly... 


#ifndef _VECTOR3_HEADER 
#define _VECTOR3_HEADER 

class Vector3f 
{


public: 
	Vector3f(); 
	Vector3f(float XValue, float YValue, float ZValue);
	//static Vector3f zero(); //returns a zero vector 

	//Operators 
	Vector3f& operator=(const Vector3f& val);
	Vector3f& operator()(const float& valx, const float& valy, const float& valz);
	const Vector3f operator+(const Vector3f& val) const;
	Vector3f operator+=(const Vector3f& val);
	Vector3f operator+=(const float& val);
	Vector3f operator-=(const Vector3f& val);
	Vector3f operator-=(const float& val);
	Vector3f& operator*=(const Vector3f& val);
	Vector3f& operator*=(const float& val); 
	Vector3f& operator/=(const Vector3f& val);
	const Vector3f operator+(const int& val) const;
	const Vector3f operator++() const;
	const Vector3f operator-(const Vector3f& val) const;
	const Vector3f operator-(const int& val) const;
	const Vector3f operator/(const Vector3f& val) const;
	const Vector3f operator/(const int& val) const;
	const Vector3f operator/(const float& val) const;
	const Vector3f operator*(const Vector3f& val) const;
	const Vector3f operator*(const int& val) const;
	const Vector3f operator*(const float& val) const;

	const bool operator>(const Vector3f& val) const;
	const bool operator<(const Vector3f& val) const;

	//=====================Operator methods to add && Possibly (totally un)Useful Note Section====================
	/* JOIN THE EASTER EGG HUNT! 
	//const Vector3f operator /=(const Vector3f& val) const; 
				<-- Looks like its been added mate.
				<-- Add overloads that take an int, not a total necessity but gets annoying when 
				<-- it complains because its the wrong type pointless casting waste of time.  
				<-- 3 people where here. 
				<-- Be the first of your friends to like this.
	//============================================================================================================
	*/

	float getMagnitude(); 

	Vector3f normalize();

	//streams 
	friend std::ostream& operator<< (std::ostream &out, Vector3f &val);

	//work out the cross vector.
	Vector3f cross(Vector3f& vector);

	static Vector3f cross(Vector3f vector1, Vector3f vector2);

	///returns the average of the vector values as a float X+Y+Z/ 3 
	float average();

	///Returns the distance between two vectors.
	float getDistance(Vector3f val);

	float x; 
	float y; 
	float z; 


};








#endif



