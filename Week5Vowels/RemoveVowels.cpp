#include <iostream>
#include <algorithm>
#include <string>
#include <string_view>

using namespace std;

int main() {

    string stringInput;
    string vowels = "AaEeIiOoUuYy";

    cout << "Please enter text for vowel removal : ";
    cin >> stringInput;	

    auto erased = erase_if(
        stringInput,
        [&vowels](char x) { return vowels.find(x) != string::npos; }
    );

    cout << erased << endl;

    return 0;
}