/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 00:19:14 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/07 00:19:14 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define SWAP(x,y,t)	((t)=(x),(x)=(y),(y)=(t))
#define MAX_SIZE	1024

int list[] = { 5, 3, 8, 4, 9, 1, 6, 2, 7 };
int size = sizeof(list) / sizeof(list[0]);

void printArray(int arr[], int n, char* str)
{
	int i;
	printf("%s = ", str);
	for (i = 0; i < n; i++) printf("%3d", arr[i]);
	printf("\n");
}

void printStep(int arr[], int n, int val)
{
	int i;
	printf("  Step %2d = ", val);
	for (i = 0; i < n; i++) printf("%3d", arr[i]);
	printf("\n");
}

// 선택 정렬 함수 
void selection_sort(int list[], int n)
{
	int i, j, least, tmp;
	for (i = 0; i < n - 1; i++) {
		least = i;
		for (j = i + 1; j < n; j++)				// 최소값 탐색 
			if (list[j] < list[least])
				least = j;
		SWAP(list[i], list[least], tmp);
		printStep(list, n, i + 1);		// 중간 과정 출력용 문장
	}
}

void insertion_sort(int list[], int n)
{
	int i, j, key;
	for (i = 1; i < n; i++) {
		key = list[i];
		for (j = i - 1; j >= 0 && list[j] > key; j--) {
			list[j+1] = list[j];
			// 레코드의 오른쪽 이동
		}
		list[j + 1] = key;
		// 발견한 위치에 key를 삽입
		printStep(list, n, i);			// 중간 과정 출력용 문장
	}
}

// 개선된 버블 정렬 함수
void bubble_sort(int list[], int n)
{
	int i, j, flag = 1, tmp;
	for (i = n - 1; i > 0; i--) {
		flag = 0;
		for (j = 0; j < i; j++)
			if (list[j] > list[j+1]) {
				SWAP(list[j], list[j+1], tmp);
				flag = 1;			// 교환 발생
			}
		if (flag == 0)					// 교환이 없으면 종료
			break;
		printStep(list, n, n - i);			// 중간 과정 출력용 문장
	}
}

int ascend(int x, int y) { return y - x; }	// 오름차순 비교함수
int descend(int x, int y) { return x - y; }	// 내림차순 비교함수

// 함수 포인터를 매개변수로 받는 삽입정렬 함수
void insertion_sort_fn(int list[], int n, int(*f)(int, int))
{
	int i, j, key;
	for (i = 1; i < n; i++) {
		key = list[i];
		for (j = i - 1; j >= 0 && f(list[j], key) < 0; j--)
			list[j + 1] = list[j];		// 레코드의 오른쪽 이동
		list[j + 1] = key;
		printStep(list, n, i);			// 중간 과정 출력용 문장
	}
}



// gap 만큼 떨어진 요소들을 삽입 정렬. 정렬의 범위는 first에서 last 
static void sortGapInsertion(int list[], int first, int last, int gap)
{
	int i, j, key;
	for (i = first + gap; i <= last; i = i + gap) {
		key = list[i];
		for (j = i - gap; j >= first && key < list[j]; j -= gap)
			list[j + gap] = list[j];
			//레코드의 gap만큼 오른쪽 이동
		list[j + gap] = key;
//발견한 위치에 key를 삽입
	}
}
// 셸 정렬 알고리즘을 이용해 int 배열을 오름차순으로 정렬하는 함수 
void shell_sort(int list[], int n)
{
	int i, gap, count = 0;
	for (gap = n / 2; gap > 0; gap = gap / 2) {
		for (i = 0; i < gap; i++) 
			sortGapInsertion(list, i, n - 1, gap);
		printStep(list, n, ++count);		// 중간 과정 출력용 문장 
	}
}

int mi = 1;
static void merge(int list[], int left, int mid, int right)
{
	int i, j, k = left, l;				// k는 정렬될 리스트에 대한 인덱스
	static int sorted[MAX_SIZE];		// 병합된 리스트 저장을 위한 임시배열

	// 분할 정렬된 list의 병합
	for (i = left, j = mid + 1; i <= mid && j <= right; )
	{
		if (list[i] <= list[j])
			sorted[k++] = list[i++];
		else
			sorted[k++] = list[j++];
	}

	// 한쪽에 남아 있는 레코드의 일괄 복사
	if (i > mid)
	{
		for (l = j; l <= right; l++)
			sorted[k++] = list[l];
	}
	else
	{
		for (l = i; l <= mid; l++)
			sorted[k++] = list[l];
	}

	// 배열 sorted[]의 리스트를 배열 list[]로 다시 복사
	for (l = left; l <= right; l++) {
		list[l] = sorted[l];
	}

	printStep(list, size, mi++);			// 중간 과정 출력용 문장
}

