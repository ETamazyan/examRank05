#include "bigint.hpp"

bigint::bigint():digits("0"){}

bigint::bigint(const bigint& other):digits(other.digits){}

bigint::~bigint(){}
bigint::bigint(unsigned int num)
{
	std::stringstream ss;
	ss << num;
	digits = ss.str();
}

std::string bigint::getDigits()const
{
	return (this->digits);
}

int bigint::stringToInt(std::string str) const
{
	std::stringstream ss(str);
	int num;
	ss >> num;
	return (num);
}

bigint bigint::operator+(const bigint& other) const
{
	bigint result;
	result.digits.clear();

	int i = digits.size() - 1;
	int j = other.digits.size() - 1;
	int temp;
	while (i >= 0 || j>= 0 || temp)
	{
		int sum = temp;
		if(i >=0)
			sum+= digits[i--] - '0';
		if(j >= 0)
			sum += other.digits[j--] - '0';
		result.digits.insert(result.digits.begin(), (sum % 10) + '0');
		temp = sum / 10;
	}
	return result;
}
bigint& bigint::operator=(const bigint& other)
{
	if (this != &other)
		digits = other.digits;
	return (*this);
}

bigint& bigint::operator+=(const bigint& other)
{
	(*this) = (*this) + other;
	return (*this);
}

bigint& bigint::operator++()
{
	*this = *this + bigint(1);
	return *this;
}

bigint bigint::operator++(int)
{
	bigint temp = *this;
	++(*this);
	return temp;
}

bool bigint::operator<(const bigint& rhs)const
{
	if(digits.size() != rhs.digits.size())
		return (digits.size() < rhs.digits.size());
	return (digits < rhs.digits);
}

bool bigint::operator>(const bigint& rhs)const
{
	return (rhs < *this);
}

bool bigint::operator<=(const bigint& rhs)const
{
	return (!(*this > rhs));
}

bool bigint::operator>=(const bigint& rhs)const
{
	return (!(*this < rhs));
}

bool bigint::operator==(const bigint& rhs)const
{
	return (digits == rhs.digits);
}

bool bigint::operator!=(const bigint& rhs)const
{
	return (!(*this == rhs));
}

bigint bigint::operator<<(unsigned int count)const //check hhis
{
	bigint temp = *this;
	if (temp.digits == "0")
		return (temp);
	temp.digits.append(count, '0');
	return (temp);

	// bigint tmp = (*this);
	// if(tmp.str == "0" )
	// 	return(tmp);
	// tmp.str.append(n,'0');
	// return(tmp);
}

bigint& bigint::operator<<=(unsigned int count)
{
	*this = *this << count;
	return (*this);
}

bigint bigint::operator>>(unsigned int count)const // check this
{
	bigint tmp = *this;

	if(tmp.digits.size() < count)
		tmp.digits="0";
	else
		tmp.digits.erase(tmp.digits.size() - count, count);
	return(tmp);
}

bigint& bigint::operator>>=(unsigned int count)
{
	*this = *this >> count;
	return (*this);
}

bigint bigint::operator<<(const bigint& other)const
{
	bigint temp = *this;
	temp = temp << stringToInt(other.digits);
	return (temp);
}

bigint& bigint::operator<<=(const bigint& other)
{
	*this = *this << stringToInt(other.digits);
	return (*this);
}

bigint bigint::operator>>(const bigint& other)const
{
	bigint temp = *this;
	temp = temp >> stringToInt(other.digits);
	return (temp);
}
bigint& bigint::operator>>=(const bigint& other)
{
	*this = *this >> stringToInt(other.digits);
	return (*this);
}

std::ostream& operator<<(std::ostream& os, const bigint& other)
{
	os << other.getDigits();
	return os;
}