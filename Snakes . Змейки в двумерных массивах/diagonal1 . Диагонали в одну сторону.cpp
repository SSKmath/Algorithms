#include <iostream>
#include <iomanip>

using namespace std;

void printArray(int (&arr)[100][100], int M, int N)
{
    for (int i = 1; i < N - 1; i++)
    {
        for (int j = 1; j < M - 1; j++)
        {
            cout << setfill(' ') << setw(3) << arr[i][j] << ' ';
        }
        cout << endl;
    }
}

int main()
{
    int N, M;
    cin >> M >> N;
    N = N + 2;
    M = M + 2;
    int A[100][100];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (i > 0 && i < N - 1 && j > 0 && j < M - 1)
                A[i][j] = 0;
            else
                A[i][j] = -1;
        }
    }
    int point1[2] = {1, 1};
    int point2[2] = {1, 1};
    for (int i = 1; i <= (M - 2) * (N - 2); i++)
    {
        A[point1[0]][point1[1]] = i;

        if(A[point1[0] + 1][point1[1] - 1] != -1)
        {
            point1[0]++;
            point1[1]--;
        }
        else
        {
            if(A[1][point2[1] + 1] != -1)
            {
                point2[1]++;
            }
            else
            {
                point2[0]++;
            }
            point1[0] = point2[0];
            point1[1] = point2[1];
        }
    }
    cout << endl;
    printArray(A, M, N);
}