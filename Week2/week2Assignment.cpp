#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main()
{
    float value1, value2, value3;
    cout << "Please enter three values separated by space: ";
    cin >> value1;
    cin >> value2;
    cin >> value3;

    vector<float> v{value1, value2, value3};

    float sum = accumulate(v.begin(), v.end(), 0);

    float average = sum / v.size();

    cout << "sum: " << sum << endl << "average " << average << endl;

    return 0;
}