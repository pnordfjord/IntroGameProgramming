#include <string>
#include <iostream>

using namespace std;

char string1[] = "A test string of tokens";
char separators[] = " ";
char* token1, * next_token1, * next_token2;

int main(void)
{
	cout << "Tokens:" << endl;

	// establish a string and get the first token:
	token1 = strtok_s(string1, separators, &next_token1);

	// while there are tokens in "string1"
	while (token1 != NULL)
	{
		// get the next token:
		if (token1 != NULL)
		{
			cout << token1 << endl;
			token1 = strtok_s(NULL, separators, &next_token1);
		}
	}

	return 0;
}