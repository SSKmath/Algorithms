#include <iostream>
#include <string>
#include <cmath>

using namespace std;

string transNumberSys(int x, int n)
{
    if (x < n)
        return to_string(x);
    int t;
    t = x % n;
    return transNumberSys(x / n, n) + to_string(t);
}

void out(string indexes, string alph)
{
    for (int i = 0; i < indexes.size(); i++)
    {
        cout << alph[stoi(indexes.substr(i, 1))];
    }
    cout << endl;
}

int main()
{
    string alph;
    cin >> alph;
    int length;
    cin >> length;
    int maxNumber = pow(alph.size(), length), sysShes = alph.size();
    string t;
    for (int i = 0; i < maxNumber; i++)
    {
        t = transNumberSys(i, sysShes);
        while (t.size() < length)
            t = '0' + t;
        out(t, alph);
    }
}