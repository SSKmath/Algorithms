#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> split(string str)
{
    str += ' ';
    vector<string> words;
    int start = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == ' ')
        {
            if (i - start > 0)
                words.push_back(str.substr(start, i - start));
            start = i + 1;
        }
    }
    return words;
}

int main()
{
    string str;
    getline(cin, str);
    vector<string> words;
    words = split(str);
    cout << words.size() << endl;
    for (int i = 0; i < words.size(); i++)
        cout << words[i] << endl;
}