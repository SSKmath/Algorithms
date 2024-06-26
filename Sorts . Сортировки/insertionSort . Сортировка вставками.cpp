#include <iostream>
#include <vector>

using namespace std;

vector<int> insertionSort(vector<int> V)
{
	int t, sort;
	for (int i = 1; i < V.size(); i++)
	{
		sort = i - 1;
		while (sort > -1 && V[sort] > V[sort + 1])
		{
			t = V[sort];
			V[sort] = V[sort + 1];
			V[sort + 1] = t;
			sort--;
		}
	}
	return V;
}

int main()
{
	vector<int> V = {5, 8, 7, 0, -2};
	for (int i = 0; i < V.size(); i++)
		cout << V[i] << ' ';
	V = insertionSort(V);
	for (int i = 0; i < V.size(); i++)
		cout << V[i] << ' ';
}
