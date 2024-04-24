#include <iostream>
#include <vector>

using namespace std;

vector<int> selectionSort(vector<int> V)
{
    int t;
    for (int i = 0; i < V.size() - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < V.size(); j++)
        {
            if (V[minIndex] > V[j])
                minIndex = j;
        }
        t = V[minIndex];
        V[minIndex] = V[i];
        V[i] = t;
    }
    return V;
}

int main()
{
	vector<int> V = {1, 2, 3, 9, 7, 4, 4, 2};
	for (int i = 0; i < V.size(); i++)
		cout << V[i] << ' ';
	cout << endl;
	V = selectionSort(V);
	for (int i = 0; i < V.size(); i++)
		cout << V[i] << ' ';
}