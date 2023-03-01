/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 06:03:30 by juwkim            #+#    #+#             */
/*   Updated: 2023/03/01 19:54:11 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	list_init(t_list *list)
{
	list->head = (t_list_node *) malloc(sizeof(t_list_node));
	assert(list->head != NULL);
	list->head->next = NULL;
	list->size = 0;
}

void	list_destroy(t_list *list, void (*del)(void *))
{
	while (list->head->next != NULL)
		list_pop_front(list, del);
	free(list->head);
}

bool	list_is_empty(const t_list *list)
{
	return (list->size == 0);
}

size_t	list_size(const t_list *list)
{
	return (list->size);
}
