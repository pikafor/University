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

typedef struct Stack {
	pNODE top;
	int len;
} STACK, *pSTACK;

pSTACK createStack() {
	pSTACK pS = (pSTACK)malloc(sizeof(STACK));
    if (pS) {
		pS->top = NULL;
		pS->len = 0;
    }
	return pS;
}

int isEmpty(pSTACK pS) {
	if (pS->top && pS->len) return 0;
	return 1; }

int push(pSTACK pS, char c) {
	pNODE p = (pNODE)malloc(sizeof(NODE));
    if (p) {
		p->value = c; p->next = pS->top; pS->top = p; pS->len++;
		return 1;
	}
	return 0;
}
char pop(pSTACK pS) {
    pNODE p = pS->top; char c = p->value; pS->top = p->next; free(p);
    pS->len--;
    return c;
}

void show(pSTACK pS) { pNODE p = pS->top; if (isEmpty(pS))
    cout << "Stack is empty" << "\n"; while (p) {
	cout << p->value;
	p = p->next; }
    cout << "\n";
}
void clearStack(pSTACK pS) { pNODE p = pS->top;
    while (p) pop(pS);
    free(pS);
}

int main() {
	pSTACK pS = createStack();
	char c;
    for (c = 'a';c <= 'z';c++) {
		push(pS, c);
		show(pS); }
	while (!isEmpty(pS)) {
        show(pS);
        pop(pS);
    }
	show(pS);
    clearStack(pS);
}
