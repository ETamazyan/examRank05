#pragma once

#include "searchable_bag.hpp"

class set
{
    private:
        searchable_bag& bag;
        set();
        set(const set& other);
        set& operator=(const set& other);
    public:
        set(searchable_bag& other);
        
        bool has(int)const;
        void insert(int);
        void insert(int*,int);
        void print()const;
        void clear();
        
        searchable_bag& get_bag()const;

        ~set();
};











// class set
// {
// private:
// 	searchable_bag	&_bag;
// public:
// 	set() = delete;
// 	set(searchable_bag &bag);
// 	set(const set &other) = delete ;

// 	set	&operator=(const set &other) = delete ;

// 	bool has(int) const ;
// 	void insert(int);
// 	void insert(int *, int);
// 	void print() const;
// 	void clear();

// 	const searchable_bag& get_bag();

// 	~set();
// };
