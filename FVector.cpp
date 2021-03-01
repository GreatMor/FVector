#include "FVector.h"
#include <corecrt_math.h>


FVector::FVector()
	:X(0.f), Y(0.f),	Z(0.f)
{

}

FVector::FVector(float InX, float InY, float InZ)
	:X(InX), Y(InY), Z(InZ)
{
	
}

FVector::FVector(float InF)
	: X(InF), Y(InF), Z(InF)
{

}

std::string FVector::ToString()
{
	std::stringstream _str;
	_str << "X = " << std::to_string(X) << " Y = " << std::to_string(Y) << " Z = ", std::to_string(Z);
	const std::string string_Vector = _str.str();

	return string_Vector;
}

void FVector::PrintVector()
{
	std::cout << "X = " << X << " Y = " << Y << " Z = " << Z <<std::endl;
}

bool FVector::AllComponentsEqual(float value) const
{
	return X-Y <= value && Y - Z <=value && X-Z <= value;
}

float FVector::Distance(FVector& v1, FVector v2)
{
	float a = sqrt((std::powf(v2.X - v1.X, 2)) + (std::powf(v2.Y - v1.Y, 2)) + (std::powf(v2.Z - v1.Z, 2)));
	return a;
}

const FVector FVector::LeftVector = FVector(0, -1, 0);
const FVector FVector::RightVector = FVector(0, 1, 0);
const FVector FVector::DownVector = FVector(0, 0, -1);
const FVector FVector::ForwardVector = FVector(1, 0, 0);
const FVector FVector::BeckwardVector = FVector(-1, 0, 0);
const FVector FVector::OneVector = FVector(1);
const FVector FVector::ZeroVector = FVector(0);

bool FVector::operator!=(const FVector& v)
{
	return X != v.X || Y != v.Y || Z != v.Z;
}

FVector FVector::operator-(const FVector& v)
{
	float _x = X - v.X;
	float _y = Y - v.Y;
	float _z = Z - v.Z;
	const FVector vec(_x, _y, _z);
	return vec;
}

FVector FVector::operator-(float InF)
{
	float _x = X - InF;
	float _y = Y - InF;
	float _z = Z - InF;
	const FVector vec(_x, _y, _z);
	return vec;
}

FVector FVector::operator-()
{
	FVector(X = -X, Y = -Y,  Z= -Z);
	return *this;
}

FVector FVector::operator*(float scale)
{
	FVector Vec(X * scale, Y * scale, Z * scale);
	return Vec;
}

FVector FVector::operator*(const FVector& v)
{
	FVector Vec(X * v.X, Y * v.Y, Z * v.Z);
	return Vec;
}

FVector FVector::operator*=(float scale)
{
	X *= scale, Y *= scale, Z *= scale;
	return *this;
}

FVector FVector::operator*=(const FVector& v)
{
	X = X *= v.X, Y= Y *= v.Y, Z = Z *= v.Z;
	return *this;
}

FVector FVector::operator/(const FVector& v)
{
	return FVector (X / v.X, Y / v.Y, Z / v.Z);	
}

FVector FVector::operator/(float scale)
{
	return FVector(X / scale, Y / scale, Z / scale);
}

FVector FVector::operator/=(float scale)
{
	return FVector(X /= scale, Y /= scale, Z /= scale);
}

FVector FVector::operator/=(const FVector& v)
{
	return FVector(X /= v.X, Y /= v.Y, Z /= v.Z);
}

float& FVector::operator[](int index)
{
	
	switch (index)
	{
	case 1:
		return X;

	case  2:
		return Y;

	case 3:
		return Z;

	default:
		break;
	}
}

float FVector::operator[](int index) const
{
	switch (index)
	{
	case 1:
		return X;		
	
	case  2:
		return Y;
	
	case 3:
		return Z;
	
	default:
		break;
	}
} 

FVector FVector::operator^(const FVector& v)
{
	const FVector cross_product(Y * v.Z - Z * v.Y, Z * v.X - X * v.Z, X * v.Y - Y * v.X);
	return cross_product;
}

float FVector::operator|(FVector& v)
{
	float dot_product = X * v.X + Y * v.Y + Z * v.Z;
	return dot_product;
}

FVector FVector::operator+(const FVector& v)
{
	float _x = X + v.X;
	float _y = Y + v.Y;
	float _z = Z + v.Z;
	const FVector vec(_x, _y, _z);
	return vec;
}

FVector FVector::operator+(float InF)
{
	float _x = X + InF;
	float _y = Y + InF;
	float _z = Z + InF;
	const FVector vec(_x, _y, _z);
	return vec;
}

bool FVector::operator==(FVector& v)
{
	return X == v.X && Y == v.Y && Z == v.Z;
}
