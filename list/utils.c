/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 05:31:04 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/18 02:11:54 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	list_init(t_list *list)
{
	list->size = 0;
}

bool	list_is_empty(t_list *list)
{
	return (list->size == 0);
}

bool	list_is_full(t_list *list)
{
	return (list->size == LIST_SIZE);
}

size_t	list_size(t_list *list)
{
	return (list->size);
}
