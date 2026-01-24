#ifndef SET_HPP
#define SET_HPP

#include "searchable_bag.hpp"

class set
{
   private:
   searchable_bag& bag;
   set();
   public:
   ~set();
   set(const set& other);
   set(searchable_bag &other);
   set operator=(const set& other);
    void insert (int);
    void insert (int *, int);
    void print() const;
    void clear();
    bool has(int) const;
    searchable_bag& get_bag()const;



};
#endif