#include "bigint.hpp"

bigint::bigint():str("0"){}

bigint::~bigint(){}

bigint::bigint(const bigint &other):str(other.str){}

bigint::bigint(unsigned int num)
{
	std::stringstream ss;
	ss << num;
	str = ss.str();
}

std::string bigint::get_str()const
{
	return(this->str);
}

int bigint::stringToInt(std::string s)const
{
	std::stringstream ss(s);
	int num;
	ss >> num;
	return(num);
}

bigint& bigint:: operator=(const bigint &other)
{
	if(this != &other)
		this->str=other.str;
	return(*this);
}

bigint bigint:: operator+(const bigint &other)const
{
	bigint res;
	res.str.clear();

	int i = this->str.size() - 1;
	int j = other.str.size() - 1;
	int temp = 0;

	while(i >= 0 || j >= 0|| temp)
	{
		int sum = temp;
		if(i>=0)
		sum+=this->str[i--] - '0';
		if(j>=0)
		sum+=other.str[j--] - '0';
		res.str.insert(res.str.begin(),(sum % 10)+'0');
		temp=sum/10;
	}
	return(res);
}
bigint& bigint::operator+=(const bigint &other)
{
	(*this)= (*this) + other;
	return(*this);
}

bigint& bigint::operator++()
{
	(*this)+=bigint(1);
	return(*this);
}
bigint bigint::operator++(int)
{
	bigint tmp=*this;
	++(*this);
	return(tmp);
}

// **** operator bool *****
// **** operator bool *****

bool bigint::operator<(const bigint& other)const
{
	if(this->str.size()!=other.str.size())
		return(this->str.size()<other.str.size());
	return(this->str<other.str); 
}
bool bigint::operator<=(const bigint& other)const
{
	return(!(*this > other));
}

bool bigint::operator>(const bigint& other)const
{
	return(other < (*this));

}

bool bigint::operator>=(const bigint& other)const
{
	return(!(*this < other));
}

bool bigint::operator==(const bigint& other)const
{
	return(this->str == other.str);
}
bool bigint::operator!=(const bigint& other)const
{
	return(!(this->str == other.str));
}

// ****** bigint uint ******
// ****** bigint uint ******

bigint bigint::operator>>(unsigned int n)const
{
	bigint tmp = *this;

	if(tmp.str.size() < n)
		tmp.str="0";
	else
		tmp.str.erase(tmp.str.size() - n,n);
	return(tmp);
}

bigint& bigint::operator>>=(unsigned int n)
{
	(*this)=(*this)>>n;
	return(*this);
}

bigint bigint::operator<<(unsigned int n)const
{
	bigint tmp = (*this);
	if(tmp.str == "0" )
		return(tmp);
	tmp.str.append(n,'0');
	return(tmp);
}

bigint& bigint::operator<<=(unsigned int n)
{
	(*this)=(*this)<<n;
	return(*this);
}

// ****** bigint ******
// ****** bigint ******

bigint bigint::operator>>(const bigint& other)const
{
	bigint tmp = *this;
	(tmp)=(tmp)>>stringToInt(other.str);
        return(tmp);
}

bigint& bigint::operator>>=(const bigint& other)
{
	(*this)=(*this)>>stringToInt(other.str);
        return(*this);
}

bigint bigint::operator<<(const bigint& other)const
{

	 bigint tmp = *this;
        (tmp)=(tmp)<<stringToInt(other.str);
        return(tmp);

}

bigint& bigint::operator<<=(const bigint& other)
{
	 (*this)=(*this)<<stringToInt(other.str);
        return(*this);

}

std::ostream& operator<<(std::ostream& os, const bigint& other)
{
	os<<other.get_str();
	return(os);
}









