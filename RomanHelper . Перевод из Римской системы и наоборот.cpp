#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

class RomanHelper
{
public:
    string to_roman(int n)
    {
        map<int, string> M = {{1, "I"}, {4, "IV"}, {5, "V"}, {9, "IX"}, {10, "X"}, {40, "XL"}, 
        {50, "L"}, {90, "XC"}, {100, "C"}, {400, "CD"}, {500, "D"}, {900, "CM"}, {1000, "M"}};
        vector<int> V = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string rez;
        int I = 0;

        while (n > 0)
        {
            if (n - V[I] < 0)
                I++;
            else
            {
                rez += M[V[I]];
                n -= V[I];
            }
        }
        return rez;
    }
    
    int from_roman(string rn)
    {
        map<string, int> M = {{"I", 1}, {"IV", 4}, {"V", 5}, {"IX", 9}, {"X", 10}, {"XL", 40}, 
        {"L", 50}, {"XC", 90}, {"C", 100}, {"CD", 400}, {"D", 500}, {"CM", 900}, {"M", 1000}};
        vector<string> V = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int rez = 0, I = 0;

        while (rn.size() > 0)
        {
            if (rn.substr(0, V[I].size()) == V[I])
            {
                rez += M[V[I]];
                rn = rn.substr(V[I].size());
            }
            else
                I++;
        }
        return rez;
    }
} RomanNumerals;

int main()
{
    cout << RomanNumerals.from_roman("MDCLXVI") << endl;
    cout << RomanNumerals.to_roman(1666);
}