#include <iostream>
#include <string>

using namespace std;

string transNumberSys(int x, int n, string& alph)
{
    if (x < n)
        return string(1, alph[x]);
    return transNumberSys(x / n, n, alph) + alph[x % n];
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
        t = transNumberSys(i, sysShes, alph);
        while (t.size() < length)
            t = alph[0] + t;
        cout << t << endl;
    }
}