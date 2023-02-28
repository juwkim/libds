/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:26:55 by juwkim            #+#    #+#             */
/*   Updated: 2023/03/01 07:15:43 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"

static int	__get_total_len(t_deque *dq);

void	dq_print(t_deque *dq)
{	
	int	cur;

	printf("size [%ld]\n", dq_size(dq));
	cur = dq->head;
	while (cur != dq->tail)
	{
		printf("%s\n", (char *) dq->items[cur]);
		cur = (cur + 1) % QUEUE_SIZE;
	}
}

char	*dq_strjoin(t_deque *dq)
{
	int			cur;
	int			idx;
	int			str_len;
	const int	total_len = __get_total_len(dq);
	char *const	str = malloc(sizeof(char) * (total_len + 1));

	assert(str != NULL);
	cur = dq->head;
	idx = 0;
	while (cur != dq->tail)
	{
		str_len = strlen(dq->items[cur]);
		memcpy(str + idx, dq->items[cur], str_len);
		idx += str_len;
		cur = (cur + 1) % QUEUE_SIZE;
	}
	str[total_len] = '\0';
	dq_destroy(dq);
	return (str);
}

static int	__get_total_len(t_deque *dq)
{
	int		cur;
	int		total_len;

	cur = dq->head;
	total_len = 0;
	while (cur != dq->tail)
	{
		total_len += strlen(dq->items[cur]);
		cur = (cur + 1) % QUEUE_SIZE;
	}
	return (total_len);
}
