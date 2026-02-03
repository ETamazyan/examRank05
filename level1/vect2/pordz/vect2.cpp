#include "vect2.hpp"

vect2::vect2():x(0), y(0){}

vect2::vect2(int num, int num1):x(num),y(num1){}
vect2::vect2(const vect2& other):x(other.x),y(other.y){}
vect2::~vect2(){};
vect2& vect2::operator=(const vect2& rhs)
{
	if(this != &rhs)
	{
		x = rhs.x;
		y = rhs.y;
	}
	return (*this);
}

int& vect2::operator[](int index)
{
	if (index == 0)
		return (x);
	return (y);
}

int vect2::operator[](int index)const
{
	if (index == 0)
		return (x);
	return (y);
}

vect2 vect2::operator-()
{
	return (vect2(-x, -y));
}

vect2& vect2::operator--()
{
	x--;
	y--;
	return(*this);
}

vect2 vect2::operator--(int)
{
	vect2 temp(*this);
	--(*this);
	return (temp);
}

vect2& vect2::operator++()
{
	x++;
	y++;
	return (*this);
}

vect2& vect2::operator++(int)
{
	vect2 temp(*this);
	++(*this);
	return (temp);
}

vect2 vect2::operator*(int num)const
{
	return (vect2(x * num, y * num));
}

vect2& vect2::operator*=(int num)
{
	x *= num;
	y *= num;
	return (*this);
}

vect2 vect2::operator+(const vect2& rhs)const
{
	return (vect2(x + rhs.x, y + rhs.y));
}
vect2 vect2::operator-(const vect2& rhs)const
{
	return (vect2(x - rhs.x, y - rhs.y));
}
vect2& vect2::operator+=(const vect2& rhs)
{
	(*this) = (*this) + rhs;
	return (*this);
}

vect2& vect2::operator-=(const vect2& rhs)
{
	(*this) = (*this) - rhs;
	return (*this);	
}

bool vect2::operator==(const vect2& rhs)
{
	return ((x == rhs.x) && (y == rhs.y));
}

bool vect2::operator!=(const vect2& rhs)
{
	return ((x == rhs.x) || (y == rhs.y));
}

vect2 operator*(int num, const vect2 &obj)
{
	vect2 temp(obj);
	temp = temp * num;
	return (temp);
}
std::ostream& operator<<(std::ostream& os, const vect2& obj)
{
	os << "{" << obj[0] << ", " << obj[1] << "}";
	return (os);
}