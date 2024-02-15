#include <iostream>
#include <stdio.h>
#include <conio.h>

using namespace std;

void Digits1();

int main() {
	Digits1();
}

void Digits1() {
	int k = 0;
	char c;
	if (c = _getche() != '.') {
		k++;
		putchar(c);
		Digits1;
	}
	cout << k;
}
