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

# define LIST_SIZE 100

typedef int	t_data;

typedef struct s_list
{
	size_t	size;
	t_data	items[LIST_SIZE];
}	t_list;

// usils.c
void	init(t_list *list);
bool	is_empty(t_list *list);
bool	is_full(t_list *list);
size_t	size(t_list *list);

// push.c
void	push_front(t_list *list, t_data item);
void	push_back(t_list *list, t_data item);
void	insert(t_list *list, int pos, t_data item);

// pop.c
void	pop_front(t_list *list);
void	pop_back(t_list *list);
void	erase(t_list *list, int pos);

// getter.c
t_data	front(t_list *list);
t_data	back(t_list *list);
t_data	get_item(t_list *list, int pos);

// operation.c
void	print(t_list *list);
void	reverse(t_list *list);
t_list	*concatenate(t_list *list1, t_list *list2);

#endif // LIST_H
