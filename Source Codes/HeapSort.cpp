#include<fstream>
#include<iostream>
#include<chrono>
using namespace std;

void heapify(long a[], long n, long i)
{
	long root = i;
	long l = 2 * i + 1;
	long r = 2 * i + 2;
	if (l < n && a[l] > a[root])
	    root = l;
	if (r < n && a[r] > a[root])
	    root = r;
	if (root != i) {
		long tmp = a[i];
		a[i] = a[root];
		a[root] = tmp;
	    heapify(a, n, root);
	}
}
 
void HeapSort(long a[], long n)
{
	for (long i = n / 2 - 1; i >= 0; i--)
	    heapify(a, n, i);
	for (long i = n - 1; i > 0; i--) {
		long tmp = a[0];
		a[0] = a[i];
		a[i] = tmp;
	    heapify(a, i, 0);
	}
}

void heapify(double a[], long n, long i)
{
	long root = i;
	long l = 2 * i + 1;
	long r = 2 * i + 2;
	if (l < n && a[l] > a[root])
		root = l;
	if (r < n && a[r] > a[root])
		root = r;
	if (root != i) {
		double tmp = a[i];
		a[i] = a[root];
		a[root] = tmp;
		heapify(a, n, root);
	}
}

void HeapSort(double a[], long n)
{
	for (long i = n / 2 - 1; i >= 0; i--)
		heapify(a, n, i);
	for (long i = n - 1; i > 0; i--) {
		double tmp = a[0];
		a[0] = a[i];
		a[i] = tmp;
		heapify(a, i, 0);
	}
}

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

int main() {
	long* a; double* b;
	a = new long[1000000];
	b = new double[1000000];
	long n = 1000000;
	Inp(a, n);
	auto begin = chrono::high_resolution_clock::now();
	HeapSort(a, n);
	auto end = chrono::high_resolution_clock::now();
	auto dur = end - begin;
	auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();
	Out(a, n);
	delete[] a, b;
	cout << ms << "ms";
	return 1;
}