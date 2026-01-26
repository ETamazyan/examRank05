#include "set.hpp"
#include "iostream"

set::~set(){}
set::set(const set& other):bag(other.bag){}
set::set(searchable_bag& other):bag(other){std::cout<<"bulki\n";}
set& set::operator=(const set& other)
{
    if(this!=&other)
        this->bag=other.bag;
    return(*this);
}
bool set::has(int value)const
{
    return(bag.has(value));
}
void set::insert(int value)
{
    if(!(this->has(value)))
        bag.insert(value);
}
void set::insert(int* data,int value)
{
    for(int i =0; i < value;i++)
        this->insert(data[i]);
}
void set::print()const
{
    bag.print();
}
void set::clear()
{
    bag.clear();
}
searchable_bag& set::get_bag()const
{
    return(this->bag);
}