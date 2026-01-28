#include "bigint.hpp"

bigint::bigint():digits("0"){}

bigint::bigint(unsigned int num)
{
	std::stringstream ss;
	ss << num;
	digits = ss.str();
}

bigint::bigint(const bigint& other):digits(other.digits){}

int bigint::stringToInt(std::string str) const
{
	std::stringstream ss(str);
	int num;
	ss >> num;
	return (num);
}

std::string bigint::getDigits()const
{
	return (this->digits);
}
bigint& bigint::operator=(const bigint& rhs)
{
	if(this != &rhs)
		digits = rhs.digits;
	return (*this);
}

bigint::~bigint(){}

bigint& bigint::operator++()
{
	*this = *this + bigint(1);
	return (*this);
}

bigint bigint::operator++(int)
{
	bigint temp = *this;
	++(*this);
	return temp;
}

bigint& bigint::operator+=(const bigint &other)
{
	(*this)= (*this) + other;
	return(*this);
}


bigint bigint::operator+(const bigint& rhs) const
{
	bigint result;
	result.digits.clear();

	int i = digits.size() - 1;
	int j = rhs.digits.size() - 1;
	int temp = 0;

	while(i >= 0 || j >= 0 || temp)
	{
		int sum = temp;
		if (i >= 0)
			sum += digits[i--] - '0';
		if (j >= 0)
			sum += rhs.digits[j--] - '0';
		result.digits.insert(result.digits.begin(), (sum % 10) + '0');
		temp = sum / 10;
	}
	return (result);
}

// operaator 

bool bigint::operator<(const bigint& rhs)const
{
	if (digits.size() != rhs.digits.size())
		return (digits.size() < rhs.digits.size());
	return (digits < rhs.digits);
}

bool bigint::operator<=(const bigint& rhs)const
{
	// return (!(rhs < *this)); // this
	return(!(*this > rhs));
}

bool bigint::operator>(const bigint& rhs)const
{
	return (rhs < *this);
}
bool bigint::operator>=(const bigint& rhs)const
{
	// return (!(rhs > *this));
	return(!(*this < rhs));

}

bool bigint::operator==(const bigint& rhs)const
{
	return (rhs.digits == digits);
}

bool bigint::operator!=(const bigint& rhs)const
{
	return (!(digits == rhs.digits));
}

// check these
// check these
// check these

bigint bigint::operator>>(unsigned int count)const
{
	bigint temp = *this;
	if (temp.digits.size() < count)
			temp.digits = "0";
	temp.digits.erase(temp.digits.size() - count, count);
	return temp;
}

bigint& bigint::operator>>=(unsigned int count)
{
	*this = *this >> count;
	return *this;
}

bigint bigint::operator<<(unsigned int count)const
{
	bigint temp = *this;
	if (temp.digits == "0")
		return (*this);
	temp.digits.append(count, '0');
	return (temp);
}
bigint& bigint::operator<<=(unsigned int count)
{
	*this = *this << count;
	return *this;
}

//bigint 
bigint bigint::operator>>(const bigint& rhs)const
{
	bigint temp = *this;
	(temp)=(temp)>>stringToInt(rhs.digits);
	return (temp);
}

bigint& bigint::operator>>=(const bigint& rhs)
{
	*this = *this >> stringToInt(rhs.digits);
	return (*this);
}

bigint bigint::operator<<(const bigint& rhs)const
{
	bigint temp = *this;
	temp = temp << stringToInt(rhs.digits);
	return(temp);
}
bigint& bigint::operator<<=(const bigint& rhs)
{
	*this = *this << stringToInt(rhs.digits);
	return (*this);
}

std::ostream& operator<<(std::ostream& os, const bigint& obj)
{
	os << obj.getDigits();
	return os;
}

// #include "bigint.hpp"

// bigint::bigint():str("0"){}

// bigint::~bigint(){}

// bigint::bigint(const bigint &other):str(other.str){}

// bigint::bigint(unsigned int num)
// {
// 	std::stringstream ss;
// 	ss << num;
// 	str = ss.str();
// }

