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

typedef int	t_data;

typedef struct s_node
{
	t_data			item;
	struct s_node	*next;
}	t_node;


typedef struct s_circular_list
{
	int		size;
	t_node	*tail;
}	t_circular_list;

// is_empty.c
bool	is_empty(t_circular_list *list);

// size.c
size_t	size(t_circular_list *list);

// create_node.c
t_node	*create_node(t_data item);

// push.c
void	push_front(t_circular_list *list, t_data item);
void	push_back(t_circular_list *list, t_data item);
void	insert(t_circular_list *list, int pos, t_data item);

// pop.c
void	pop_front(t_circular_list *list);
void	pop_back(t_circular_list *list);
void	erase(t_circular_list *list, int pos);

// get_item.c
t_data	front(t_circular_list *list);
t_data	back(t_circular_list *list);
t_data	get_item(t_circular_list *list, int pos);

#endif // CIRCULAR_LINKED_LIST_H
