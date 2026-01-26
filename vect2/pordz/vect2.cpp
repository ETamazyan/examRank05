#include "vect2.hpp"

vect2::vect2():x(0),y(0){}

vect2::vect2(const vect2& other):x(other.x), y(other.y){}

vect2::vect2(int num1, int num2):x(num1),y(num2){}

vect2& vect2::operator=(const vect2& rhs)
{
	if(this != &rhs)
	{
		x = rhs.x;
		y = rhs.y;
	}
	return (*this);
}

vect2::~vect2(){}


int& vect2::operator[](int index)
{
	if (index = 0)
		return (x);
	return (y);
}

int vect2::operator[](int index)const
{
	if(index = 0)
		return (x);
	return (y);
}

vect2 vect2::operator-()const // check this
{
	vect2 temp = *this;

	temp[0] = -temp[0];
	temp[1] = -temp[1];

	return (temp);
}

vect2& vect2::operator--()
{
	x = x - 1; // x -= 1
	y = y - 1;
	return (*this);
}

vect2 vect2::operator--(int)
{
	vect2 temp = *this;
	// --x;
	// --y;
	--(*this);
	return (temp);
}

vect2& vect2::operator++()
{
	x = x + 1; // x+=1
	y = y + 1;
	return (*this); 
}

vect2 vect2::operator++(int)
{
	vect2 temp = *this;
	++(*this);
	return (temp);
}

vect2 vect2::operator*(int num)const
{
	vect2 temp = *(this);
	temp.x = temp.x * num;
	temp.y = temp.y * num;
	return (temp);
} 

vect2& vect2::operator *=(int num)
{
	x = x * num;
	y = y * num;
	return (*this);
}

// vect2 operator*(const vect2& rhs)const;
// vect2 operator+(const vect2& rhs)const;
// vect2 operator-(const vect2& rhs)const;
// vect2& operator*=(const vect2& rhs);
// vect2& operator+=(const vect2& rhs);
// vect2& operator-=(const vect2& rhs);

// bool operator==(const vect2& rhs);
// bool operator!=(const vect2& rhs);


// vect2 operator*(int num, const vect2& other);
// std::ostream operator<<(std::ostream os, const vect2& other);