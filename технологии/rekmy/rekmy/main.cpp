
#include <iostream>
#include <stdio.h>
#include <conio.h>

using namespace std;

void Digits1(float summa);

int main(){
    float sumka=0.;
	Digits1(sumka);
}

void Digits1(float summa) {
	float x;
	cin>>x;
	if(x<0.) {
        cout<<summa;
	}
	else{
        summa+=x;
        return Digits1(summa);
	}
}
