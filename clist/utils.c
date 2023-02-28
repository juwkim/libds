/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 03:41:27 by juwkim            #+#    #+#             */
/*   Updated: 2023/03/01 06:13:36 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clist.h"

void	clist_init(t_clist *list)
{
	list->size = 0;
	list->tail = NULL;
}

void	clist_destroy(t_clist *list)
{
	while (clist_is_empty(list) == false)
		clist_pop_front(list);
}

bool	clist_is_empty(t_clist *list)
{
	return (list->size == 0);
}

size_t	clist_size(t_clist *list)
{
	return (list->size);
}
