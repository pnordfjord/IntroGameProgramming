#include <iostream>

using namespace std;

bool isPrimeNumber(int num) {
    if (num == 1) return false;

    for (int i = 2; i < num; i++) {
        if (num % i == 0) return false;
        break;
    }
}

void printBoolPrime(bool b) {
    if (b) {
        cout << ("not a prime number") << endl;
    }
    else {
        cout << "is a prime number"   << endl;
    }
}

int main() {

    int num;
    cout << "Enter a number to see if it's prime: ";
    cin >> num;

    printBoolPrime(isPrimeNumber(num));

    return 0;
}