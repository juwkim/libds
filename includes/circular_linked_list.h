/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circular_linked_list.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 00:15:44 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/07 00:15:44 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CIRCULAR_LINKED_LIST_H
# define CIRCULAR_LINKED_LIST_H

# include <stdlib.h>
# include <stdbool.h>

# include "../../libft/includes/libft.h"

typedef int	t_data;

typedef struct s_node
{
	t_data			item;
	struct s_node	*next;
}	t_node;

typedef struct s_circular_linked_list
{
	size_t	size;
	t_node	*tail;
}	t_circular_linked_list;

// utils.c
void					init(t_circular_linked_list *list);
void					destroy(t_circular_linked_list *list);
bool					is_empty(t_circular_linked_list *list);
size_t					size(t_circular_linked_list *list);

// push.c
void					push_front(t_circular_linked_list *list, t_data item);
void					push_back(t_circular_linked_list *list, t_data item);
void					insert(t_circular_linked_list *list, int pos, \
															t_data item);

// pop.c
void					pop_front(t_circular_linked_list *list);
void					pop_back(t_circular_linked_list *list);
void					erase(t_circular_linked_list *list, int pos);

// getter.c
t_data					front(t_circular_linked_list *list);
t_data					back(t_circular_linked_list *list);
t_data					get_item(t_circular_linked_list *list, int pos);

// operation.c
void					print(t_circular_linked_list *list);
void					reverse(t_circular_linked_list *list);
t_circular_linked_list	*concatenate(t_circular_linked_list *list1, \
										t_circular_linked_list *list2);

#endif // CIRCULAR_LINKED_LIST_H
