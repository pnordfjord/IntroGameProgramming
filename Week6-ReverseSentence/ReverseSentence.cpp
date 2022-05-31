#include <iostream>
#include <string>
#include <vector>

using namespace std;

void tokenizeString(string const& s, const char delimiter, vector<string>& out)
{
    size_t beginning;
    size_t end = 0;

    while ((beginning = s.find_first_not_of(delimiter, end)) != string::npos)
    {
        end = s.find(delimiter, beginning);
        out.push_back(s.substr(beginning, end - beginning));
    }
}

int main()
{
    string s = "C C++ Java";
    string reversed; 
    const char delimiter = ' ';

    vector<string> out;
    tokenizeString(s, delimiter, out);



    //for (int i = (s.size() - 1); i >= 0; --i) {
   //     reversed += s[i];
   // }

    //cout << reversed;

 //   for (auto& s : out) {
   //   cout << s;
 //   }

    return 0;
}