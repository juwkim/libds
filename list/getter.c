/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 05:36:45 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/14 05:40:03 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_data	front(t_list *list)
{
	return (get_item(list, 0));
}

t_data	back(t_list *list)
{
	return (get_item(list, list->size - 1));
}

t_data	get_item(t_list *list, int pos)
{
	return (list->items[pos]);
}
