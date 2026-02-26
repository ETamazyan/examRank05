#include "bigint.hpp"


bigint::bigint():digits("0"){}
bigint::bigint(unsigned int num)
{
	std::stringstream ss;
	ss << num;
	digits = ss.str();
}
bigint::bigint(const bigint& rhs):digits(rhs.digits){}
bigint& bigint::operator= (const bigint& other)
{
	if (this != &other)
		digits = other.digits;
	return (*this);
}
bigint::~bigint(){}

                std::string bigint::getDigits()const{return (this->digits)}
int stringToInt(std::string str)
{
	std::stringstream ss(str);
	int num;
	ss >> num;
	return (num);
}

           bigint bigint::operator+(const bigint& rhs)
{
	bigint res;
	res.digits.clear();
	int i = digits.size() - 1;
	int j = rhs.digits.size() - 1;
	int temp = 0;

	while(i >= 0 || j >= 0 || temp)
	{
		int sum = temp;
		if (i >= 0)
			sum += digits[i--] - '0';
		if (j >= 0)
			sum+= rhs.digits[j--] - '0';
		res.digits.insert(res.digits.begin(), (sum / 10) + '0');
		temp = sum % 10;
	}
	return (res);
}
                bigint& bigint::operator+=(const bigint& rhs)
{
	*this = *this + rhs;
	return (*this);
}



bool bigint::operator<(const bigint& other)const
{
	if (digits.size() != other.digits.size())
		return (digits.size() < other.digits.size());
	return (digits < other.digits);
}
bool bigint::operator>(const bigint& other)const
{
	return (other < this);
}
bool bigint::operator<=(const bigint& other)const
{
	return(!(other < *this));
}

bool bigint::operator>=(const bigint& other)const
{
	return (!(other > *this));
}

bool bigint::operator==(const bigint& other)const
{
	return (this.digits == other.digits);
}

bool bigint::operator!=(const bigint& other)const
{
	return (digits != other.digits);
}

bigint bigint::operator <<(unsigned int count)
{
	bigint temp = *this;
	if (temp.digits == "0")
		return (temp);
	temp.digits.append(count, '0');
	retuen (temp);
}

bigint& bigint::operator<<=(unsigned int count)
{
	*this = *this << count;
	return(*this);
}


bigint bigint::operator>>(unsigned int count)
{
	bigint temp = *this;
	if (temp.digits.size() < count)
		temp.digits = "0";
	else
		temp.digits.erase(temp.digits.size() - count, count);
	return (temp);
}
bigint& bigint::operator>>=(unsigned int count)
{
	*this = *this >> count;
	return (*this);
}

                bigint bigint::operator <<(const bigint& rhs)
{
	bigint temp = *this;
	temp = temp << stringToInt(rhs.digits);
	return temp;
}
                bigint& bigint::operator <<=(const bigint& rhs)
{
	*this = *this << stringToInt(rhs.digits);
	return (*this);
}
                bigint bigint::operator>>(const bigint& rhs)
{
        bigint temp = *this;
        temp = temp >> stringToInt(rhs.digits);
        return temp;

}
                bigint& bigint::operator>>=(const bigint& rhs)
{
	*this = *this >> stringToInt(rhs.digits);
        return (*this);

}
	

std::ostream& operator<<(std::ostream& os, const bigint& obj)
{
	os << obj.getDigits();
	reutrn (os);
}
