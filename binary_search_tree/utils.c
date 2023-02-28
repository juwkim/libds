/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 13:20:34 by juwkim            #+#    #+#             */
/*   Updated: 2023/03/01 05:53:07 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binary_search_tree.h"

t_bst_node	*bst_create_node(t_bst_data key)
{
	t_bst_node *const	new_node = (t_bst_node *) malloc(sizeof(t_bst_node));

	assert(new_node != NULL);
	new_node->key = key;
	new_node->left = NULL;
	new_node->right = NULL;
	return (new_node);
}

void	bst_destroy(t_bst_node *root)
{
	if (root == NULL)
		return ;
	bst_destroy(root->left);
	bst_destroy(root->right);
	free(root);
}

size_t	bst_get_height(t_bst_node *root)
{
	size_t	left_height;
	size_t	right_height;

	left_height = 0;
	right_height = 0;
	if (root->left != NULL)
		left_height = bst_get_height(root->left);
	if (root->right != NULL)
		right_height = bst_get_height(root->right);
	if (left_height > right_height)
		return (left_height + 1);
	return (right_height + 1);
}

size_t	bst_count_nodes(t_bst_node	*root)
{
	size_t	left_nodes;
	size_t	right_nodes;

	left_nodes = 0;
	right_nodes = 0;
	if (root->left != NULL)
		left_nodes = bst_count_nodes(root->left);
	if (root->right != NULL)
		right_nodes = bst_count_nodes(root->right);
	return (left_nodes + right_nodes + 1);
}
