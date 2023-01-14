/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 00:16:43 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/07 00:16:43 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DQUEUE_H
# define DQUEUE_H

# include <stddef.h>
# include <stdbool.h>

# define QUEUE_SIZE 100

typedef int	t_data;

typedef struct s_dqueue
{
	int		head;
	int		tail;
	size_t	size;
	t_data	items[QUEUE_SIZE];
}	t_dqueue;

// utils.c
void	init(t_dqueue *dq);
bool	is_empty(t_dqueue *dq);
bool	is_full(t_dqueue *dq);
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

#endif
