/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 00:16:46 by juwkim            #+#    #+#             */
/*   Updated: 2023/03/01 06:47:32 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

static int	__get_total_len(t_list *list);

void	list_print(t_list *list)
{
	t_list_node	*cur;

	cur = list->head->next;
	printf(YELLOW"%s "DEF_COLOR, (char *) cur->item);
	while (cur->next != NULL)
	{
		cur = cur->next;
		printf(GREEN"%s "DEF_COLOR, (char *) cur->item);
	}
}

void	list_reverse(t_list *list)
{
	t_list_node	*prev;
	t_list_node	*cur;
	t_list_node	*next;

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

t_list	*list_concatenate(t_list *list1, t_list *list2)
{
	t_list *const	list = (t_list *) malloc(sizeof(t_list));
	t_list_node		*cur;

	assert(list != NULL);
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

char	*list_strjoin(t_list *list)
{
	t_list_node	*cur;
	int			idx;
	int			str_len;
	const int	total_len = __get_total_len(list);
	char *const	str = malloc(sizeof(char) * (total_len + 1));

	assert(str != NULL);
	cur = list->head->next;
	idx = 0;
	while (cur != NULL)
	{
		str_len = strlen(cur->item);
		memcpy(str + idx, cur->item, str_len);
		idx += str_len;
		cur = cur->next;
	}
	str[total_len] = '\0';
	list_destroy(list, free);
	return (str);
}

static int	__get_total_len(t_list *list)
{
	t_list_node	*cur;
	int			total_len;

	total_len = 0;
	cur = list->head->next;
	while (cur != NULL)
	{
		total_len += strlen(cur->item);
		cur = cur->next;
	}
	return (total_len);
}
