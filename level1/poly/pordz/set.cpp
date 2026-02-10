#include "set.hpp"

set::set(searchable_bag& other):bag(other){}
set::~set(){}

bool has(int value);
void insert(int value);
void insert(int *data, int size);
void print()const;
void clear();

searchable_bag& get_bag()const;
