#include "searchable_array_bag.hpp"

  searchable_array_bag::searchable_array_bag(){}
  searchable_array_bag::~searchable_array_bag(){}
    searchable_array_bag::searchable_array_bag(const searchable_array_bag& bag):array_bag(){}
    searchable_array_bag& searchable_array_bag::operator=(const searchable_array_bag& bag)
    {
        if(this!=&bag)
            array_bag::operator=(bag);
        return(*this);
    }
    bool searchable_array_bag::has(int value) const
    {
        for(int i=0;i<size;i++)
            if(data[i] == value)
                return(true);
        return(false);
    }