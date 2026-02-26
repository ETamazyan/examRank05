#include "searchable_tree_bag.hpp"

bool searchable_tree_bag::search(node *node, int value)const
{
	if (!node)
		return (false);
	if (node->value == value)
		return (true);
	else if(node->value > value)
		return (search(node->l, value));
	else if (node->value < value)
		return (search(node->r, value));
	return (false);
}

searchable_tree_bag::searchable_tree_bag(){}
searchable_tree_bag::searchable_tree_bag(const searchable_tree_bag& other):tree_bag(other){}
searchable_tree_bag& searchable_tree_bag::operator=(const searchable_tree_bag& rhs)
{
	if (this != &rhs)
		tree_bag::operator=(rhs);
	return (*this);
}

searchable_tree_bag::~searchable_tree_bag(){}

bool searchable_tree_bag::has(int value)const
{
	return (search(tree, value));
}

