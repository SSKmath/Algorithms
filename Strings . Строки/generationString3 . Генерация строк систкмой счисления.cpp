#include <iostream>
#include <string>
#include <cmath>

using namespace std;

void transNumberSys(int x, int n, string& alph, int cnt)
{
    if (x < n)
    {
        while (cnt > 1)
        {
            cout << alph[0];
            cnt--;
        }
        cout << alph[x];
        return;
    }
    transNumberSys(x / n, n, alph, cnt - 1);
    cout << alph[x % n];
}

int main()
{    
    string alph;
    cin >> alph;
    int length;
    cin >> length;
    int maxNumber = pow(alph.size(), length), sysShes = alph.size();
    for (int i = 0; i < maxNumber; i++)
    {
        transNumberSys(i, sysShes, alph, length);
        cout << endl;
    }
}