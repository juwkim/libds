/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 13:20:34 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/14 15:03:10 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binary_search_tree.h"

t_node	*create_node(t_data key)
{
	t_node *const	new_node = (t_node *) malloc(sizeof(t_node));

	if (new_node == NULL)
		exit(EXIT_FAILURE);
	new_node->key = key;
	new_node->left = NULL;
	new_node->right = NULL;
	return (new_node);
}

void	destroy(t_node *root)
{
	if (root == NULL)
		return ;
	destroy(root->left);
	destroy(root->right);
	free(root);
}

size_t	get_height(t_node *root)
{
	size_t	left_height;
	size_t	right_height;

	left_height = 0;
	right_height = 0;
	if (root->left != NULL)
		left_height = get_height(root->left);
	if (root->right != NULL)
		right_height = get_height(root->right);
	return (ft_max(left_height, right_height) + 1);
}

size_t	count_nodes(t_node	*root)
{
	size_t	left_nodes;
	size_t	right_nodes;

	left_nodes = 0;
	right_nodes = 0;
	if (root->left != NULL)
		left_nodes = count_nodes(root->left);
	if (root->right != NULL)
		right_nodes = count_nodes(root->right);
	return (left_nodes + right_nodes + 1);
}
