#include <iostream>
#include <vector>

using namespace std;

vector<int> bubbleSort(vector<int> V)
{
	int t;
	for (int end = V.size(); end > 1; end--)
	{
		for (int i = 1; i < end; i++)
		{
			if (V[i - 1] > V[i])
			{
				t = V[i - 1];
				V[i - 1] = V[i];
				V[i] = t;
			}
		}
	}
	return V;
}

int main()
{
	vector<int> V = {1, 2, 3, 9, 7, 4, 4, 2};
	for (int i = 0; i < V.size(); i++)
		cout << V[i] << ' ';
	cout << endl;
	V = bubbleSort(V);
	for (int i = 0; i < V.size(); i++)
		cout << V[i] << ' ';
}
