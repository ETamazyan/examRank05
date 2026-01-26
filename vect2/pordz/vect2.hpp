#pragma once

#include <iostream>
#include <sstream>

class vect2
{
	private:
		int x;
		int y;
	public:
		vect2();
		vect2(const vect2& other);
		vect2(int num1, int num2);
		vect2& operator=(const vect2& rhs);
		~vect2();

		int& operator[](int index);
		int operator[](int index)const;

		vect2 operator-()const; //check this
		vect2& operator--(); // check this
		vect2 operator--(int); // check this

		vect2& operator++(); // check this
		vect2 operator++(int); // check this

		vect2 operator*(int num)const; //check this
		vect2& operator *=(int num); // check this

		vect2 operator*(const vect2& rhs)const;
		vect2 operator+(const vect2& rhs)const;
		vect2 operator-(const vect2& rhs)const;
		vect2& operator*=(const vect2& rhs);
		vect2& operator+=(const vect2& rhs);
		vect2& operator-=(const vect2& rhs);

		bool operator==(const vect2& rhs);
		bool operator!=(const vect2& rhs);
};
vect2 operator*(int num, const vect2& other);
std::ostream operator<<(std::ostream os, const vect2& other);