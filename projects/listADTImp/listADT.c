#include "listADT.h"
#include <stdio.h>

list createList() {
	list L;
	L.size = 0;
	return L;
}

int append(list *L, int X) {
	if (L->size < MAX) {
		L->items[L->size] = X;
		L->size++;
		return 1;
	}
	return 0;
}

int Prepend(list *L, int X) {
	if (L->size == MAX) return 0;
	for (int i = L->size - 1; i > 0; i--)
		L->items[i] = L->items[i - 1];
	L->items[0] = X;
	return 1;
}

int insertAfter(list *L, int W, int X) { 
	if (L->size < MAX) {
		L->size++;
		for (int i = L->size - 1; i > W; i--)
			L->items[i] = L->items[i - 1];
		L->items[W] = X;
		return 1;
	}
	return 0;
}

int removeItem(list *L, int X) {
	int removed = 0;
	for (int i = 0; i < L->size; i++) {
		if (removed && (i < L->size - 1)) L->items[i] = L->items[i + 1];
		if (L->items[i] == X) removed = 1;
	}
		
	return removed;
}

int linearSearch(list L, int X) { // done
	for (int i = 0; i < L.size; i++) {
		if (L.items[i] == X) {
			return 1;
		}
	}
	return 0;
}


int binarySearch(list L, int X) {
	int min = 0;
	int max = L.size - 1;

	int mid = (max + min)/ 2;
	// printf("\n%d", mid);

	while (L.items[mid] != X) {
		if (L.items[mid] > X) {
			max = mid;
			mid = (0 + max) / 2;
		}
		if (L.items[mid] < X) {
			min = mid;
			mid = (min + max) / 2;
		}

		if (L.items[mid] == X)
			return 1;
		if (max == min + 1)
			break;
	}
	
	return 0;
}

void print(list L) {
	for (int i = 0; i < L.size; i++)
		printf("%d ", L.items[i]);
	printf("\n");
}

void printReverse(list L) {
	for (int i = L.size-1; i >=0; i--)
		printf("%d ", L.items[i]);
	printf("\n");
}

void sort(list *L) {
	int swap;
	for (int i=0; i<L->size-1; i++)
		for (int j = 0; j < L->size - i - 1; j++)
			if(L->items[j]>L->items[j+1]){
				swap = L->items[j];
				L->items[j] = L->items[j + 1];
				L->items[j + 1] = swap;
			}
}

int isEmpty(list L) {
	if (L.size == 0) return 1;
	return 0;
}

int getLength(list L) {
	return L.size;
}