#pragma once
#include <iostream>
#include <string>  

struct FVector
{
	//Variabels
	float X;
	float Y;
	float Z;

	//Constructors
	FVector();
	FVector(float InF);
	FVector(float InX, float InY, float InZ);
	
	//Functions
	std::string ToString();
	void PrintVector();

	//Constants
	FVector LeftVector();
	FVector RightVector();
	FVector DownVector();
	FVector ForwardVector();
	FVector BeckwardVector();
	FVector OneVector();
	FVector ZeroVector();

	///Operators

	//Get a negated copy of the vector.
	FVector  	operator-();
	
	//Gets the result of component - wise subtraction of this by another vector.
	FVector operator- (const FVector& v);

	//Gets the result of subtracting from each component of the vector.
	FVector operator- (float InF);

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
	float& operator[] (int index);

	//Gets specific component of the vector.
	float operator[] (int index)const;

	//Calculate cross product between this and another vector.
	FVector operator^ (const FVector& v);

	//Gets the result of component-wise addition of this and another vector.
	FVector operator+ (const FVector& v);

	//Gets the result of adding to each component of the vector.
	FVector operator+ (float InF);
};

int main()
{
	FVector v(7,3,-4);
	FVector b(1,0,6);
	FVector x = v ^ b;
	
	x.PrintVector();
	
}

