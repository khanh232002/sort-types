#include<fstream>
#include<iostream>
#include<algorithm>
#include<vector>
#include<chrono>
using namespace std;

void Inp(long* a, long n) {
	ifstream list;
	list.open("01.txt");
	for (long i = 0; i < 1000000; i++)
		list >> a[i];
	list.close();
}

void Out(long* a, long n) {
	ofstream list;
	list.open("sorted.txt");
	for (long i = 0; i < n; i++)
		list << a[i] << " ";
	list.close();
}

void Inp(double* a, long n) {
	ifstream list;
	list.open("10.txt");
	for (long i = 0; i < 1000000; i++)
		list >> a[i];
	list.close();
}

void Out(double* a, long n) {
	ofstream list;
	list.open("sorted.txt");
	for (long i = 0; i < n; i++)
		list << a[i] << " ";
	list.close();
}

int compareLong(const void* x, const void* y) {
	if (*(int*)x > *(int*)y) return 1;
	else if (*(int*)x < *(int*)y) return -1;
	else return 0;
}

int compareDouble(const void* x, const void* y) {
	if (*(double*)x > *(double*)y) return 1;
	else if (*(double*)x < *(double*)y) return -1;
	else return 0;
}

int main() {
	long* a; double* b;
	a = new long[1000000];
	b = new double[1000000];
	long n = 1000000;
	Inp(b, n);


	auto begin = chrono::high_resolution_clock::now();
	qsort(b, n - 1, sizeof(double), compareDouble);
	auto end = chrono::high_resolution_clock::now();
	auto dur = end - begin;
	auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();


	Out(b, n);
	delete[] a, b;
	cout << ms << "ms";
	return 1;
}