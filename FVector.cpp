#include "FVector.h"
#include <corecrt_math.h>

template<class T>
FVector<T>::FVector()
	:X(0)
	,Y(0)
	,Z(0)
{

}

template<class T>
FVector<T>::FVector(T InF)
	:X(InF)
	,Y(InF)
	,Z(InF)
{

}

template<class T>
FVector<T>::FVector(T InX, T InY, T InZ)
	: X(InX)
	, Y(InY)
	, Z(InZ)
{

}

template<class T>
std::string FVector<T>::ToString()
{
	std::stringstream _str;	
	_str << "X = " << X << " Y = " << Y << " Z = ", Z;
	const std::string string_Vector = _str.str();

	return string_Vector;
}

template<class T>
void FVector<T>::PrintVector()
{
	std::cout << "X = " << X << " Y = " << Y << " Z = " << Z << std::endl;
}

template<class T>
bool FVector<T>::AllComponentsEqual(float value) const
{
	return std::abs(X - Y) <= value && std::abs(Y - Z) <=value && std::abs(X-Z) <= value;
}

template<class T>
float FVector<T>::Distance(FVector& v1, FVector& v2)
{
	float a = sqrt((std::powf(v2.X - v1.X, 2)) + (std::powf(v2.Y - v1.Y, 2)) + (std::powf(v2.Z - v1.Z, 2)));
	return a;
}

template<class T>
T FVector<T>::DotProduct(const FVector& v1, const FVector& v2)
{
	return T(v1.X *v2.X + v1.Y * v2.Y + v1.Z * v2.Z);
}

template<class T>
bool FVector<T>::Equals(const FVector& v1, float Tolerance)
{
	return std::abs(this->X - v1.X) <= Tolerance && std::abs(this->Y - v1.Y) <= Tolerance && std::abs(this->Z - v1.Z) <= Tolerance;
}

template<class T>
FVector<T> FVector<T>::GetAbs()
{
	return FVector<T>(std::abs(this->X), abs(this->Y), abs(this->Z));
}

template<class T>
T FVector<T>::GetAbsMax()
{
	T cur_max;
	if (this->X > this->Y)	
	 cur_max = this->X;	
	else
	 cur_max = this->Y;	

	if (cur_max < this->Z)
	 cur_max = Z;

	return cur_max;	
}

template<class T>
T FVector<T>::GetAbsMin()
{
	T cur_min;
	if (this->X > this->Y)
		cur_min = this->Y;
	else
		cur_min = this->X;

	if (cur_min > this->Z)
		cur_min = Z;

	return cur_min;
}

template<class T>
const FVector<T> FVector<T>::LeftVector = FVector(0, -1, 0);
template<class T>
const FVector<T> FVector<T>::RightVector = FVector(0, 1, 0);
template<class T>
const FVector<T> FVector<T>::DownVector = FVector(0, 0, -1);
template<class T>
const FVector<T> FVector<T>::ForwardVector = FVector(1, 0, 0);
template<class T>
const FVector<T> FVector<T>::BeckwardVector = FVector(-1, 0, 0);
template<class T>
const FVector<T> FVector<T>::OneVector = FVector(1);
template<class T>
const FVector<T> FVector<T>::ZeroVector = FVector(0);

template<class T>
bool FVector<T>::operator!=(const FVector& v)
{
	return X != v.X || Y != v.Y || Z != v.Z;
}

template<class T>
FVector<T> FVector<T>::operator-(const FVector& v)
{
	float _x = X - v.X;
	float _y = Y - v.Y;
	float _z = Z - v.Z;
	const FVector vec(_x, _y, _z);
	return vec;
}

template<class T>
FVector<T> FVector<T>::operator-(T InF)
{
	T _x = X - InF;
	T _y = Y - InF;
	T _z = Z - InF;
	const FVector vec(_x, _y, _z);
	return vec;
}

template<class T>
FVector<T> FVector<T>::operator-()
{
	FVector(X = -X, Y = -Y,  Z= -Z);
	return *this;
}

template<class T>
FVector<T> FVector<T>::operator*(float scale)
{
	FVector Vec(X * scale, Y * scale, Z * scale);
	return Vec;
}

template<class T>
FVector<T> FVector<T>::operator*(const FVector& v)
{
	FVector Vec(X * v.X, Y * v.Y, Z * v.Z);
	return Vec;
}

template<class T>
FVector<T> FVector<T>::operator*=(float scale)
{
	X *= scale, Y *= scale, Z *= scale;
	return *this;
}

template<class T>
FVector<T> FVector<T>::operator*=(const FVector& v)
{
	X = X *= v.X, Y= Y *= v.Y, Z = Z *= v.Z;
	return *this;
}

template<class T>
FVector<T> FVector<T>::operator/(const FVector& v)
{
	return FVector (X / v.X, Y / v.Y, Z / v.Z);	
}

template<class T>
FVector<T> FVector<T>::operator/(float scale)
{
	return FVector(X / scale, Y / scale, Z / scale);
}

template<class T>
FVector<T> FVector<T>::operator/=(float scale)
{
	return FVector(X /= scale, Y /= scale, Z /= scale);
}

template<class T>
FVector<T> FVector<T>::operator/=(const FVector& v)
{
	return FVector(X /= v.X, Y /= v.Y, Z /= v.Z);
}

template<class T>
T& FVector<T>::operator[](int index)
{
	int i = index - 1;
	if (i < 0 || i>2)
	{
		float er = 0;
		std::cout << "ERROR!" << " this is 3d Vector" << std::endl;
		return er;
	}
	else
		return *(&X + i);
}

template<class T>
T FVector<T>::operator[](int index) const
{
	int i = index - 1;
	if (i < 0 || i>2)
	{
		float er = 0;
		std::cout << "ERROR!" << " this is 3d Vector" << std::endl;
		return er;
	}
	else
		return *(&X + i);
} 

template<class T>
FVector<T> FVector<T>::operator^(const FVector& v)
{
	const FVector cross_product(Y * v.Z - Z * v.Y, Z * v.X - X * v.Z, X * v.Y - Y * v.X);
	return cross_product;
}

template<typename T>
T FVector<T>::operator|(FVector<T>& v)
{
	T dot_product = X * v.X + Y * v.Y + Z * v.Z;
	return dot_product;
}

template<typename T>
FVector<T> FVector<T>::operator+(const FVector<T>& v)
{
	T _x = X + v.X;
	T _y = Y + v.Y;
	T _z = Z + v.Z;
	const FVector vec(_x, _y, _z);
	return vec;
}

template<typename T>
FVector<T> FVector<T>::operator+(T InF)
{
	T _x = X + InF;
	T _y = Y + InF;
	T _z = Z + InF;
	const FVector vec(_x, _y, _z);
	return vec;
}

template<typename T>
bool FVector<T>::operator==(FVector<T>& v)
{
	return X == v.X && Y == v.Y && Z == v.Z;
}