// 병합 정렬 알고리즘을 이용해 int 배열을 오름차순으로 정렬하는 함수
void merge_sort(int list[], int left, int right) {

	if (left < right) {
		int mid = (left + right) / 2;		// 리스트의 균등 분할
		merge_sort(list, left, mid);		// 부분 리스트 정렬
		merge_sort(list, mid + 1, right);	// 부분 리스트 정렬
		merge(list, left, mid, right);		// 병합
	}
}

int qi = 1;
int partition(int list[], int left, int right)
{
	int tmp;
	int low = left + 1;
	int high = right;
	int pivot = list[left]; 		// 피벗 설정 
	while (low < high) {			// low와 high가 역전되지 않는 한 반복 

		while (low <= high && list[low] < pivot)
			low++;
		while (high >= low && list[high] > pivot)
			high--;

		if (low < high)				// 선택된 두 레코드 교환 
			SWAP(list[low], list[high], tmp);
	}
	SWAP(list[left], list[high], tmp);	// high와 피벗 항목 교환
	printStep(list, size, qi++);
	return high;
}

// 퀵 정렬 알고리즘을 이용해 배열의 left ~ right 항목들을 오름차순으로 정렬하는 함수
void quick_sort(int list[], int left, int right)
{
	int q;
	if (left < right) { // 정렬 범위가 2개 이상인 경우
		q = partition(list, left, right);	// 좌우로 분할 
		quick_sort(list, left, q - 1);		// 왼쪽 부분리스트를 퀵 정렬
		quick_sort(list, q + 1, right);		// 오른쪽 부분리스트를 퀵 정렬
	}
}

int compare(const void* e1, const void* e2)
{
	int* p1 = (int*)e1;
	int* p2 = (int*)e2;
	return (*p1 - *p2); // 오름차순 정렬
	//return -(*p1 - *p2); // 내림차순 정렬

}

void main()
{
	int sort_method = 0;
	char end[5] = "n";

	printArray(list, size, "Original ");	// 정렬 전 배열 출력 
	do {

		list[0] = 5, list[1] = 3, list[2] = 8, list[3] = 4, list[4] = 9, list[5] = 1, list[6] = 6, list[7] = 2, list[8] = 7;

		printf("\n\n");
		printArray(list, size, "Original ");	// 정렬 전 배열 출력 
		printf("(1번: 선택정렬, 2번: 삽입정렬, 3번: 버블정렬, 4번: 내림차순 삽입정렬, 5번: 셀 정렬, 6번: 합병 정렬, 7번: 퀵 정렬, (1-7)이외의 숫자 번호: 종료)\n 정렬 방법을 선택하세요: ");
		if (scanf("%d", &sort_method) == 0)
			return;
		switch (sort_method) {
		case 1:
			selection_sort(list, size);		// 선택 정렬 실행 
			printArray(list, size, "Selection");	// 정렬 후 배열 출력 
			break;
		case 2:
			insertion_sort(list, size); 		// 삽입 정렬 실행 
			printArray(list, size, "Insertion");		// 정렬 후 배열 출력 
			break;
		case 3:
			bubble_sort(list, size); 		// 버블 정렬 실행 
			printArray(list, size, "Bubble   ");	// 정렬 후 배열 출력 
			break;
		case 4:
			insertion_sort_fn(list, size, descend); 	// 내림차순 삽입정렬 알고리즘
			printArray(list, size, "Insert-De");	// 정렬 후 배열 출력 
			break;
		case 5:
			shell_sort(list, size); 			// 셀정렬 알고리즘
			printArray(list, size, "ShellSort");		// 정렬 후 배열 출력 
			break;
		case 6:
			merge_sort(list, 0, size - 1); 		// 합병정렬 알고리즘
			printArray(list, size, "MergeSort");	// 정렬 후 배열 출력 
			break;
		case 7:
			quick_sort(list, 0, size - 1); 		// 퀵정렬 알고리즘
			//qsort((void *)list, size, sizeof(int), compare);  // 퀵정렬 라이브러리 함수 호출
			printArray(list, size, "QuickSort");	// 정렬 후 배열 출력 
			break;
		default:
			printf("정렬을 끝내시겠습니까?(y/n) :");
			if (scanf("%s", end) == 0)
				return;
			break;
		}
	} while (strcmp(end, "n") == 0);
}