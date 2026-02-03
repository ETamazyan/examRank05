#pragma once

#include <iostream>
#include <sstream>
#include <string>

class bigint
{
	private:
		std::string digits;
	public:
		bigint();
		bigint(const bigint& other);
		bigint(unsigned int num);
		bigint& operator=(const bigint& other);
		~bigint();

		bigint operator+(const bigint& other) const;
		bigint& operator+=(const bigint& other);

		bigint& operator++();
		bigint operator++(int);

		bool operator<(const bigint& other)const;
		bool operator>(const bigint& other)const;
		bool operator<=(const bigint& other)const;
		bool operator>=(const bigint& other)const;
		bool operator==(const bigint& other)const;
		bool operator!=(const bigint& other)const;

		bigint operator<<(const bigint& other)const;
		bigint& operator<<=(const bigint& other);
		bigint operator>>(const bigint& other)const;
		bigint& operator>>=(const bigint& other);
		
		bigint operator<<(unsigned int)const;
		bigint& operator<<=(unsigned int);
		bigint operator>>(unsigned int)const;
		bigint& operator>>=(unsigned int);

		std::string getDigits()const;
		int stringToInt(std::string str) const;
};

std::ostream& operator<<(std::ostream& os, const bigint& other);