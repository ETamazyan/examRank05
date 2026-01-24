#pragma once

#include "searchable_bag.hpp"
#include <iostream>

class set
{
    private:
    searchable_bag& bag;
    set();

    public:
    ~set();
    set(const set& bag);
    set( searchable_bag& bag);
    set& operator=(const set& bag);
     void insert (int) ;
	 void insert (int *, int) ;
	 void print() const ;
	 void clear() ;
      bool has(int value);
      searchable_bag& get_bag();

};