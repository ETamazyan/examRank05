#include "searchable_bag.hpp"

class set
{
	private:
		set();
		set(const set& other);
		set& operator=(const set& rhs);
		searchable_bag &bag;
	public:
		set(searchable_bag& other);
		~set();

		bool has(int value);
		void insert(int value);
		void insert(int *data, int size);
		void print()const;
		void clear();

		searchable_bag& get_bag()const;
}