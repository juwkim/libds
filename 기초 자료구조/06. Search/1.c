/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 00:19:19 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/07 00:19:19 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ELEMENTS 10000000L
int list[MAX_ELEMENTS];
int count;	// 탐색 수행횟수

#define INDEX_SIZE 256

typedef struct {
	int key;
	int index;
} itable;
itable index_list[INDEX_SIZE];


//
// 순차 탐색
//
int seqsearch(int list[], int n, int searchnum)
{
	int i;

	count = 0;
	for (i = 0; i < n; i++) {
		count++;
		if (list[i] == searchnum)
			return i;
	}
	return -1;		// 발견되지 않음 
}

//
// 개선된 순차 탐색
//
int seqsearch2(int list[], int n, int searchnum)
{
	count = 0;
	while (count < n && list[count] != searchnum)
		count++;

	if (count == n)	return -1;		// 발견되지 않음
	else return count; 		//탐색 성공
}
//
// 순차 탐색
//
int seqsearch3(int low, int high, int searchnum)
{
	int i;

	count = 0;
	for (i = low; i < high; i++) {
		count++;
		if (list[i] == searchnum)
			return i;
	}
	return -1;		// 발견되지 않음 
}


//
// 이진 탐색(반복)
//
int binsearch(int list[], int n, int searchnum)
{
	int left = 0;
	int right = n - 1;
	int middle;

	count = 0;
	while (left <= right) {		// 아직 숫자들이 남아 있으면
		count++;
		middle = (left + right) / 2;
		if (list[middle] == searchnum)
			return middle;
		else if (list[middle] < searchnum)
			left = middle + 1;
		else
			right = middle - 1;
	}
	return -1;		// 발견되지 않음 
}

//
// 이진 탐색(순환 호출 버전)
//
int binsearch2(int list[], int low, int high, int searchnum)
{
	if (low > high)
		return -1; // 발견되지 않음

	int middle = (low + high) / 2;
	count++;
	if (list[middle] == searchnum)
		return middle;
	else if (list[middle] < searchnum)
		return binsearch2(list, middle + 1, high, searchnum);
	else
		return binsearch2(list, low, middle - 1, searchnum);
}

//인덱스 테이블 생성
void makeIndexTable(int list[], int size) {
	int interval = (size + INDEX_SIZE - 1) / INDEX_SIZE;

	for (int i = 0; i < INDEX_SIZE; i++) {
		index_list[i].index = i * interval;
		index_list[i].key = list[i * interval];
	}
}

/* INDEX_SIZE는 인덱스 테이블의 크기,n은 전체 데이터의 수 */
int index_search(int list[], int key, int n)
{
	int i, low, high;
	// 키 값이 리스트 범위 내의 값이 아니면 탐색 종료 
	if (key < list[0])
		return -1;

	makeIndexTable(list, n);  //인덱스 테이블 생성

	// 인덱스 테이블을 조사하여 해당키의 구간 결정
	for (i = 1; i <= INDEX_SIZE; i++)
	{
		if (key <= index_list[i].key) {
			low = index_list[i - 1].index;
			high = index_list[i].index;
			break;
		}
	}

	if (i == INDEX_SIZE) {  // 인덱스 테이블의 끝이면 
		low = index_list[INDEX_SIZE - 1].index;
		high = n;
	}
	// 예상되는 범위만 순차 탐색 
	return seqsearch3(low, high, key);

}

//보간탐색
int search_interpolation(int list[], int n, int key)
{
	int low, high, j;
	count = 0;
	low = 0;
	high = n - 1;

	while ((list[low] <= key) && (key <= list[high])) {		//key가 list의 범위 안에 있으면
		count++;
		j = low + (high - low) / (list[high] - list[low]) * (key - list[low]);
		if (list[j] == key)
			return j;
		else if (list[j] > key)
			high = j - 1;
		else
			low = j + 1;
	}
	if (list[low] == key) return low;  	//탐색 성공
	else return -1;  			// 발견되지 않음 
}

int main()
{
	int i;
	int search_number;  // 탐색할 숫자
	int return_value;
	clock_t start, finish;
	clock_t  duration;

	for (i = 0; i < MAX_ELEMENTS; i++)
		list[i] = i;

	printf("탐색할 숫자를 입력하세요: ");
	if (scanf("%d", &search_number) == 0)
		return 0;

	//순차탐색으로 검색 
	start = clock();
	return_value = seqsearch(list, MAX_ELEMENTS, search_number);
	finish = clock();

	duration = finish - start;
	printf("순차 탐색시간 = %d milliseconds\n", duration);
	printf("수행횟수 = %d\n ", count);

	if (return_value == -1) {
		printf("숫자가 발견되지 않았습니다.\n");
	}
	else {
		printf("숫자가 위치 %d에서 발견되었습니다.\n", return_value);
	}

	//개선된 순차탐색으로 검색 
	start = clock();
	return_value = seqsearch2(list, MAX_ELEMENTS, search_number);
	finish = clock();

	duration = finish - start;
	printf("개선된 순차 탐색시간 = %d milliseconds\n", duration);
	printf("수행횟수 = %d\n ", count);

	if (return_value == -1) {
		printf("숫자가 발견되지 않았습니다.\n");
	}
	else {
		printf("숫자가 위치 %d에서 발견되었습니다.\n", return_value);
	}


	//이진 탐색(반복)으로 검색
	start = clock();
	return_value = binsearch(list, MAX_ELEMENTS, search_number);
	finish = clock();

	duration = finish - start;
	printf("이진 탐색(반복 버전) 시간 = %d milliseconds\n", duration);
	printf("수행횟수=%d\n ", count);

	if (return_value == -1) {
		printf("숫자가 발견되지 않았습니다.\n");
	}
	else {
		printf("숫자가 위치 %d에서 발견되었습니다.\n", return_value);
	}


	//이진 탐색(순환)으로 검색
	count = 0;
	start = clock();
	return_value = binsearch2(list, 0, MAX_ELEMENTS - 1, search_number);
	finish = clock();

	duration = finish - start;
	printf("이진 탐색(순환 버전) 시간 = %d milliseconds\n", duration);
	printf("수행횟수=%d\n ", count);

	if (return_value == -1) {
		printf("숫자가 발견되지 않았습니다.\n");
	}
	else {
		printf("숫자가 위치 %d에서 발견되었습니다.\n", return_value);
	}


	//색인 순차 탐색으로 검색
	start = clock();
	return_value = index_search(list, search_number, MAX_ELEMENTS);
	finish = clock();

	duration = finish - start;
	printf("색인 순차 탐색시간 = %d milliseconds\n", duration);
	printf("수행횟수=%d\n ", count);

	if (return_value == -1) {
		printf("숫자가 발견되지 않았습니다.\n");
	}
	else {
		printf("숫자가 위치 %d에서 발견되었습니다.\n", return_value);
	}


	//보간탐색으로 검색 
	start = clock();
	return_value = search_interpolation(list, MAX_ELEMENTS, search_number);
	finish = clock();

	duration = finish - start;
	printf("보간 탐색시간 = %d milliseconds\n", duration);
	printf("수행횟수 = %d\n ", count);
	if (return_value == -1) {
		printf("숫자가 발견되지 않았습니다.\n");
	}
	else {
		printf("숫자가 위치 %d에서 발견되었습니다.\n", return_value);
	}

	return 0;
}