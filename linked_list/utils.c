/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 06:03:30 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/30 17:50:58 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

void	list_init(t_linked_list *list)
{
	list->head = (t_node *) malloc(sizeof(t_node));
	if (list->head == NULL)
		exit(EXIT_FAILURE);
	list->head->next = NULL;
	list->size = 0;
}

void	list_destroy(t_linked_list *list)
{
	while (list->head->next != NULL)
		list_pop_front(list);
	free(list->head);
}

bool	list_is_empty(t_linked_list *list)
{
	return (list->size == 0);
}

size_t	list_size(t_linked_list *list)
{
	return (list->size);
}
