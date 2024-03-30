#include <iostream>
#include <string>

using namespace std;

bool haveIt(string str, string s)
{
	for (int i = 0; i < str.size() - s.size(); i++)
	{
		bool flag = true;
		for (int j = 0; j < s.size(); j++)
		{
			if (str[i + j] != s[j])
			{
				flag = false;
				break;
			}
		}
		if (flag)
			return true;
	}
	return false;
}

int main()
{
	string str = "abcdc";
	cout << haveIt(str, "abce");
}
