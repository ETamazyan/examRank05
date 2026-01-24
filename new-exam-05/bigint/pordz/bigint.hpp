#pragma once

#include <string>
#include <iostream>
#include <sstream>

class bigint
{
	private:
		std::string val;

	public:
		bigint();
		bigint(const bigint& other);
		bigint(unsigned int num);
		bigint& operator=(const bigint& rhs);
		~bigint();

		std::string get_val() const;
		int	stringToInt(std::string str) const;


		bigint operator+(const bigint& rhs)const;
		bigint& operator+=(const bigint& rhs);

		bigint operator++()const;
		bigint& operator++(int);

	bool operator>(const bigint& rhs)const;
	bool operator>=(const bigint& rhs) const;
	bool operator<(const bigint& rhs)const;
	bool operator<=(const bigint& rhs)const;
	bool operator==(const bigint& rhs)const;
	bool operator!=(const bigint& rhs)const;








		// std::string get_val()const;
		// int bigint::stringToInt(std::string s) const

		// bigint operator+(const bigint& other)const;
		// bigint& operator +=(const bigint& other);

		// bigint& operator++(); //x++
		// bigint operator++(int); //++x

		// bool operator>(const bigint& other)const;
		// bool operator>=(const bigint& other)const;
		// bool operator<(const bigint& other)const;;
		// bool operator<=(const bigint& other)const;
		// bool operator==(const bigint& other)const;
		// bool operator!=(const bigint& other)const;

};

std::ostream& operator<<(std::ostream& os, const bigint& obj);