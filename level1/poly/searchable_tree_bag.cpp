#include "searchable_tree_bag.hpp"

searchable_tree_bag::searchable_tree_bag() {}

searchable_tree_bag::searchable_tree_bag(const searchable_tree_bag &other) : tree_bag(other) {}

searchable_tree_bag &searchable_tree_bag::operator=(const searchable_tree_bag &other)
{
    if (this != &other)
        tree_bag::operator=(other);
    return (*this);
}

bool searchable_tree_bag::search(node *node, const int value) const
{
    if (!node)
        return (false);
    else if (node->value == value)
        return (true);
    else if (node->value < value)
        return (search(node->r, value));
    else if (node->value > value)
        return (search(node->l, value));
    return (false);
}

bool searchable_tree_bag::has(int value) const
{
    return (search(this->tree, value));
}

searchable_tree_bag::~searchable_tree_bag() {}