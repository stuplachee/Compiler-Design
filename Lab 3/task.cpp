#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool isValidKeyword(const string& input)
{
    fstream keywordFile("Keywords.txt");

    string keyword;
    while (getline(keywordFile, keyword))
    {
        if (input == keyword)
        {
            cout << "Invalid identifier: Keyword/DataType cannot be used as an identifier" << endl;
            return false;
             keywordFile.close();
        }
    }

    return true;

}

bool ValidIdentifier(const string& input)
{
    int n = input.length();
    int validCount = 0;

    if (n == 0)
    {
        cout << "Invalid: The identifier is empty." << endl;
        return false;
    }

    if ((input[0] == '_') || (input[0] >= 'a' && input[0] <= 'z') || (input[0] >= 'A' && input[0] <= 'Z'))
    {
        validCount++;
    }
    else
    {
        cout << "Invalid: The first character '" << input[0] << "' is not valid for an identifier." << endl;
        return false;
    }

    for (int i = 1; i < n; ++i)
    {
        if ((input[i] == '_') || (input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z') || (input[i] >= '0' && input[i] <= '9'))
        {
            validCount++;
        }
        else
        {
            cout << "Invalid: The character at position " << i << " ('" << input[i] << "') is not valid for an identifier." << endl;
            return false;
        }
    }

    if (validCount == n)
    {
        cout << "Valid identifier." << endl;
        return true;
    }

    return false;
}

int main()
{

    string input;

    while (true)
    {
        cout << "Enter a variable name: ";
        cin >> input;

        if (!isValidKeyword(input))
        {
            continue;
        }

        ValidIdentifier(input);
    }


    return 0;
}
