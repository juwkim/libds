/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 00:16:57 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/07 00:16:57 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORTING_H
# define SORTING_H

# include <stdio.h>
# include <stdbool.h>

# define MAX_SIZE 100

typedef int Data;

int MIN(int a, int b);
int MAX(int a, int b);
void SWAP(Data* a, Data* b);

// SelectionSort
void SelectionSort(Data* list, int n);

// BubbleSort
void BubbleSort(Data* list, int n);

// InsertionSort
void InsertionSort(Data* list, int n);

// QuickSort
int Partition(Data* list, int left, int right);
void QuickSort(Data * list, int left, int right);

// MergeSort
void Merge(Data* list, int left, int mid, int right);
void MergeSort(Data* list, int left, int right);

// IterMergeSort
void IterMergeSort(Data* list, int n);

// CountingSort
void CountingSort(Data* list, int n);

// RadixSort
void Counting(Data* list, int n, int exp);
void RadixSort(Data* list, int n);

// shell_sort
void sortGapInsertion(int list[], int first, int last, int gap);
void shell_sort(int list[], int n);

#endif