// std::string bigint::get_str()const
// {
// 	return(this->str);
// }

// int bigint::stringToInt(std::string s)const
// {
// 	std::stringstream ss(s);
// 	int num;
// 	ss >> num;
// 	return(num);
// }

// bigint& bigint:: operator=(const bigint &other)
// {
// 	if(this != &other)
// 		this->str=other.str;
// 	return(*this);
// }

// bigint bigint:: operator+(const bigint &other)const
// {
// 	bigint res;
// 	res.str.clear();

// 	int i = this->str.size() - 1;
// 	int j = other.str.size() - 1;
// 	int temp = 0;

// 	while(i >= 0 || j >= 0|| temp)
// 	{
// 		int sum = temp;
// 		if(i>=0)
// 		sum+=this->str[i--] - '0';
// 		if(j>=0)
// 		sum+=other.str[j--] - '0';
// 		res.str.insert(res.str.begin(),(sum % 10)+'0');
// 		temp=sum/10;
// 	}
// 	return(res);
// }
// bigint& bigint::operator+=(const bigint &other)
// {
// 	(*this)= (*this) + other;
// 	return(*this);
// }

// bigint& bigint::operator++()
// {
// 	(*this)+=bigint(1);
// 	return(*this);
// }
// bigint bigint::operator++(int)
// {
// 	bigint tmp=*this;
// 	++(*this);
// 	return(tmp);
// }

// // **** operator bool *****
// // **** operator bool *****

// bool bigint::operator<(const bigint& other)const
// {
// 	if(this->str.size()!=other.str.size())
// 		return(this->str.size()<other.str.size());
// 	return(this->str<other.str); 
// }
// bool bigint::operator<=(const bigint& other)const
// {
// 	return(!(*this > other));
// }

// bool bigint::operator>(const bigint& other)const
// {
// 	return(other < (*this));

// }

// bool bigint::operator>=(const bigint& other)const
// {
// 	return(!(*this < other));
// }

// bool bigint::operator==(const bigint& other)const
// {
// 	return(this->str == other.str);
// }
// bool bigint::operator!=(const bigint& other)const
// {
// 	return(!(this->str == other.str));
// }

// // ****** bigint uint ******
// // ****** bigint uint ******

// bigint bigint::operator>>(unsigned int n)const
// {
// 	bigint tmp = *this;

// 	if(tmp.str.size() < n)
// 		tmp.str="0";
// 	else
// 		tmp.str.erase(tmp.str.size() - n,n);
// 	return(tmp);
// }

// bigint& bigint::operator>>=(unsigned int n)
// {
// 	(*this)=(*this)>>n;
// 	return(*this);
// }

// bigint bigint::operator<<(unsigned int n)const
// {
// 	bigint tmp = (*this);
// 	if(tmp.str == "0" )
// 		return(tmp);
// 	tmp.str.append(n,'0');
// 	return(tmp);
// }

// bigint& bigint::operator<<=(unsigned int n)
// {
// 	(*this)=(*this)<<n;
// 	return(*this);
// }

// // ****** bigint ******
// // ****** bigint ******

// bigint bigint::operator>>(const bigint& other)const
// {
// 	bigint tmp = *this;
// 	(tmp)=(tmp)>>stringToInt(other.str);
//         return(tmp);
// }

// bigint& bigint::operator>>=(const bigint& other)
// {
// 	(*this)=(*this)>>stringToInt(other.str);
//         return(*this);
// }

// bigint bigint::operator<<(const bigint& other)const
// {

// 	bigint tmp = *this;
// 	(tmp)=(tmp)<<stringToInt(other.str);
// 	return(tmp);
// }

// bigint& bigint::operator<<=(const bigint& other)
// {
// 	 (*this)=(*this)<<stringToInt(other.str);
//         return(*this);
// }

// std::ostream& operator<<(std::ostream& os, const bigint& other)
// {
// 	os<<other.get_str();
// 	return(os);
// }









