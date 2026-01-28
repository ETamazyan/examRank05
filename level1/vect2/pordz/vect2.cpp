#include "vect2.hpp"

vect2::vect2():x(0), y(0){}

vect2::vect2(const vect2& other):x(other.x), y(other.y){}

vect2::vect2(int num1, int num2):x(num1),y(num2){}

vect2& vect2::operator=(const vect2& rhs)
{
	if (this != &rhs)
	{
		x = rhs.x;
		y = rhs.y;
	}
	return (*this);
}

int& vect2::operator[](int index)
{
	if (index == 0)
		return (this->x);
	return (this->y);
}

int vect2::operator[](int index)const
{
	if (index == 0)
		return (this->x);
	return (this->y);
}

vect2 vect2::operator-()const // false
{
	vect2 temp = *this;
	temp.x = -temp.x;
	temp.y = -temp.y;
	return (temp);
}

vect2& vect2::operator--()
{
	x = x - 1;
	y = y - 1;
	return (*this); 
}

vect2 vect2::operator--(int) // kind of false
{
	vect2 temp = *this;
	--(*this);
	return (*this);
}

vect2& vect2::operator++()
{
	x = x +1;
	y = y + 1;
	return (*this);
}
vect2 vect2::operator++(int) //kind of false
{
	vect2 temp = *this;
	++(*this);
	return (temp);
}

vect2 vect2::operator*(int num)const
{
	vect2 temp = *this;
	temp.x = temp.x * num;
	temp.y = temp.y * num;
	return (temp);
}
vect2& vect2::operator*=(int num)
{
	x = x * num;
	y = y * num;
	return (*this);
}

vect2 vect2::operator*(const vect2& rhs)const
{
	vect2 temp = *this;
	temp.x = temp.x * rhs.x;
	temp.y = temp.y * rhs.y;
	return (temp);
}

vect2 vect2::operator+(const vect2& rhs)const
{
	vect2 temp = *this;
	temp.x = temp.x + rhs.x;
	temp.y = temp.y + rhs.y;
	return (temp);
}

vect2 vect2::operator-(const vect2& rhs)const
{
	vect2 temp = *this;
	temp.x = temp.x - rhs.x;
	temp.y = temp.y - rhs.y;
	return (temp);
}

vect2& vect2::operator*=(const vect2& rhs)
{
	x = x * rhs.x;
	y = y * rhs.y;
	return (*this);
}

vect2& vect2::operator+=(const vect2& rhs)
{
	x = x + rhs.x;
	y = y + rhs.y;
	return (*this);
}

vect2& vect2::operator-=(const vect2& rhs)
{
	x = x - rhs.x;
	y = y - rhs.y;
	return (*this);
}

bool vect2::operator==(const vect2& other)
{
	return ((x == other.x) && (y == other.y));
}

bool vect2::operator!=(const vect2& other)
{
	return (!(*this == other));
}

vect2::~vect2(){}

vect2 operator*(int num, const vect2& other)
{
	vect2 temp = other;
	temp *= num;
	return (temp);
}

std::ostream& operator<<(std::ostream& os, const vect2& obj)
{
	os<< "{" << obj[0] << ", " << obj[1] << "}";
	return (os);
}