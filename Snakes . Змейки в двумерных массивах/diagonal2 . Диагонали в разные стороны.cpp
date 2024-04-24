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
    A[1][1] = 1;
    int point[2] = {2, 1};
    bool diagonalRightUp = true, diagonalLeftDown = false;
    for (int i = 2; i < (N - 2) * (M - 2) + 1; i++)
    {
        A[point[0]][point[1]] = i;
        if (A[point[0] - 1][point[1] + 1] != 0 && diagonalLeftDown == false)
        {
            diagonalRightUp = false;
            diagonalLeftDown = true;
            if (A[point[0]][point[1] + 1] == 0)
            {
                point[1]++;
                A[point[0]][point[1]] = i;
                continue;
            }
            else
            {
                point[0]++;
                A[point[0]][point[1]] = i;
                continue;
            }
        }
        else if (A[point[0] + 1][point[1] - 1] != 0 && diagonalRightUp == false)
        {
            diagonalLeftDown = false;
            diagonalRightUp = true;
            if (A[point[0] + 1][point[1]] == 0)
            {
                point[0]++;
                A[point[0]][point[1]] = i;
                continue;
            }
            else
            {
                point[1]++;
                A[point[0]][point[1]] = i;
                continue;
            }
        }
        if (diagonalRightUp)
        {
            point[0]--;
            point[1]++;
        }
        else if (diagonalLeftDown)
        {
            point[0]++;
            point[1]--;
        }
    }
    cout << endl;
    printArray(A, M, N);
}