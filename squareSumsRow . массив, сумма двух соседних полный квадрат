#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

int search(vector<int> V, int target)
{
	for (int i = 0; i < V.size(); i++)
	{
		if (V[i] == target)
			return i;
	}
	return -1;
}

void f(vector<int>* V, int N, vector<int> squares, vector<int> build)
{
	int t;
	if (build.size() == N)
	{
		(*V) = build;
		return;
	}
	for (int i = 0; i < squares.size(); i++)
	{
		t = squares[i] - build[build.size() - 1];
		if (t > 0 && t < N + 1 && search(build, t) == -1)
		{
			build.push_back(t);
			f(V, N, squares, build);
			build.erase(build.begin() + build.size() - 1);
		}
	}
}

vector<int> square_sums_row(int n)
{
	vector<int> V, squares;
	int t = 0;
	while (t * t <= 2 * n - 1)
		t++;
	t--;
	for (int i = 2; i <= t; i++)
		squares.push_back(i * i);

	for (int i = 1; i <= n; i++)
	{
		V.clear();
		f(&V, n, squares, {i});
		if (V.size() > 0)
			return V;
	}
	return {};
}


int main()
{
	auto start_time = chrono::high_resolution_clock::now();
	vector<int> V;
	V = square_sums_row(15);
	for (int i = 0; i < V.size(); i++)
		cout << V[i] << ' ';
	cout << endl;
	auto end_time = chrono::high_resolution_clock::now();
	chrono::duration<double> elapsed_time = end_time - start_time;
	cout << "Программа выполнилась за " << elapsed_time.count() << " секунд." << endl;
}
