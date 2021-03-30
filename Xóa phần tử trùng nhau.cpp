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


void Delete(int a[], int &n, int pos) {
	for (int i = pos; i < n; i++) {
		a[i] = a[i + 1];
	}
	n--;
}

void process(int a[], int &n) {
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i] == a[j])
			{
				Delete(a,n,j);
				j--;
			}
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
	cout << "After deleting: " << endl;
	output(a,n);
	return 0;
}   