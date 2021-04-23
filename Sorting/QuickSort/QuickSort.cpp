#include<fstream>
#include<iostream>
#include<chrono>
using namespace std;

void QuickSort(long a[], long left, long right) {
	long i = left, j = right;
	long tmp;
	long pivot = a[(left + right) / 2];

	while (i <= j) {
		while (a[i] < pivot)
			i++;
		while (a[j] > pivot)
			j--;
		if (i <= j) {
			tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
			i++; j--;
		}
	}
	if (left < j)
		QuickSort(a, left, j);
	if (i < right)
		QuickSort(a, i, right);
}

void QuickSort(double a[], long left, long right) {
	long i = left, j = right;
	double tmp;
	double pivot = a[(left + right) / 2];

	while (i <= j) {
		while (a[i] < pivot)
			i++;
		while (a[j] > pivot)
			j--;
		if (i <= j) {
			tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
			i++; j--;
		}
	}
	if (left < j)
		QuickSort(a, left, j);
	if (i < right)
		QuickSort(a, i, right);
}

void Inp(long *a, long n) {
	ifstream list;
	list.open("../Inputs/05(equal).txt");
	for (long i = 0; i < 1000000; i++)
		list >> a[i];
	list.close();
}

void Out(long *a, long n) {
	ofstream list;
	list.open("Output/05(sorted).txt");
	for (long i = 0; i < n; i++)
		list << a[i] << " ";
	list.close();
}

void Inp(double* a, long n) {
	ifstream list;
	list.open("../Inputs/10(equal).txt");
	for (long i = 0; i < 1000000; i++)
		list >> a[i];
	list.close();
}

void Out(double* a, long n) {
	ofstream list;
	list.open("Output/10(sorted).txt");
	for (long i = 0; i < n; i++)
		list << a[i] << " ";
	list.close();
}

int main() {
	long* a; double* b;
	a = new long[1000000];
	b = new double[1000000];
	long n = 1000000;
	Inp(a, n);
	auto begin = chrono::high_resolution_clock::now();
	QuickSort(a, 0, n - 1);
	auto end = chrono::high_resolution_clock::now();
	auto dur = end - begin;
	auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();
	Out(a, n);
	delete[] a, b;
	cout << ms << "ms";
	return 1;
}