//#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <malloc.h>

using namespace std;

struct Data {
	char c;
	int k;
};
typedef struct Data T;
typedef int hashTableIndex;
#define comEQ(a,b) ((a)==(b))

typedef struct Node {
	T data;
	struct Node* next;
}NODE, *pNODE;

pNODE p;
int kolchar(char* s);
Node** hashTable;
int hashTableSize;
hashTableIndex myhash(T data);
pNODE insertNode(T data);
void deleteNode(T data);
pNODE findNode(T data);

int main() {
	int i, k, maxnum;
	T* a;
	char s[255], * ps = s;

	printf("Input the number of elements (maxnum): ");
	cin >> maxnum;

	printf("Input size Hash-Table HashTableSize: ");
	cin >> hashTableSize;

	a = (T*)malloc(maxnum * sizeof(T));

	for (i = 0; i < maxnum; i++) {
		a[i].c = 0;
		a[i].k = 0;
	}
	hashTable = (Node**)malloc(sizeof(pNODE) * hashTableSize);

	cout << "Input string: \n";
	cin >> s;

	for (i = 0; s[i]; i++) {
		k = kolchar(ps);
		a[i].c = s[i];
		a[i].k = k;
		printf("%d-%c  %s  (%d=%c)\n", k, ps[0], ps, a[i].k, a[i].c);
		ps++;
	}

	for (i = 0; i < hashTableSize; i++)
		hashTable[i] = NULL;

	ofstream out("c:\\List_195.txt");

	for (i = 0; i < maxnum; i++) {
		if (a[i].c > 0) out << a[i].c << " - " << a[i].k << "\n";
	}
	out.close();
	for (i = 0; i < maxnum; i++) if (a[i].c > 0) insertNode(a[i]);

	for (i = maxnum - 1; i >= 0; i--) {
		p = findNode(a[i]);
		if (p) printf("% d--> % d\n", a[i].c, p->data.c);
		else printf("%d not find", a[i].c);
	}

	out.open("c:\\HashTable_195.txt");
	for (i = 0; i < hashTableSize; i++) {
		out << i << " : ";
		pNODE Temp = hashTable[i];
		while (Temp) {
			out << "(" << Temp->data.c << " " << Temp->data.k << ") ->";
			Temp = Temp->next;
		}
		out << endl;
	}
	out.close();

	//очистка хеш-таблицы
	for (i = maxnum - 1; i >= 0; i--) {
		deleteNode(a[i]);
	}
	system("pause");
	return 0;
}

//хеш-функция размещения вершины
hashTableIndex myhash(T dat) {
	int i = dat.c;
	return(i % hashTableSize);
}

//функция поиска местоположения и вставки вершины в таблицу
pNODE insertNode(T newdata) {
	pNODE p, p0;
	hashTableIndex bucket;
	//вставка вершины в начало списка
	bucket = myhash(newdata);
	if (!(p = (pNODE)malloc(sizeof(Node)))) {
		fprintf(stderr, "Net pamyati (insertNode)\n");
		exit(1);
	}
	p0 = hashTable[bucket];
	hashTable[bucket] = p;
	p->next = p0;
	p->data = newdata;
	return p;
}

//функция удаления вершины из таблицы
void deleteNode(T dat) {
	pNODE p0, p;
	hashTableIndex bucket;
	p0 = NULL;
	bucket = myhash(dat);
	p = hashTable[bucket];
	while (p && !comEQ(p->data.c, dat.c)) {
		p0 = p;
		p = p->next;
	}
	if (!p) return;
	if (p0) p0->next = p->next;
	else hashTable[bucket] = p->next;
	free(p);
}

//функция поиска вершина со значением data
pNODE findNode(T data) {
	NODE *p;
	p = hashTable[myhash(data)];
	while (p && !comEQ(p->data.c, data.c))
		p = p->next;
	return p;
}

//возвращает кол-во вхождений в строку символов s[0]
//из строки s удаляет все символы, совпадающие с s[0], кроме s[0]
int kolchar(char *s) {
	int k = 1, i, j;
	for (i = j = 1; s[i]; i++)
		if (s[i] != s[0]) {
			s[j] = s[i];
			j++;}
		else k++;
	s[j] = 0;
	return k;
		}

