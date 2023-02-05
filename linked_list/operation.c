/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 00:16:46 by juwkim            #+#    #+#             */
/*   Updated: 2023/02/03 04:42:14 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

void	list_print(t_linked_list *list)
{
	t_node	*cur;

	cur = list->head->next;
	printf(YELLOW"%s "DEF_COLOR, cur->item);
	cur = cur->next;
	while (cur != NULL)
	{
		printf(GREEN"%s "DEF_COLOR, cur->item);
		cur = cur->next;
	}
}

void	list_reverse(t_linked_list *list)
{
	t_node	*prev;
	t_node	*cur;
	t_node	*next;

	cur = NULL;
	next = list->head->next;
	while (next != NULL)
	{
		prev = cur;
		cur = next;
		next = next->next;
		cur->next = prev;
	}
	list->head->next = cur;
}

t_linked_list	*list_concatenate(t_linked_list *list1, t_linked_list *list2)
{
	t_linked_list *const	list = \
							(t_linked_list *) malloc(sizeof(t_linked_list));
	t_node					*cur;

	if (list == NULL)
		exit(EXIT_FAILURE);
	list_init(list);
	cur = list1->head->next;
	while (cur)
	{
		list_push_back(list, cur->item);
		cur = cur->next;
	}
	cur = list2->head->next;
	while (cur)
	{
		list_push_back(list, cur->item);
		cur = cur->next;
	}
	return (list);
}
