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
		bigint(unsigned int num);
		bigint(const bigint& rhs);
		bigint& operator= (const bigint& other);
		~bigint();

		std::string getDigits()const;
		int stringToInt(std::string str);

		bigint operator+(const bigint& rhs);
		bigint& operator+=(const bigint& rhs);

		bool operator<(const bigint& other)const;
       		bool operator>(const bigint& other)const;
		bool operator<=(const bigint& other)const;
     		bool operator>=(const bigint& other)const;
     		bool operator==(const bigint& other)const;
	       	bool operator!=(const bigint& other)const;

		bigint operator <<(unsigned int count);
		bigint& operator<<=(unsigned int count);
		bigint operator>>(unsigned int count);
		bigint& operator>>=(unsigned int count);

		bigint operator <<(const bigint& rhs);
		bigint& operator <<=(const bigint& rhs);
		bigint operator>>(const bigint& rhs);
		bigint& operator>>=(const bigint& rhs);
};

std::ostream& operator<<(std::ostream& os, const bigint& obj);

