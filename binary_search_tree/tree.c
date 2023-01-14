/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 00:17:11 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/07 00:17:11 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binary_search_tree.h"

t_node	*bst_search(t_node *root, t_data key)
{
	if (root == NULL || root->key == key)
		return (root);
	if (key < root->key)
		return (bst_search(root->left, key));
	return (bst_search(root->right, key));
}

t_node	*bst_insert(t_node *root, t_data key)
{
	if (root == NULL)
		return (create_node(key));
	if (key < root->key)
		root->left = bst_insert(root->left, key);
	else if (key > root->key)
		root->right = bst_insert(root->right, key);
	return (root);
}

static t_node	*min_value_node(t_node *node)
{
	t_node	*cur;

	cur = node;
	while (cur->left != NULL)
		cur = cur->left;
	return (cur);
}

static t_node	*succssor(t_node *root)
{
	t_node	*temp;

	if (root->left == NULL)
	{
		temp = root->right;
		free(root);
		return (temp);
	}
	else if (root->right == NULL)
	{
		temp = root->left;
		free(root);
		return (temp);
	}
	temp = min_value_node(root->right);
	root->key = temp->key;
	root->right = bst_remove(root->right, temp->key);
	return (root);
}

t_node	*bst_remove(t_node *root, t_data key)
{
	if (root == NULL)
		return (NULL);
	if (key == root->key)
		return (succssor(root));
	if (key < root->key)
		root->left = bst_remove(root->left, key);
	else if (key > root->key)
		root->right = bst_remove(root->right, key);
	return (root);
}
