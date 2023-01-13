/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 03:41:27 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/14 05:21:27 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circular_linked_list.h"

void	init(t_circular_list *list)
{
	list->size = 0;
	list->tail = NULL;
}

void	destroy(t_circular_list *list)
{
	while (is_empty(list) == false)
		pop_front(list);
}

bool	is_empty(t_circular_list *list)
{
	return (list->size == 0);
}

size_t	size(t_circular_list *list)
{
	return (list->size);
}

t_node	*create_node(t_data item)
{
	t_node *const	new_node = (t_node*) malloc(sizeof(t_node));

	if (new_node == NULL)
		exit(EXIT_FAILURE);
	new_node->item = item;
	return (new_node);
}
