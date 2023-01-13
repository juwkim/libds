/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 03:39:53 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/14 03:39:53 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circular_linked_list.h"

t_node	*create_node(t_data item)
{
	t_node *const	new_node = (t_node*) malloc(sizeof(t_node));

	if (new_node == NULL)
		exit(EXIT_FAILURE);
	new_node->item = item;
	return (new_node);
}
