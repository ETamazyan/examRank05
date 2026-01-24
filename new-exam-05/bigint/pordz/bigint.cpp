#include "bigint.hpp"

bigint::bigint():val("0"){}

bigint::bigint(const bigint& other):val(other.val){};

bigint::bigint(unsigned int num)
{
	std::stringstream ss;
	ss << num;
	this->val = ss.str();
}
//operator +,+=


std::string bigint::get_val() const
{
	return (this -> val);
}

// check this function later, i don't know him
int	stringToInt(std::string str) const
{
	std::stringstream ss(str);
	int num;
	ss >> num;
	return (num);
}

bigint bigint::operator+(const bigint& rhs)const
{
	bigint result;
	result.val.clear();

	int i = val.size() - 1;
	int j = rhs.val.size() - 1;
	int temp = 0;

	while (i >= 0 || j >= 0 || temp)
	{
		int sum = temp;
		if (i >= 0)
			sum += val[i--] - '0';
		if (j >= 0)
			sum += rhs.val[j--] = '0';
		result.val.insert(result.val.begin(), (sum % 10) + '0');
		temp = sum / 10;
	}
	return result;
}

bigint& bigint::operator+=(const bigint& rhs)
{
	(*this) = *this + other;
	return (*this)
}

bigint& bigint::operator++()
{
	(*this) += bigint(1);
	return (*this);
}

bigint bigint::operator++(int) //++x
{
	bigint temp = *this;
	++(*this);
	return (temp);

}

bool bigint::operator>(const bigint& rhs)const
{
	return (rhs < (*this));
}
bool bigint::operator>=(const bigint& rhs) const
{
	return (!( *this < rhs));
}

bool bigint::operator<(const bigint& rhs)const
{
	if(rhs.val.size() != *this.val.size())
		return (rhs.val.size() < *this.val.size());
	return ( rhs.val < *this->val);
}

bool bigint::operator<=(const bigint& rhs)const
{
	return (*this.val == rhs.val);
}

bool bigint::operator==(const bigint& rhs)const
{
	return (val == rhs.val);
}
bool bigint::operator!=(const bigint& rhs)const
{
	return (!(val == rhs.val));
}







// bigint bigint::operator+(const bigint& other)const
// {
// 	bigint result;
// 	result.val.clear();

// 	int i = val.size() - 1;
// 	int j = other.val.size() - 1;
// 	int temp = 0;

// 	while(i >= 0 || j >= 0 || temp)
// 	{
// 		int sum = temp;
// 		if (i >= 0)
// 			sum += val[i--] - '0';
// 		if (j >= 0)
// 			sum += other.val[j--] - '0';
// 		result.val.insert(result.val.begin(), (sum % 10) + '0');
// 		temp = sum / 10;
// 	}
// 	return (result);
// }

// bigint& bigint::operator+=(const bigint& other)
// {
// 	(*this) = (*this) + other;
// 	return (*this)
// }

// bigint& bigint::operator++() // prefix
// {
// 	(*this) += bigint(1);
// 	return (*this);
// }

// bigint bigint::operator++(int)
// {
// 	bigint temp = *this;
// 	++(*this);
// 	return (temp);
// }

// bigint& bigint::operator=(const bigint& rhs)
// {
// 	if (this != &rhs)
// 		this->val = rhs.val;
// 	return *this;
// }

// std::string bigint::get_val() const {return val;}

// // opertores
// bool bigint::operator>(const bigint& other)const
// {
// 	return(other < (*this));
// }

// bool bigint::operator>=(const bigint& other)const
// {
// 	return (other > (*this)); // check
// 		// return(!(*this < other));
// }

// bool bigint::operator<(const bigint& other)const
// {
// 	if(val.size() != other.val.size())
// 		return (val.size() < other.val.size());
// 	return (val < other.val);
// }

// bool bigint::operator<=(const bigint& other)const
// {
// 	return (!(*this > other));
// }

// bool bigint::operator==(const bigint other)const
// {
// 	return (val == other.val);
// }

// bool bigint::operator!=(const bigint other)const
// {
// 	return (!(*this == other));
// }

// opertores

std::ostream& operator<<(std::ostream &os, const bigint &obj)
{
	os << obj.get_val();
	return(os);
}

bigint::~bigint(){}