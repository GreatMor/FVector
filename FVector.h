#pragma once
#include <iostream>
#include <string>  
#include <iosfwd>
#include <sstream>

template<class T>
struct FVector
{

	FVector();
	FVector(T InF);
	FVector(T InX, T InY, T InZ);
	
	//Constants
	static const FVector LeftVector;
	static const FVector RightVector;
	static const FVector DownVector;
	static const FVector ForwardVector;
	static const FVector BeckwardVector;
	static const FVector OneVector;
	static const FVector ZeroVector;

	///Operators

	//Get a negated copy of the vector.
	FVector  operator-();
	
	//Gets the result of component - wise subtraction of this by another vector.
	FVector operator- (const FVector& v);

	//Gets the result of subtracting from each component of the vector.
	FVector operator- (T InF);

	//Get a negated copy of the vector.
	bool operator != (const FVector& v);

	//Gets the result of component - wise multiplication of this vector by another.
	FVector operator* (const FVector& v );

	//Gets the result of scaling the vector(multiplying each component by a value).
	FVector operator* (float scale);

	//Multiplies the vector with another vector, using component-wise multiplication.
	FVector operator*= (const FVector& v);

	//Scales the vector.
	FVector operator*= (float scale);

	//Gets the result of dividing each component of the vector by a value.
	FVector operator/ (const FVector& v);

	//Gets the result of dividing each component of the vector by a value.
	FVector operator/ (float scale);

	//Divides the vector by a number.
	FVector operator/= (float scale);

	//Divides the vector by another vector, using component-wise division.
	FVector operator/= (const FVector& v);

	//Gets specific component of the vector.
	T& operator[] (int index);

	//Gets specific component of the vector.
	T operator[] (int index)const;

	//Calculate cross product between this and another vector.
	FVector operator^ (const FVector& v);

	//Calculate the dot product between this and another vector.
	T operator| (FVector& v);

	//Gets the result of component-wise addition of this and another vector.
	FVector operator+ (const FVector& v);

	//Gets the result of adding to each component of the vector.
	FVector operator+ (T InF);

	//Check against another vector for equality.
	bool operator== (FVector& v);

	///Functions
	std::string ToString();

	void PrintVector();

	//Checks whether all components of this vector are the same, within a tolerance.
	bool AllComponentsEqual(float value) const;

	//Get distance
	static float Distance(FVector& v1, FVector& v2);

	//Calculate the dot product of two vectors.
	static T DotProduct(const FVector& v1, const FVector& v2);

	//Check against another vector for equality, within specified error limits.
	bool Equals(const FVector& v1, float Tolerance);

	//Get a copy of this vector with absolute value of each component.
	FVector GetAbs();

	//Get the maximum absolute value of the vector's components.
	T GetAbsMax();

	//Get the minimum absolute value of the vector's components.
	T GetAbsMin(); 

	//Variabels
	T X;
	T Y;
	T Z;
};


int main()
{
	FVector<int> v3(42, 12, 111);

	v3.PrintVector();
	FVector<int> v(v3.GetAbsMin());
	v.PrintVector();
	//FVector b(1, 0, 6);
	
}

