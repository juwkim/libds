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

#ifndef CLIST_H
# define CLIST_H

# include <stdio.h>
# include <assert.h>
# include <stdlib.h>
# include <stdbool.h>

typedef void *	t_clist_data;

typedef struct s_clist_node
{
	t_clist_data		item;
	struct s_clist_node	*next;
}	t_clist_node;

typedef struct s_clist
{
	size_t			size;
	t_clist_node	*tail;
}	t_clist;

// utils.c
void			clist_init(t_clist *list);
void			clist_destroy(t_clist *list);
bool			clist_is_empty(t_clist *list);
size_t			clist_size(t_clist *list);

// push.c
void			clist_push_front(t_clist *list, t_clist_data item);
void			clist_push_back(t_clist *list, t_clist_data item);
void			clist_insert(t_clist *list, int pos, t_clist_data item);

// pop.c
void			clist_pop_front(t_clist *list);
void			clist_pop_back(t_clist *list);
void			clist_erase(t_clist *list, int pos);

// getter.c
t_clist_data	clist_front(t_clist *list);
t_clist_data	clist_back(t_clist *list);
t_clist_data	clist_get_item(t_clist *list, int pos);

// operation.c
void			clist_print(t_clist *list);
void			clist_reverse(t_clist *list);
t_clist			*clist_concatenate(t_clist *list1, t_clist *list2);

#endif // CLIST_H
