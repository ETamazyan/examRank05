#include <iostream>
#include <sstream>

class vect2
{
private:
    int x;
    int y;
public:
    vect2();
    ~vect2();
    vect2(int num1,int num2);
    vect2(const vect2& other);

    vect2 operator-()const;
    vect2& operator*=(int num);
    vect2 operator*(int num)const;

    vect2& operator++();
    vect2 operator++(int);

    vect2& operator--();
    vect2 operator--(int);

    int operator[](int index)const;
    int& operator[](int index);

    vect2 operator+(const vect2& other)const;
    vect2 operator-(const vect2& other)const;
    vect2 operator*(const vect2& other)const;

    vect2& operator+=(const vect2& other);
    vect2& operator-=(const vect2& other);
    vect2& operator*=(const vect2& other);

    bool operator==(const vect2& other);
    bool operator!=(const vect2& other);
};

vect2 operator*(int num,const vect2& other);
std::ostream& operator<<(std::ostream& os,const vect2& other);

