#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> arr[1001] = {};
bool visited[1001] = {};

void DFS(int data)
{
	visited[data] = true;

	for (auto v : arr[data])
	{
		if (!visited[v])
		{
			DFS(v);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;

		arr[a].push_back(b);
		arr[b].push_back(a);
	}

	int result = 0;
	for (int i = 1; i <= N; i++)
	{
		if (!visited[i])
		{
			result++;
			visited[i] = true;
			DFS(i);
		}
	}

	cout << result << "\n";

	return 0;
}
