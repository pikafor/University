
#include <iostream>
#include <ctime>
const int N = 20;

using namespace std;

void vv(int* A);
void print(int* A);
void copy(int* A, int* B);
void select(int A[], int N);
void bubble(int B[], int N);
void bubblenew(int B[], int N);
void insert(int B[], int N);
void shella(int B[], int N);
void shaker(int B[], int N);

int main() {
	int A[N], B[N];
	vv(A);
	print(A);
	copy(A, B);
	bubble(B, N);
	print(B);
	return 0;
}

void vv(int A[]) {
	int i;
	srand(time(NULL));
	for (i = 0; i < N; i++) {
		A[i] = rand() % 51;
	}
}

void print(int A[]) {
	int i;
	for (i = 0; i < N; i++) cout << A[i] << " ";
	cout << "\n";
}

void copy(int A[], int B[]) {
	for (int i = 0; i < N; i++) {
		B[i] = A[i];
	}
}

void select(int B[], int N) {
	cout << "Metod viborki: " << endl;
	int i, j, ind, temp;
	for (i = 0; i < N - 1; i++) {
		ind = i;
		for (j = i + 1; j < N; j++)
			if (B[j] < B[ind]) ind = j;
		temp = B[ind];
		B[ind] = B[i];
		B[i] = temp;
	}
}

void bubble(int B[], int N) {
	cout << "BubbleNew: \n";
	int i, j, temp, c = 0, p = 0;;
	for (i = 0; i < N - 1; i++) {
		for (j = N - 1; j > i; j--) {
			c++;
			if (B[j - 1] > B[j]) {
				p++;
				temp = B[j];
				B[j] = B[j - 1];
				B[j - 1] = temp;
			}
		}
		cout << "Compare: "<<c<<endl;
		cout << "Perestavili: "<<p<<endl;
	}

}

void bubblenew(int B[], int N) {
	cout << "BubbleNew: \n";
	int i = 0, j, m, temp, c = 0, p = 0;
	do {
		m = i;
		for (j = N - 1; j > m; j--) {
			c++;
			if (B[j - 1] > B[j]) {
				p++;
				temp = B[j];
				B[j] = B[j - 1];
				B[j - 1] = temp;
			}
		}
		cout << "Compare: " << c << endl;
		cout << "Perestavili: " << p << endl;
	} while (m - j);
}

void insert(int B[], int N){
	int i, j, temp, c = 0;
	double p = 0;
	for (i = 1; i < N; i++)
	{
		if (B[i] < B[i - 1]) {
			c++;
			temp = B[i];
			p = 1. / 3;
			for (j = i - 1; j >= 0 && B[j] > temp; j--, c++)
			{
				p = 1. / 3;
				B[j + 1] = B[j];
			}
			B[j + 1] = temp;
			p = 1. / 3;
		}
		cout << "Compare: " << c << endl;
		cout << "Perestavili: " << p << endl;
	}
}
void shella(int B[], int N){
	int i, j, temp, step = N / 2, c = 0;
	double p = 0;
	cout << "Shella: \n";
	while (step)
	{
		for (i = step; i < N; i++)
		{
			p += 1. / 3;
			temp = B[i];
			for (j = i - step; j >= 0 && B[j] > temp; j -= step, c++)
			{
				p += 1. / 3;
				B[j + step] = B[j];
			}
			B[j + step] = temp;
			p += 1. / 3;
		}
		step /= 2;
		cout << "Compare: " << c << endl;
		cout << "Perestavili: " << p << endl;
	}
}

void shaker(int B[], int N) {
	int i, j, temp, n1=0, n2= N-1, c = 0, p = 0;
	cout << "Shaker: \n";
	do {
		for (i = n2; i > n1; i--) {
			if (B[i - 1] > B[i]) {
				p++;
				j = i;
				temp = B[i - 1];
				B[i - 1] = B[i];
				B[i] = temp;
			}
		}
		n1 = j;
		for (i = n1; i <= n2; i++) {
			c++;
			temp = B[i - 1];
			B[i - 1] = B[i];
			B[i] = temp;
		}
		cout << "Compare: " << c << endl;
		cout << "Perestavili: " << p << endl;
		n2 = j - 1;
	} while (n1<n2);

}
