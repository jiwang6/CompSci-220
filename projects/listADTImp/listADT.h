#pragma once
#ifndef LISTADT_H
#define LISTADT_H
#define MAX 250

typedef struct {
	int items[MAX];
	int size;
}list;


list createList();

int append(list *L, int X);

int Prepend(list *L, int X);

int insertAfter(list *L, int W, int X);

int removeItem(list *L, int X);

int linearSearch(list L, int X);

int binarySearch(list L, int X);

void print(list L);

void printReverse(list L);

void sort(list *L);

int isEmpty(list L);

int getLength(list L);




#endif // !listADT_H
