/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 05:36:45 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/18 02:47:14 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_list_data	list_front(t_list *list)
{
	return (list_get_item(list, 0));
}

t_list_data	list_back(t_list *list)
{
	return (list_get_item(list, list->size - 1));
}

t_list_data	list_get_item(t_list *list, int pos)
{
	return (list->items[pos]);
}
