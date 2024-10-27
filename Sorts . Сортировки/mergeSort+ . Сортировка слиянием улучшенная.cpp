#include <iostream>
#include <vector>

using namespace std;

void mergeSortHelper(vector<int>& V, int start, int end, vector<int>& T)
{
    if (start == end)
    {
        T[start] = V[start];
        return;
    }  
    
    int mid = start + (end - start) / 2;
    mergeSortHelper(V, start, mid, T);
    mergeSortHelper(V, mid + 1, end, T);
    
    int i = start;
    int j = mid + 1;
    int k = start;
    while (i <= mid && j <= end)
    {
        if (V[i] < V[j])
        {
            T[k] = V[i];
            i++;
        }
        else
        {
            T[k] = V[j];
            j++;
        }
        k++;
    }
    
    while (i <= mid)
    {
        T[k] = V[i];
        i++;
        k++;
    }
    
    while (j <= end)
    {
        T[k] = V[j];
        j++;
        k++;
    }
    
    for (int m = start; m <= end; m++)
        V[m] = T[m];
}

void mergeSort(vector<int>& V)
{
    vector<int> T(V.size());
    mergeSortHelper(V, 0, V.size() - 1, T);
}

int main()
{
    vector<int> V = {1, 2, 3, 9, 7, 4, 4, 2};

    for (int i = 0; i < V.size(); i++)
        cout << V[i] << ' ';
    cout << endl;

    mergeSort(V);
    
    for (int i = 0; i < V.size(); i++)
        cout << V[i] << ' ';
}
