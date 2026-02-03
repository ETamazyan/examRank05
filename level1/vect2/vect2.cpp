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
	// vect2 t=*this;
	// t[0]=-t[0];
	// t[1]=-t[1];
	// return(t);
	return (vect2(-x, -y));

}

vect2& vect2::operator--()
{
	//   this->x-=1;
    //     this->y-=1;
    //     return(*this);
	x--;
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
	// this->x+=1;
	// this->y+=1;
	// return(*this);
	x++;
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
	// vect2 tmp =(*this);
	// tmp.x=num * tmp.x;
	// tmp.y=num*tmp.y;
	// return(tmp);
	return (vect2(x * num, y * num));

}

vect2& vect2::operator*=(int num)
{
	//  this->x=this->x*num;
    //     this->y=this->y*num;
    //     return(*this);
	x *= num;
	y *= num;

	return (*this);

}


// vect2 vect2::operator*(const vect2& other)const
// {
// 	 vect2 tmp=(*this);
//         tmp.x=tmp.x*other.x;
//         tmp.y=tmp.y*other.y;
//         return(tmp);
// }

vect2 vect2::operator+(const vect2& other)const
{
	// vect2 tmp=(*this);
	// tmp.x=tmp.x+other.x;
	// tmp.y=tmp.y+other.y;
	// return(tmp);
	return (vect2(x + other.x, y + other.y));

}

vect2 vect2::operator-(const vect2& other)const
{
	//  vect2 tmp=(*this);
    //     tmp.x=tmp.x-other.x;
    //     tmp.y=tmp.y-other.y;
    //     return(tmp);
	return (vect2(x - other.x, y - other.y));
}

// vect2& vect2::operator*=(const vect2& other)
// {
// 	this->x=this->x*other.x;
//         this->y=this->y*other.y;
//         return(*this);
// }

vect2& vect2::operator+=(const vect2& other)
{
	// this->x=this->x+other.x;
	// this->y=this->y+other.y;
	// return(*this);
	(*this) = (*this) + other;
	return (*this);

}

vect2& vect2::operator-=(const vect2& other)
{
	// this->x=this->x-other.x;
    //     this->y=this->y-other.y;
    //     return(*this);
	(*this) = (*this) - other;
	return (*this);
}

bool vect2::operator==(const vect2& other)
{
	return((this->x==other.x) && (this->y==other.y));
}

bool vect2::operator!=(const vect2& other)
{
	// return(!(*this==other));
	return (x != other.x || y != other.y);

}

// vect2 operator*(int num,const vect2& other)
// {
// 	// vect2 o =other;
// 	// o*=num;
// 	// return(o);

// }

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
