#include "searchable_tree_bag.hpp"

searchable_tree_bag::searchable_tree_bag(){}

searchable_tree_bag::searchable_tree_bag(const searchable_tree_bag& other){}
searchable_tree_bag& searchable_tree_bag::operator=(const searchable_tree_bag& rhs)
{
	if (this != &rhs)
		tree_bag::operator=(rhs);
	return *this;
}

bool searchable_tree_bag::has(int value)
{
	return (search(tree, value));
}
bool searchable_tree_bag::search(node * node, int value) const
{
	if (!node)
		return (false);
	else if (node->value == value)
		return (true);
	else if (node-> value < value)
		return (search(node->r, value));
	else if (node-> value > value)
		return (search(node->l, value));
	return (false);
}

searchable_tree_bag::~searchable_tree_bag(){}