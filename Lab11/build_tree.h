#ifndef BUILD_TREE_H
#define BUILD_TREE_H

#include "bintree.h"

/**
 *  This is a helper function
 */
template <class T>
binary_tree_node<T>* build_from_node_lists(
	const T preorder[], const T inorder[],
	size_t pre_start, size_t pre_end,
	size_t in_start, size_t in_end
) {
	if (pre_start >= pre_end)
		return  NULL;
	const T rootval = preorder[pre_start];
	size_t r = in_start;
	while (r < in_end && inorder[r] != rootval) {
		r++;
	}

	assert(r < in_end);
	size_t lsize = r - in_start;

	binary_tree_node<T>* left = build_from_node_lists(preorder, inorder,
		pre_start + 1, pre_start + lsize + 1,
		in_start, r);
	binary_tree_node<T>* right = build_from_node_lists(preorder, inorder,
		pre_start + lsize + 1, pre_end,
		r + 1, in_end);
	return new binary_tree_node<T>(rootval, left, right);
}

/**
 * Given the preorder and inorder list of binary tree nodes,
 * recreate the binary tree.
 * precondition: preorder and inorder are both of size 'size'.
 */
template <class T>
binary_tree_node<T>* build_from_node_lists(
	const T preorder[], const T inorder[], size_t size
) {
	return build_from_node_lists(preorder, inorder, 0, size, 0, size);
}


/*
 * The following functions each return a sample binary tree that you can
 * use to try out various functions you have created.
 */

binary_tree_node<int>* sample1();

binary_tree_node<int>* sample2();

binary_tree_node<double>* sample3();

binary_tree_node<double>* sample4();

binary_tree_node<std::string>* sample5();

binary_tree_node<double>* sample_bal1();

binary_tree_node<double>* sample_bal2();

#endif // BUILD_TREE_H
