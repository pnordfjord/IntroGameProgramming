#include<iostream>

using namespace std;


int main() {

	int starAmount;
	cout << "Please enter star amount: ";
	cin >> starAmount;

	int spaces = starAmount - 1;

	for (int i = 0; i <= starAmount; i++) {
		
		for (int j = 0; j < spaces; j++) {
			cout << " ";
		}

		for (int j = 0; j <= i; j++) {
			cout << "*";
		}

		cout << endl;
		spaces--;

	}

	spaces = 0;

	for (int i = starAmount; i > 0; --i) {
		for (int j = 0; j < spaces; ++j) {
			cout << " ";
		}

		for (int j = 0; j < i; ++j) {
			cout << "*";
		}

		cout << endl;
		spaces++;
	}
}