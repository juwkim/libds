/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 00:17:15 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/07 00:17:15 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINARY_SEARCH_TREE_H
# define BINARY_SEARCH_TREE_H

# include <stdio.h>
# include <assert.h>
# include <stdlib.h>

# include "deque.h"

typedef int	t_bst_data;

typedef struct s_bst_node
{
	t_bst_data			key;
	struct s_bst_node	*left;
	struct s_bst_node	*right;
}	t_bst_node;

// utils.c
t_bst_node	*bst_create_node(t_bst_data key);
size_t		bst_get_height(t_bst_node *root);
size_t		bst_count_nodes(t_bst_node *root);
void		bst_destroy(t_bst_node *root);

// tree.c
t_bst_node	*bst_search(t_bst_node *root, t_bst_data key);
t_bst_node	*bst_insert(t_bst_node *root, t_bst_data key);
t_bst_node	*bst_remove(t_bst_node *root, t_bst_data key);

// traversal.c
void		bst_inorder(t_bst_node *root);
void		bst_preorder(t_bst_node *root);
void		bst_postorder(t_bst_node *root);
// void		bst_levelorder(t_bst_node *root);

#endif // BINARY_SEARCH_TREE_H
