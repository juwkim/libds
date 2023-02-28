/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 00:15:55 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/07 00:15:55 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DLIST_H
# define DLIST_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <assert.h>

typedef void *	t_dlist_data;

typedef struct s_dlist_node
{
	t_dlist_data		item;
	struct s_dlist_node	*prev;
	struct s_dlist_node	*next;
}	t_dlist_node;

typedef struct s_dlist
{
	size_t			size;
	t_dlist_node	*head;
	t_dlist_node	*tail;
}	t_dlist;

// utils.c
void			dlist_init(t_dlist *list);
void			dlist_destroy(t_dlist *list);
bool			dlist_is_empty(t_dlist *list);
size_t			dlist_size(t_dlist *list);
t_dlist_node	*dlist_get_iterator(t_dlist *list, int pos);

// push.c
void			dlist_push_front(t_dlist *list, t_dlist_data item);
void			dlist_push_back(t_dlist *list, t_dlist_data item);
void			dlist_insert(t_dlist *list, int pos, t_dlist_data item);

// pop.c
void			dlist_pop_front(t_dlist *list);
void			dlist_pop_back(t_dlist *list);
void			dlist_erase(t_dlist *list, int pos);

// getter.c
t_dlist_data	dlist_front(t_dlist *list);
t_dlist_data	dlist_back(t_dlist *list);
t_dlist_data	dlist_get_item(t_dlist *list, int pos);

// operation.c
void			dlist_print(t_dlist *list);
void			dlist_reverse(t_dlist *list);
t_dlist			*dlist_concatenate(t_dlist *list1, t_dlist *list2);

#endif // DLIST_H
