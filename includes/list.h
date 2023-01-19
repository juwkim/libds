/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 00:16:22 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/07 00:16:22 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include <stdlib.h>
# include <stdbool.h>

# include "libft_headers/ft_printf.h"

# define LIST_SIZE 100000

typedef char *	t_list_data;

typedef struct s_list
{
	size_t		size;
	t_list_data	items[LIST_SIZE];
}	t_list;

// usils.c
void		list_init(t_list *list);
bool		list_is_empty(t_list *list);
bool		list_is_full(t_list *list);
size_t		list_size(t_list *list);

// push.c
void		list_push_front(t_list *list, t_list_data item);
void		list_push_back(t_list *list, t_list_data item);
void		list_insert(t_list *list, int pos, t_list_data item);

// pop.c
void		list_pop_front(t_list *list);
void		list_pop_back(t_list *list);
void		list_erase(t_list *list, int pos);

// getter.c
t_list_data	list_front(t_list *list);
t_list_data	list_back(t_list *list);
t_list_data	list_get_item(t_list *list, int pos);

// operation.c
void		list_print(t_list *list);
void		list_reverse(t_list *list);
t_list		*list_concatenate(t_list *list1, t_list *list2);

#endif // LIST_H
