#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, k;
vector<pair<int, int>> vec[1001] = {};
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
priority_queue<int> result[1001] = {};
bool visited[1001] = {};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> k;
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		vec[a].push_back({ c, b });
	}

	pq.push({ 0, 1 });
	while (!pq.empty())
	{
		pair<int, int> front = pq.top();
		pq.pop();
		int cost = front.first;
		int node = front.second;

		if (result[node].size() < k)
		{
			result[node].push(cost);
		}
		else if (result[node].top() > cost)
		{
			result[node].pop();
			result[node].push(cost);
		}
		else
		{
			continue;
		}

		for (auto v : vec[node])
		{
			pq.push({ cost + v.first, v.second });
		}
	}

	for (int i = 1; i <= n; i++)
	{
		if (result[i].size() < k)
		{
			cout << -1 << '\n';
		}
		else
		{
			cout << result[i].top() << '\n';
		}
	}

	return 0;
}
