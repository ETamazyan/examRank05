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
		set(searchable_bag &bag);
		~set();

		void insert(int value);
		void insert(int *node, int value);
		void print() const;
		void clear();

		bool has(int value)const;
};