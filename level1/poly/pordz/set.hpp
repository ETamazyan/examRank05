#include "searchable_bag.hpp"

class set
{
	private:
		searchable_bag& bag;
		set();
		set(const set& other);
		set& operator=(const set& rhs);
	public:
		set(searchable_bag& bag);

		bool has(int value)const;
		void insert(int value);
		void insert(int* data, int size);
		void print()const;
		void clear();

		searchable_bag& get_bag()const;
		~set();
};

