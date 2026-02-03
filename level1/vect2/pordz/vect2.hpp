#pragma once

#include <sstream>
#include <iostream>

class vect2
{
	private:
		int x;
		int y;
	public:
		vect2();
		vect2(int num, int num1);
		vect2(const vect2& other);
		~vect2();
		vect2& operator=(const vect2& other);

		int& operator[](int index);
		int operator[](int index)const;

		vect2 operator-();
		vect2& operator--();
		vect2 operator--(int);

		vect2& operator++();
		vect2& operator++(int);

		vect2 operator*(int num)const;
		vect2& operator*=(int num);

		vect2 operator+(const vect2& rhs)const;
		vect2 operator-(const vect2& rhs)const;
		vect2& operator+=(const vect2& rhs);
		vect2& operator-=(const vect2& rhs);

		bool operator==(const vect2& rhs);
		bool operator!=(const vect2& rhs);
};

vect2 operator*(int num, const vect2& obj);
std::ostream& operator<<(std::ostream& os, const vect2& obj);