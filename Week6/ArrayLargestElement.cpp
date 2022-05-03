#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{

    int input;
    int i = 0;
    vector<int> v;

    cout << "Enter values for vector, and finish the vector with end or exit the program." << endl;
    cout << "Example: 1 12 9 8 19 end" << endl; 
    cout << "Enter here: ";


    while (cin >> input) {
        v.push_back(input);
    }

    int maxValue = *max_element(v.begin(), v.end());

    cout << maxValue;

    return 0;
}