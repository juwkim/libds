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

# include <stdio.h>
# include <stdlib.h>
# include <assert.h>

# include "deque.h"

typedef struct s_graph_node
{
	int					id;
	struct s_graph_node	*next;
}	t_graph_node;

typedef struct s_graph
{
	size_t			size;
	t_graph_node	**heads;
}	t_graph;

// graph.c
void			graph_init(t_graph *graph, size_t size);
void			graph_destroy(t_graph *graph);
t_graph_node	*graph_create_node(int id);
void			graph_add_edge(t_graph *graph, int src, int dst);
void			graph_print(t_graph *graph);

// search.c
void			bfs(t_graph *graph);
void			dfs(t_graph *graph);

#endif // GRAPH_H
