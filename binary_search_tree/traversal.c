/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traversal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 13:09:59 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/16 10:29:27 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binary_search_tree.h"

void	bst_inorder(t_bst_node *root)
{
	if (root == NULL)
		return ;
	bst_inorder(root->left);
	ft_printf("%06d", root->key);
	bst_inorder(root->right);
}

void	bst_preorder(t_bst_node *root)
{
	if (root == NULL)
		return ;
	ft_printf("%06d", root->key);
	bst_preorder(root->left);
	bst_preorder(root->right);
}

void	bst_postorder(t_bst_node *root)
{
	if (root == NULL)
		return ;
	bst_postorder(root->left);
	bst_postorder(root->right);
	ft_printf("%06d", root->key);
}

// void	bst_levelorder(t_bst_node *root)
// {
// 	t_deque	dq;

// 	dq_init(&dq);
// 	push_back(&dq, root);
// 	while (is_empty(&dq) == false)
// 	{
// 		root = front(&dq);
// 		pop_front(&dq);
// 		ft_printf("%06d", root->key);
// 		if (root->left != NULL)
// 			push_back(&dq, root->left);
// 		if (root->right != NULL)
// 			push_back(&dq, root->right);
// 	}
// }
