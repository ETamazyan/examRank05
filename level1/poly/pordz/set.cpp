#include "set.hpp"

set::set(searchable_bag& bag):bag(bag){}

bool set::has(int value)const
{
	return (bag.has(value));
}

void set::insert(int value)
{
	if(!bag.has(value))
		bag.insert(value);
}
void set::insert(int* data, int size)
{
	for(int i = 0; i < size; i++)
		insert(data[i]);
}
void set::print()const{bag.print();}
void set::clear(){bag.clear();}

searchable_bag& set::get_bag()const
{
	return (bag);
}
set::~set(){}

