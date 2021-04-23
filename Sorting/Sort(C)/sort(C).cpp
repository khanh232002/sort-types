#include<fstream>
#include<iostream>
#include<algorithm>
#include<vector>
#include<chrono>
using namespace std;

void Inp(long* a, long n) {
	ifstream list;
	list.open("../Inputs/06(rand).txt");
	for (long i = 0; i < 1000000; i++)
		list >> a[i];
	list.close();
}

void Out(long* a, long n) {
	ofstream list;
	list.open("Output/06(sorted).txt");
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
	Inp(b, n);
	auto begin = chrono::high_resolution_clock::now();
	sort(b, b + n);
	auto end = chrono::high_resolution_clock::now();
	auto dur = end - begin;
	auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();
	Out(b, n);
	delete[] a, b;
	cout << ms << "ms";
	return 1;
}