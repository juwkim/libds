/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 06:03:30 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/14 06:55:58 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "single_linked_list.h"

void	init(t_single_linked_list *list)
{
	list->head = (t_node *) malloc(sizeof(t_node));
	if (list->head == NULL)
		exit(EXIT_FAILURE);
	list->head->next = NULL;
	list->size = 0;
}

void	destroy(t_single_linked_list *list)
{
	while (list->head->next != NULL)
		pop_front(list);
	free(list->head);
}

bool	is_empty(t_single_linked_list *list)
{
	return (list->size == 0);
}

size_t	size(t_single_linked_list *list)
{
	return (list->size);
}
