#include<iostream>

using namespace std;

void input(int a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << "a[" << i << "] = ";
		cin >> a[i];
	}
}

void output(int a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
}
bool isPerfectNum(int n) {
	int sum = 0;
	for (int i = 1; i <= n / 2; i++) {
		if (n % i == 0) sum += i;
	}
	if (sum == n) return true;
	return false;
}

void Add(int a[], int &n, int pos) {
	for(int i = n; i > pos; i--) {
		a[i] = a[i - 1];
	}
	a[pos] = 0;
	n++;
}

void process(int a[], int &n) {
	for (int i = 0; i < n; i++) {
		if (isPerfectNum(a[i])) {
			Add(a,n,i);
		    i++;
		}
	}
}
int main() {
	int a[100], n;
	do {
		cout << "Enter elements: ";
		cin >> n;
	}while(n < 0 || n > 100 );
	input(a,n);
	process(a,n);
	cout << "After adding: " << endl;
	output(a,n);
	return 0;
}  