/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 06:03:30 by juwkim            #+#    #+#             */
/*   Updated: 2023/02/09 09:46:48 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

bool	list_init(t_list *list)
{
	list->head = (t_node *) malloc(sizeof(t_node));
	if (list->head == NULL)
		return (false);
	list->head->next = NULL;
	list->size = 0;
	return (true);
}

void	list_destroy(t_list *list, void (*del)(void *))
{
	while (list->head->next != NULL)
		list_pop_front(list, del);
	free(list->head);
}

bool	list_is_empty(t_list *list)
{
	return (list->size == 0);
}

size_t	list_size(t_list *list)
{
	return (list->size);
}
