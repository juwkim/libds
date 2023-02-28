/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dqueue.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 00:16:01 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/07 00:16:01 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DDEQUE_H
# define DDEQUE_H

# include <stdlib.h>
# include <stdbool.h>
# include <assert.h>

typedef void *	t_ddq_data;

typedef struct s_ddq_node
{
	t_ddq_data			item;
	struct s_ddq_node	*prev;
	struct s_ddq_node	*next;
}	t_ddq_node;

typedef struct s_ddeque
{
	size_t		size;
	t_ddq_node	*head;
	t_ddq_node	*tail;
}	t_ddeque;

// utils.c
void		ddq_init(t_ddeque *dq);
void		ddq_destroy(t_ddeque *dq);
bool		ddq_is_empty(t_ddeque *dq);
size_t		ddq_size(t_ddeque *dq);

// push.c
void		ddq_push_front(t_ddeque *dq, t_ddq_data item);
void		ddq_push_back(t_ddeque *dq, t_ddq_data item);

// pop.c
void		ddq_pop_front(t_ddeque *dq);
void		ddq_pop_back(t_ddeque *dq);

// getter.c
t_ddq_data	ddq_front(t_ddeque *dq);
t_ddq_data	ddq_back(t_ddeque *dq);

#endif // DDEQUE_H
