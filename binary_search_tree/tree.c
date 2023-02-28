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

static t_bst_node	*__bst_min_value_node(t_bst_node *node);
static t_bst_node	*__bst_succssor(t_bst_node *root);

t_bst_node	*bst_search(t_bst_node *root, t_bst_data key)
{
	if (root == NULL || root->key == key)
		return (root);
	if (key < root->key)
		return (bst_search(root->left, key));
	return (bst_search(root->right, key));
}

t_bst_node	*bst_insert(t_bst_node *root, t_bst_data key)
{
	if (root == NULL)
		return (bst_create_node(key));
	if (key < root->key)
		root->left = bst_insert(root->left, key);
	else if (key > root->key)
		root->right = bst_insert(root->right, key);
	return (root);
}

t_bst_node	*bst_remove(t_bst_node *root, t_bst_data key)
{
	if (root == NULL)
		return (NULL);
	if (key == root->key)
		return (__bst_succssor(root));
	if (key < root->key)
		root->left = bst_remove(root->left, key);
	else if (key > root->key)
		root->right = bst_remove(root->right, key);
	return (root);
}

static t_bst_node	*__bst_min_value_node(t_bst_node *node)
{
	t_bst_node	*cur;

	cur = node;
	while (cur->left != NULL)
		cur = cur->left;
	return (cur);
}

static t_bst_node	*__bst_succssor(t_bst_node *root)
{
	t_bst_node	*temp;

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
	temp = __bst_min_value_node(root->right);
	root->key = temp->key;
	root->right = bst_remove(root->right, temp->key);
	return (root);
}
