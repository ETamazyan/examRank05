#pragma once

#include "searchable_bag.hpp"

class set
{
	private:
		searchable_bag& bag;
		set();
		set(const set& other);
		set& operator=(const set& rhs);
	public:
		set(searchable_bag &other);

		bool has(int value)const;

		void insert(int);
		void insert(int*, int);
		void clear();
		void print()const;

		const searchable_bag& get_bag();

		~set();
};