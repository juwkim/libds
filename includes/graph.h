/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 00:16:15 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/07 00:16:15 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPH_H
# define GRAPH_H

# include <stdlib.h>

# include "deque.h"
# include "libft_header/ft_printf.h"

typedef struct s_node
{
	int				id;
	struct s_node	*next;
}	t_node;

typedef struct s_graph
{
	size_t	size;
	t_node	**heads;
}	t_graph;

// graph.c
void	init(t_graph *graph, size_t size);
void	destroy(t_graph *graph);
t_node	*create_node(int id);
void	add_edge(t_graph *graph, int src, int dst);
void	print(t_graph *graph);

// search.c
void	bfs(t_graph *graph);
void	dfs(t_graph *graph);

#endif
