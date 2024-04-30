#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(const string& str, int l, int r)
{
    for (int i = l; i <= r; i++)
    {
        if (str[i] != str[r - i + l])
            return false;
    }
    return true;
}

void f(string& input, int& mx, int l, int r, int& L, int& R)
{
    if (l <= r && r < input.size())
    {
        if (isPalindrome(input, l, r) && r - l + 1 >= mx)
        {
            mx = r - l + 1;
            L = l;
            R = r;
        }
        f(input, mx, l + 1, r, L, R);
        f(input, mx, l, r - 1, L, R);
    }
}

string longestPalindrome(string input)
{
    int mx = -1, l = 0, r = input.size() - 1, L = 0, R = 0;
    f(input, mx, l, r, L, R);
    return input.substr(L, R - L + 1);
}

int main()
{
    cout << longestPalindrome("badad");
}