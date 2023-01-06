/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 00:16:22 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/07 00:16:22 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include <stdlib.h>
# include <stdbool.h>

# define LIST_SIZE 100

typedef int Data;
typedef struct
{
	Data items[LIST_SIZE];
	int len;
} ArrayList;

// Make a list empty.
void InitList(ArrayList* plist);

// Check whether the list is empty.
bool IsEmpty(ArrayList* plist);

// Check whether the list is full.
bool IsFull(ArrayList* plist);

// Insert an item at the k-th position.
void InsertMiddle(ArrayList* plist, int pos, Data item);

// Remove an item at the k-th position.
void RemoveMiddle(ArrayList* plist, int pos);

// Read an item at the k-th position.
Data ReadItem(ArrayList* plist, int pos);

// Print each item in a list in sequence.
void PrintList(ArrayList* plist);

#endif
