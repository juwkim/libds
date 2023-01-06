/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 00:17:05 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/07 00:17:05 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stdio.h>
# include <stdbool.h>
# include <stdlib.h>

# define STACK_SIZE 100

typedef int Data;
typedef struct
{
	Data items[STACK_SIZE];
	int top;
} stack;

// Make stack empty.
void Initstack(stack* pstack);

// Check whether stack is full.
bool IsFull(stack* pstack);

// check whether stack is empty
bool IsEmpty(stack* pstack);

// Read the item at the top.
Data Peek(stack* pstack);

// Insert an item at the top.
void Push(stack* pstack, Data item);

// Remove the item at the top.
void Pop(stack* pstack);

void ReversePrint(char* s, int len);

# endif
