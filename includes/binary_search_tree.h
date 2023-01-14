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
# include <stdlib.h>

# include "dqueue.h"
# include "libft_headers/ft_math.h"
# include "libft_headers/ft_printf.h"

typedef int	t_data;

typedef struct s_node
{
	t_data			key;
	struct s_node	*left;
	struct s_node	*right;
}	t_node;

// utils.c
t_node	*create_node(t_data key);
size_t	get_height(t_node *root);
size_t	count_nodes(t_node	*root);
void	destroy(t_node *root);

// tree.c
t_node	*bst_search(t_node *root, t_data key);
t_node	*bst_insert(t_node *root, t_data key);
t_node	*bst_remove(t_node *root, t_data key);

// traversal.c
void	inorder(t_node *root);
void	preorder(t_node *root);
void	postorder(t_node *root);
// void	levelorder(t_node *root);

#endif // BINARY_SEARCH_TREE_H
