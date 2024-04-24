#include <iostream>
#include <string>

using namespace std;

void f(string rez, int n, string alph, int alphSize)
{
    if (n > 0)
    {
        for (int i = 0; i < alphSize; i++)
            f(rez + alph[i], n - 1, alph, alphSize);
    }
    else
        cout << rez << endl;
}

int main()
{    
    string alph;
    cin >> alph;
    int length;
    cin >> length;
    f("", length, alph, alph.size());
}