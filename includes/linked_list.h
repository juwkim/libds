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

#ifndef LINKED_LIST_H
# define LINKED_LIST_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

# define DEF_COLOR	"\033[0;39m"
# define GRAY		"\033[1;90m"
# define RED		"\033[1;91m"
# define GREEN		"\033[1;92m"
# define YELLOW		"\033[1;93m"
# define BLUE		"\033[1;94m"
# define MAGENTA	"\033[1;95m"
# define CYAN		"\033[1;96m"
# define WHITE		"\033[1;97m"

typedef char *	t_data;

typedef struct s_node
{
	t_data			item;
	struct s_node	*next;
}	t_node;

typedef struct s_linked_list
{
	size_t	size;
	t_node	*head;
}	t_linked_list;

// usils.c
void			list_init(t_linked_list *list);
void			list_destroy(t_linked_list *list);
bool			list_is_empty(t_linked_list *list);
size_t			list_size(t_linked_list *list);

// push.c
void			list_push_front(t_linked_list *list, t_data item);
void			list_push_back(t_linked_list *list, t_data item);
void			list_insert(t_linked_list *list, int pos, t_data item);

// pop.c
void			list_pop_front(t_linked_list *list);
void			list_pop_back(t_linked_list *list);
void			list_erase(t_linked_list *list, int pos);

// getter.c
t_data			list_front(t_linked_list *list);
t_data			list_back(t_linked_list *list);
t_data			list_get_item(t_linked_list *list, int pos);

// operation.c
void			list_print(t_linked_list *list);
void			list_reverse(t_linked_list *list);
t_linked_list	*list_concatenate(t_linked_list *list1, t_linked_list *list2);

#endif // LINKED_LIST_H
