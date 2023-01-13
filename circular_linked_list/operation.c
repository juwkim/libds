/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 07:26:55 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/14 08:08:11 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circular_linked_list.h"

void	print(t_circular_linked_list *list)
{
	t_node	*cur;

	cur = list->tail->next;
	while (cur != NULL)
	{
		ft_printf("%06d", cur->item);
		cur = cur->next;
	}
}

void	reverse(t_circular_linked_list *list)
{
	t_node	*prev;
	t_node	*cur;
	t_node	*next;

	cur = NULL;
	next = list->tail->next;
	while (next != NULL)
	{
		prev = cur;
		cur = next;
		next = next->next;
		cur->next = prev;
	}
	list->tail->next = cur;
}

t_circular_linked_list	*concatenate(t_circular_linked_list *list1, \
										t_circular_linked_list *list2)
{
	t_circular_linked_list *const	list = \
		(t_circular_linked_list *) malloc(sizeof(t_circular_linked_list));
	t_node							*cur;

	if (list == NULL)
		exit(EXIT_FAILURE);
	init(list);
	cur = list1->tail->next;
	while (cur)
	{
		push_back(list, cur->item);
		cur = cur->next;
	}
	cur = list2->tail->next;
	while (cur)
	{
		push_back(list, cur->item);
		cur = cur->next;
	}
	return (list);
}
