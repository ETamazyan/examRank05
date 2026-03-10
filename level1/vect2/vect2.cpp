#include "vect2.hpp"

vect2::vect2():x(0),y(0){}

vect2::~vect2(){}
 
vect2::vect2(const vect2& other):x(other.x),y(other.y){}
 
vect2& vect2::operator=(const vect2& other)
{
	if(this!=&other)
	{
		this->x=other.x;
		this->y=other.y;
	}
	return(*this);
}
vect2::vect2(int num1,int num2):x(num1),y(num2){}

int& vect2:: operator[](int index)
{
	if(index == 0)
		return(this->x);
	return(this->y);
}

int vect2:: operator[](int index)const
{
	if(index == 0)
                return(this->x);
        return(this->y);
}


vect2 vect2::operator-()const
{
	// vect2 t=*this; // v1
	// t[0]=-t[0];
	// t[1]=-t[1];
	// return(t);
	return (vect2(-x, -y)); // v2

}

vect2& vect2::operator--()
{
	//   this->x-=1; // v1
    //     this->y-=1;
    //     return(*this);
	x--; // v2
	y--;

	return (*this);
}

vect2 vect2::operator--(int)
{
	vect2 tmp(*this);
	--(*this);
	
	return(tmp);
}


vect2& vect2::operator++()
{
	// this->x+=1; //v1
	// this->y+=1;
	// return(*this);
	x++; // v2
	y++;

	return (*this);
}

vect2 vect2::operator++(int)
{
	vect2 tmp(*this);
	++(*this);
	return(tmp);
}

// continue from this

vect2 vect2::operator*(int num)const
{
	// vect2 tmp =(*this); //v1
	// tmp.x=num * tmp.x;
	// tmp.y=num*tmp.y;
	// return(tmp);
	return (vect2(x * num, y * num)); //v2

}

vect2& vect2::operator*=(int num)
{
	//  this->x=this->x*num; //v1
    //     this->y=this->y*num;
    //     return(*this);
	x *= num; // v2
	y *= num;

	return (*this);

}

vect2 vect2::operator+(const vect2& other)const
{
	// vect2 tmp=(*this); //v1
	// tmp.x=tmp.x+other.x;
	// tmp.y=tmp.y+other.y;
	// return(tmp);
	return (vect2(x + other.x, y + other.y)); //v2

}

vect2 vect2::operator-(const vect2& other)const
{
	//  vect2 tmp=(*this); //v1
    //     tmp.x=tmp.x-other.x;
    //     tmp.y=tmp.y-other.y;
    //     return(tmp);
	return (vect2(x - other.x, y - other.y)); //v2
}

vect2& vect2::operator+=(const vect2& other)
{
	// this->x=this->x+other.x; //V1
	// this->y=this->y+other.y;
	// return(*this);
	(*this) = (*this) + other; // V2
	return (*this);

}

vect2& vect2::operator-=(const vect2& other)
{
	// this->x=this->x-other.x; //v1
    //     this->y=this->y-other.y;
    //     return(*this);
	(*this) = (*this) - other; //v2
	return (*this);
}

bool vect2::operator==(const vect2& other)
{
	return((this->x==other.x) && (this->y==other.y));
}

bool vect2::operator!=(const vect2& other)
{
	return (x != other.x || y != other.y);

}
vect2	operator*(int num, const vect2 &obj)
{
	vect2	result(obj);
	
	result = result * num;
	return (result);
}

std::ostream& operator<<(std::ostream& os,const vect2& other)
{
	os<<"{" << other[0] << ", " << other[1] << "}";
	return(os);
}
