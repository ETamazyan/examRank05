#include "bigint.hpp"

bigint::bigint():str("0"){}

// bigint::bigint(unsigned int num)
// {
// 	std::stringstream ss;
// 	ss << num;
// 	ss.str();
// }

bigint::bigint(const bigint& other):str(other.str){}

bigint& bigint::operator=(const bigint& rhs)
{
	if(this != &rhs)
		this->str = rhs.str;
	return (*this);
}

bigint bigint::operator+(const bigint& other)
{
	bigint result;
	result.str.clear();

	int i = str.size() - 1;
	int j = other.str.size() - 1;
	int temp = 0;

	while(i >= 0 || j >= 0 || temp)
	{
		int sum = temp;
		if (i >= 0)
			sum += str[i--] - '0';
		if (j >= 0)
			sum += str[j--] - '0';
		result.str.insert(result.str.begin(), (sum % 10) + '0');
		temp = sum / 10;
	}
	return (result);
}


bigint::~bigint(){}

// bigint& operator+=(const bigint& other)
// str + str?

bigint& bigint::operator++()
{
	*this = *this + bigint(1);
	return (*this);	
}

bigint bigint::operator++(int)
{
	bigint temp = *this;
	*this = *this + bigint(1);
	return (temp);
}
