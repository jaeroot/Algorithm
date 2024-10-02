#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, K, X;
vector<int> vec[300001] = {};
queue<pair<int, int>> q;
bool visited[300001] = {};
vector<int> result;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K >> X;

	int a, b;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;

		vec[a].push_back(b);
	}

	visited[X] = true;
	q.push({ X, 0 });
	while (!q.empty())
	{
		auto top = q.front();
		q.pop();

		if (top.second > K)
		{
			break;
		}

		if (top.second == K)
		{
			result.push_back(top.first);
		}

		for (auto v : vec[top.first])
		{
			if (visited[v] == false)
			{
				visited[v] = true;
				q.push({ v, top.second + 1 });
			}
		}
	}

	sort(result.begin(), result.end());

	if (result.empty())
	{
		cout << -1 << '\n';
	}
	else
	{
		for (auto r : result)
		{
			cout << r << '\n';
		}
	}


	return 0;
}
