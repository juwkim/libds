/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dynamic_stack.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 00:16:08 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/07 00:16:08 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DYNAMIC_STACK_H
# define DYNAMIC_STACK_H

# include <stdlib.h>
# include <stdbool.h>

typedef int Data;
typedef struct _Node
{
	Data item;
	struct _Node* next;
} Node;

typedef struct
{
	Node* top;
} DStack;

// Make stack empty.
void InitStack(DStack* pstack);

// check whether stack is empty.
bool IsEmpty(DStack *pstack);

// Read the item at the top.
Data Peek(DStack* pstack);

void Push(DStack* pstack, Data item);

// Remove the item at the top.
void Pop(DStack* pstack);

#endif
