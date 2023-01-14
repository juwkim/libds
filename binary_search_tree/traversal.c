/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traversal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 13:09:59 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/14 14:55:59 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binary_search_tree.h"

void	inorder(t_node *root)
{
	if (root == NULL)
		return ;
	inorder(root->left);
	ft_printf("%06d", root->key);
	inorder(root->right);
}

void	preorder(t_node *root)
{
	if (root == NULL)
		return ;
	ft_printf("%06d", root->key);
	preorder(root->left);
	preorder(root->right);
}

void	postorder(t_node *root)
{
	if (root == NULL)
		return ;
	postorder(root->left);
	postorder(root->right);
	ft_printf("%06d", root->key);
}

/*
void	levelorder(t_node *root)
{
	t_dqueue	dq;

	dq_init(&dq);
	push_back(&dq, root);
	while (is_empty(&dq) == false)
	{
		root = front(&dq);
		pop_front(&dq);
		printf("%06d", root->key);
		if (root->left != NULL)
			push_back(&dq, root->left);
		if (root->right != NULL)
			push_back(&dq, root->right);
	}
}
*/
