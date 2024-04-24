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

    int point[2] = {1, 1};
    bool right = true, down = false, left = false, up = false;
    for (int i = 1; i < (M - 2) * (N - 2) + 1; i++)
    {
        A[point[0]][point[1]] = i;

        if (A[point[0]][point[1] + 1] != 0 && right)
        {
            right = false;
            down = true;
        }
        else if (A[point[0] + 1][point[1]] != 0 && down)
        {
            down = false;
            left = true;
        }
        else if (A[point[0]][point[1] - 1] != 0 && left)
        {
            left = false;
            up = true;
        }
        else if (A[point[0] - 1][point[1]] != 0 && up)
        {
            up = false;
            right = true;
        }

        if (right)
            point[1]++;
        else if (down)
            point[0]++;
        else if (left)
            point[1]--;
        else
            point[0]--;
    }
    cout << endl;
    printArray(A, M, N);
}