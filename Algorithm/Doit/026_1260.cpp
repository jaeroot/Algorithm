#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> vec[1001] = {};
bool visited[1001] = {};
queue<int> q;

void DFS(int num)
{
	visited[num] = true;

	cout << num << " ";
	for (auto v : vec[num])
	{
		if (!visited[v])
		{
			DFS(v);
		}
	}
}

void BFS()
{
	while (!q.empty())
	{
		int num = q.front();
		if (visited[num])
		{
			q.pop();
			continue;
		}

		visited[num] = true;
		cout << num << " ";
		q.pop();

		for (auto v : vec[num])
		{
			if (!visited[v])
			{
				q.push(v);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, V;
	cin >> N >> M >> V;

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;

		vec[a].push_back(b);
		vec[b].push_back(a);
	}

	for (int i = 1; i <= N; i++)
	{
		sort(vec[i].begin(), vec[i].end());
	}

	for (int i = 0; i <= N; i++)
	{
		visited[i] = false;
	}
	DFS(V);
	cout << "\n";

	for (int i = 0; i <= N; i++)
	{
		visited[i] = false;
	}
	q.push(V);
	BFS();
	cout << "\n";

	return 0;
}
