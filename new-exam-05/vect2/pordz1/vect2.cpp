#include "vect2.hpp"

vect2::vect2():x(0),y(0){}
vect2::~vect2(){}
vect2::vect2(int num1,int num2):x(num1),y(num2){}
vect2::vect2(const vect2& other):x(other.x),y(other.y){}

vect2 vect2:: operator-()const///const
{
    vect2 tmp =*this;

    tmp[0]=-tmp[0];
    tmp[1]=-tmp[1];

    return(tmp);
}
vect2& vect2::operator*=(int num)
{
        this->x=this->x*num;
        this->y=this->y*num;

        return(*this);
    }
    vect2 vect2::operator*(int num)const
    {
        vect2 tmp=*this;

        tmp.x=tmp.x*num;
        tmp.y=tmp.y*num;

        return(tmp);
    }

    vect2& vect2::operator++()
    {
         this->x=this->x+1;
        this->y=this->y+1;

        return(*this);
    }
    vect2 vect2::operator++(int)
    {
        vect2 tmp=*this;

       ++(*this);//poxum enq himnakany

        return(tmp);
    }

    vect2& vect2::operator--()
    {
         this->x=this->x-1;
        this->y=this->y-1;

        return(*this);
    }
    vect2 vect2::operator--(int)
    {
         vect2 tmp=*this;

        --(*this);////poxum enq himnakany

        return(tmp);
    }

    int vect2::operator[](int index)const
    {
        if(index==0)
            return(this->x);
        return(this->y);
    }
    int& vect2::operator[](int index)//& um ov
    {
        if(index==0)
            return(this->x);
        return(this->y);
    }

    vect2 vect2::operator+(const vect2& other)const
    {
        vect2 tmp=*this;

        tmp.x=tmp.x+other.x;
        tmp.y=tmp.y+other.y;

        return(tmp);
    }
    vect2 vect2::operator-(const vect2& other)const
    {
        vect2 tmp=*this;

        tmp.x=tmp.x-other.x;
        tmp.y=tmp.y-other.y;

        return(tmp);
    }
    vect2 vect2::operator*(const vect2& other)const
    {
        vect2 tmp=*this;

        tmp.x=tmp.x*other.x;
        tmp.y=tmp.y*other.y;

        return(tmp);
    }

    vect2& vect2::operator+=(const vect2& other)
    {
        this->x=this->x+other.x;
        this->y=this->y+other.y;

        return(*this);
    }
    vect2& vect2::operator-=(const vect2& other)
    {
        this->x=this->x-other.x;
        this->y=this->y-other.y;

        return(*this);
    }
    vect2& vect2::operator*=(const vect2& other)
    {
        this->x=this->x*other.x;
        this->y=this->y*other.y;

        return(*this);
    }

    bool vect2::operator==(const vect2& other)
    {
        return(this->x==other.x && this->y==other.y);
    }
    bool vect2::operator!=(const vect2& other)
    {
        return(!(*this==other));
    }

    vect2 operator*(int num,const vect2& other)
    {
        vect2 tmp;
        tmp = other*num;
        return(tmp);
    }
std::ostream& operator<<(std::ostream& os,const vect2& other)
{
    os<< "{" << other[0] << ", " << other[1] << "}" << std::endl;
    return(os);
}