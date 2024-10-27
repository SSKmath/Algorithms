#include <iostream>
#include <vector>

using namespace std;

vector<int> mergeSortHelper(const vector<int>& V, int start, int end)
{
    if (start == end)
        return {V[start]};    
    
    int mid = start + (end - start) / 2;
    vector<int> v1 = mergeSortHelper(V, start, mid);
    vector<int> v2 = mergeSortHelper(V, mid + 1, end);

    vector<int> rez(v1.size() + v2.size());
    
    int i = 0, j = 0;
    while (i < v1.size() && j < v2.size())
    {
        if (v1[i] < v2[j])
        {
            rez[i + j] = v1[i];
            i++;
        }
        else
        {
            rez[i + j] = v2[j];
            j++;
        }
    }
    while (i < v1.size())
    {
        rez[i + j] = v1[i];
        i++;
    }
    while (j < v2.size())
    {
        rez[i + j] = v2[j];
        j++;
    }
    
    return rez;
}

vector<int> mergeSort(const vector<int>& V)
{
    return mergeSortHelper(V, 0, V.size() - 1);
}

int main()
{
	vector<int> V = {1, 2, 3, 9, 7, 4, 4, 2};

	for (int i = 0; i < V.size(); i++)
		cout << V[i] << ' ';
	cout << endl;

	V = mergeSort(V);
	for (int i = 0; i < V.size(); i++)
		cout << V[i] << ' ';
}
