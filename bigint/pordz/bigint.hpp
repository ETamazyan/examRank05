#pragma once

#include <sstream>
#include <ostream>
#include <string>

class bigint
{
	private:
		std::string str;
	public:
		bigint();
		bigint(unsigned int num);
		bigint (const bigint& other);
		bigint& operator=(const bigint& rhs);
		~bigint();

		bigint operator+(const bigint& other);
		bigint& operator+=(const bigint& other);

		bigint& operator++();
		bigint operator++(int);

		bool operator<(const bigint& rhs) const;
		bool operator<=(const bigint& rhs) const;
		bool operator>(const bigint& rhs) const;
		bool operator>=(const bigint& rhs) const;
		bool operator==(const bigint& rhs) const;
		bool operator!=(const bigint& rhs) const;

		bigint operator<<(unsigned int count) const;
		bigint& operator<<=(unsigned int count);
		bigint operator>>(unsigned int count) const;
		bigint& operator>>=(unsigned int count);

		bigint operator<<(const bigint& rhs) const;
		bigint& operator<<=(const bigint& rhs);
		bigint operator>>(const bigint& rhs) const;
		bigint& operator>>=(const bigint& rhs);

		// + += ++ ++, < > <= >= == !=, << <<= >> >>=, << <<= >> >>=
		// getStr, stringToInt, ostream,
};