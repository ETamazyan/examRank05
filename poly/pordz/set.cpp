#include "set.hpp"

 set::~set(){}
 set::set(searchable_bag& s):bag(s){}
 set::set(const set& s):bag(s.bag){}
 set& set::operator=(const set& other){
    if(this!=&other)
    this->bag=other.bag;
    return(*this);

 }
 bool set::has(int value)
 {
    return(bag.has(value));
 }
 void set::insert (int value)
 {
    if(!(has(value)))
        bag.insert(value);
 }
void set::insert (int *data, int value)
{
    for(int i =0;i < value;i++)
        insert(value);
}
void set::print() const
{
    std::cout<<"llll\n";
    bag.print();
}
void set::clear()
{
    bag.clear();
}
 searchable_bag& set::get_bag()
 {
    return(this->bag);
 }