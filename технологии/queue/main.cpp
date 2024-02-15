#include <iostream>
#include <cstdio>
#include "stdio.h"
#include "conio.h"
#include "malloc.h"


using namespace std;

typedef struct Node {
	char value;
	struct Node *next;
} NODE, *pNODE;


typedef struct queue {
	pNODE beg, end;
    int len;
} QUEUE, *pQUEUE;

pQUEUE createQUEUE() {
	pQUEUE pQ = (pQUEUE)malloc(sizeof(QUEUE));
    if (pQ) {
		pQ->beg = NULL; pQ->end = NULL; pQ->len = 0;
	}
	return pQ;
}
int isEmptyQueue(pQUEUE pQ) {
	if (pQ->beg && pQ->end && pQ->len) return 0;
	return 1;
}
void put(pQUEUE pQ, char val) {
	pNODE p = (pNODE)malloc(sizeof(NODE));
    p->next = NULL;
	p->value = val;
	if (pQ->end) pQ->end->next = p;
	else pQ->beg = p;
	pQ->end = p;
	pQ->len++;
}
char take(pQUEUE pQ) {
	pNODE p = pQ->beg; char c = p->value;
    pQ->beg = p->next;
	free(p);
    pQ->len--;
    return c;
}
void showQ(pQUEUE pQ) {
	pNODE p = pQ->beg;
	if (isEmptyQueue(pQ)) cout << "Queue is empty" << "\n";
    while (p) {
		cout << p->value;
		p = p->next;
	}
	cout << "\n";
}

void ClearQueue(pQUEUE pQ) {
	while (!isEmptyQueue(pQ)) take(pQ);
    if (isEmptyQueue(pQ)) cout << "Queue is empty" << "\n";
    free(pQ);
}

int main() {
	pQUEUE pQ = createQUEUE();
	char c;
	for (c = '0'; c <= '9'; c++) {
		put(pQ, c);
		showQ(pQ);
	}
	while (!isEmptyQueue(pQ)) {
		take(pQ);
		showQ(pQ);
	}
	showQ(pQ);
    ClearQueue(pQ);
	return 0;
}

