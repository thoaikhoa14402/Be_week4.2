#include<iostream>

using namespace std;

void input(int a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << "a[" << i << "] = ";
		cin >> a[i];
	}
}
bool isPalindrome(int n) {
	int num = 0, temp = n;
	while (n != 0) {
		num = num * 10 + (n % 10);
		n /= 10;
	}
	if (num == temp) return true;
	return false;
}

void Del(int a[], int &n, int pos) {
	for (int i = pos; i < n - 1; i++) {
		a[i] = a[i + 1];
	}
	n--;
}

void process(int a[], int &n, int &count){
	for (int i = 0; i < n; i++) {
		if (isPalindrome(a[i])) {
			Del(a, n, i);
			i--;
			++count;
		}
	}
	
}

void output(int a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << "\t";
	}
}
int main() {
	int a[100], n, count = 0;
	do {
		cout << "Please enter n elements in array (n > 0): " << endl;
		cin >> n;
		input(a, n);
	} while (n < 0);

	process(a, n,count);
	if (count == 0) cout << "Cannot find the palindrome number in Array for deleting";
	else {
		cout << "After Deleting Palindrome Number: " << endl;
		if (n == 0) {
			cout << "The array deleted all the elements";
		}
		else 
			output(a, n);
	}
	return 0;
}
