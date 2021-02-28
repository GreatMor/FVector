#include "FVector.h"

FVector::FVector()
{

}

FVector::FVector(float InX, float InY, float InZ)
{
	X = InX; Y = InY; Z = InZ;
}

FVector::FVector(float InF)
{
	X = InF; Y = InF; Z = InF;
}

std::string FVector::ToString()
{
	std::string X_String = std::to_string(X);
	std::string Y_String = std::to_string(Y);
	std::string Z_String = std::to_string(Z);

	return "X = " + X_String + "  " + " Y = " + Y_String + "  " + " Z = " +Z_String;
}

void FVector::PrintVector()
{
	std::cout << "X = " << X << " Y = " << Y << " Z = " << Z <<std::endl;
}

FVector FVector::LeftVector()
{
	static const FVector L_Vector(0, -1, 0);
	return L_Vector;
}

FVector FVector::RightVector()
{
	static const FVector R_Vector(0, 1, 0);
	return R_Vector;
}

FVector FVector::DownVector()
{
	static const FVector D_Vector(0, 0, -1);
	return D_Vector;
}

FVector FVector::ForwardVector()
{
	static const FVector F_Vector(1, 0, 0);
	return F_Vector;
}

FVector FVector::BeckwardVector()
{
	static const FVector D_Vector(-1, 0, 0);
	return D_Vector;
}

FVector FVector::OneVector()
{
	FVector One_Vector(1);
	return One_Vector;
}

FVector FVector::ZeroVector()
{
	FVector One_Vector(0);
	return One_Vector;
}

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

float& FVector::operator[](int i)
{
	if(i == 0)
	{
		return X;
	}
	else if(i == 1)
	{
		return Y;
	}
	else if(i == 2)
	{
		return Z;
	}
	else if(i < 0 || i > 2)
	{
		float zero = 0;
		std::cout << "thi is 3D vector" << std::endl;
		return zero;
	}
}

float FVector::operator[](int indexi) const
{
	if (indexi == 0)
	{
		return X;
	}
	else if (indexi == 1)
	{
		return Y;
	}
	else if (indexi == 2)
	{
		return Z;
	}
	else if (indexi < 0 || indexi > 2)
	{
		float zero = 0;
		std::cout << "thi is 3D vector" << std::endl;
		return zero;
	}
} 

FVector FVector::operator^(const FVector& v)
{
	const FVector cross_product(Y * v.Z - Z * v.Y, Z * v.X - X * v.Z, X * v.Y - Y * v.X);
	cross_product.X;
	cross_product.Y;
	cross_product.Z;
	return cross_product;
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
