#include <iostream>
#include <cstdio>
#include "stdio.h"
#include "conio.h"
#include "malloc.h"

using namespace std;

typedef struct Node {
    int value;
    struct Node* next;
}NODE, * pNODE;

typedef struct List {
    int len;
    pNODE top;
}LIST, * pLIST;

pLIST createList() {
    pLIST pL = (pLIST)malloc(sizeof(LIST));
    if (pL) {
        pL->top = NULL;
        pL->len = 0;
    }
    return pL;
}

int isEmpty(pLIST pL) {
    if (pL->top && pL->len) return 0;
    else return 1;
}

pNODE getPointer(pLIST pL, int date) {
    pNODE p = pL->top;
    if (isEmpty(pL)) return NULL;
    else {
        if (date < p->value) return p;
        while (p->next && p->next->value < date) p = p->next;
        return p;
    }
}

int addNode(pLIST pL, pNODE pN, int date) {
    pNODE pNew=(pNODE)malloc(sizeof(NODE)), p=pL->top;
    if(!pNew) return 0;
    pL->len++;
    pNew->value=date;
    if(isEmpty(pL)||date<p->value){
        pNew->next=p;
        pL->top=pNew;
        return 1;
    }
    pNew->next=pN->next;
    pN->next=pNew;
    return 1;
}

int delNode(pLIST pL, pNODE pN) {
    pNODE p = pN->next;
    if (!p) {
        free(pN);
        pL->top = p;
    }
    else {
        pN->next = p->next;
        free(p);
    }
    pL->len--;
    return 1;
}

void clearList(pLIST pL) {
    while (pL->top) {
        delNode(pL, pL->top);
        printf("top=%p\n", pL->top);
    }
}

void deleteList(pLIST pL) {
    clearList(pL);
    free(pL);
}

void showList(pLIST pL) {
    pNODE p = pL->top;
    if (isEmpty(pL)) printf("List is empty\n");
    while (p) {
        printf("%p->%d->%p\n", p, p->value, p->next);
        p = p->next;
    }
}

pNODE findNode(pLIST pL, int date) {
    pNODE p = pL->top;
    if (isEmpty(pL)) return NULL;
    while (p && p->value != date) p = p->next;
    return p;
}

int main(int argc, int* argv[])
{
    pNODE p;
    pLIST list = createList();
    char exit = 0;
    int com;
    while (1) {
        puts("1-dovalenie");
        puts("2-poisk");
        puts("3-udalenie elementa spiska");
        puts("4-show");
        puts("5-clear");
        puts("0-exit");
        cin >> com;
        switch (com) {
        case 0:exit = 1; break;
        case 1:
            printf("Vvedite chislo:");
            cin >> com;
            addNode(list, getPointer(list, com), com);
            break;

        case 2:
            printf("Vvedite chislo:");
            cin >> com;
            p = findNode(list, com);
            if (p) printf("Chislo est - %d, adres: %p\n", com, p);
            else printf("Chisla net");
            break;

        case 3:
            printf("Vvedite chislo:");
            cin >> com;
            p = findNode(list, com);
            if (p) {
                getPointer(list, com);
                if ((p = list->top) && (com == list->top->value)) {
                    list->top = p->next;
                    free(p);
                }
                else delNode(list, p);
                printf("Udalenie zaversheno");
            }

        case 4:
            showList(list);
            break;

        case 5:
            clearList(list);
            showList(list);
            break;

        }
        if (exit) break;
    }
    deleteList(list);
    return 0;
}
