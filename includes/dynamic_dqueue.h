/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dynamic_queue.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 00:16:01 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/07 00:16:01 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DYNAMIC_DQUEUE_H
# define DYNAMIC_DQUEUE_H

# include <stdlib.h>
# include <stdbool.h>

typedef int	t_data;

typedef struct s_node
{
	t_data			item;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_dqueue
{
	size_t	size;
	t_node	*head;
	t_node	*tail;
}	t_dqueue;

// utils.c
void	dq_init(t_dqueue *dq);
void	destroy(t_dqueue *dq);
bool	is_empty(t_dqueue *dq);
size_t	size(t_dqueue *dq);

// push.c
void	push_front(t_dqueue *dq, t_data item);
void	push_back(t_dqueue *dq, t_data item);

// pop.c
void	pop_front(t_dqueue *dq);
void	pop_back(t_dqueue *dq);

// getter.c
t_data	front(t_dqueue *dq);
t_data	back(t_dqueue *dq);

#endif // DYNAMIC_DQUEUE_H
