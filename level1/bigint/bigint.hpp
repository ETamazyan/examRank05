#pragma once

#include <sstream>
#include <string>
#include <iostream>

class bigint
{
	private:
		std::string digits;
	public:
		bigint();
		bigint(unsigned int num);
		bigint(const bigint& other);
		bigint& operator=(const bigint& rhs);
		~bigint();

		bigint operator+(const bigint& rhs)const;
		bigint& operator+=(const bigint& other);

		bigint& operator++();
		bigint operator++(int);

		bool operator>(const bigint& rhs)const;
		bool operator>=(const bigint& rhs)const;
		bool operator<(const bigint& rhs)const;
		bool operator<=(const bigint& rhs)const;
		bool operator==(const bigint&rhs)const;
		bool operator!=(const bigint& rhs)const;

		bigint operator>>(unsigned int count)const;
		bigint& operator >>=(unsigned int count);
		bigint operator<<(unsigned int count)const;
		bigint& operator<<=(unsigned int count);

		bigint operator >>(const bigint& rhs)const;
		bigint& operator>>=(const bigint& rhs);
		bigint operator<<(const bigint& rhs)const;
		bigint& operator<<=(const bigint& rhs);

		std::string getDigits()const;
		int stringToInt(std::string str)const;
};


std::ostream& operator<<(std::ostream& os, const bigint& obj);

// #ifndef BIGINT_HPP
// #define BIGINT_HPP
// #include <iostream>
// #include <sstream>
// #include <string>

// class bigint
// {
// 	private:
// 		std::string str;
// 	public:	
// 	bigint();
// 	bigint(const bigint &other);
// 	bigint(unsigned int num);

// 	~bigint();

// 	bigint& operator=(const bigint &other);

// 	bigint operator+(const bigint& other)const;
// 	bigint& operator+=(const bigint& other);

// 	bigint& operator++();
// 	bigint operator++(int);

// 	bool operator>(const bigint& other)const;
// 	bool operator>=(const bigint& other)const;
// 	bool operator<(const bigint& other)const;
// 	bool operator<=(const bigint& other)const;

// 	bool operator==(const bigint& other)const;
// 	bool operator!=(const bigint& other)const;

// 	bigint operator>>(unsigned int)const;
// 	bigint& operator>>=(unsigned int);
// 	bigint operator<<(unsigned int)const;
// 	bigint& operator<<=(unsigned int);

// 	bigint operator>>(const bigint& other)const;
// 	bigint& operator>>=(const bigint& other);
// 	bigint operator<<(const bigint& other)const;
// 	bigint& operator<<=(const bigint& other);

// 	std::string get_str()const;
// 	int stringToInt(std::string s)const;
// };

// std::ostream& operator<<(std::ostream& os,const bigint& other);
// #endif
