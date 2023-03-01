/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_linked_list.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 00:16:51 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/07 00:16:51 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>
# include <assert.h>

# define DEF_COLOR	"\033[0;39m"
# define GRAY		"\033[1;90m"
# define RED		"\033[1;91m"
# define GREEN		"\033[1;92m"
# define YELLOW		"\033[1;93m"
# define BLUE		"\033[1;94m"
# define MAGENTA	"\033[1;95m"
# define CYAN		"\033[1;96m"
# define WHITE		"\033[1;97m"

typedef void *	t_list_data;

typedef struct s_list_node
{
	t_list_data			item;
	struct s_list_node	*next;
}	t_list_node;

typedef struct s_list
{
	size_t		size;
	t_list_node	*head;
}	t_list;

// usils.c
void		list_init(t_list *list);
void		list_destroy(t_list *list, void (*del)(void *));
bool		list_is_empty(const t_list *list);
size_t		list_size(const t_list *list);

// push.c
void		list_push_front(t_list *list, t_list_data item);
void		list_push_back(t_list *list, t_list_data item);
void		list_insert(t_list *list, int pos, t_list_data item);
t_list_node	*list_insert_list(t_list *list1, t_list_node *prev, t_list *list2);
t_list_node	*list_create_node(t_list_data item);

// pop.c
void		list_pop_front(t_list *list, void (*del)(void *));
void		list_pop_back(t_list *list, void (*del)(void *));
void		list_erase(t_list *list, int pos, void (*del)(void *));
void		list_pop_next(t_list_node *prev, void (*del)(void *));

// getter.c
t_list_data	list_front(t_list *list);
t_list_data	list_back(t_list *list);
t_list_data	list_get_item(t_list *list, int pos);

// operation.c
void		list_print(t_list *list);
void		list_reverse(t_list *list);
t_list		*list_concatenate(t_list *list1, t_list *list2);
char		*list_strjoin(t_list *list);

#endif // LIST_H
