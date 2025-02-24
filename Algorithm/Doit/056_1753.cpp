#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

int V, E;
int K;
vector<pair<int, int>> vec[20001] = {};
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int visited[20001] = {};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> V >> E;
	cin >> K;
	for (int i = 0; i < E; i++)
	{
		int u, vv, w;
		cin >> u >> vv >> w;

		vec[u].push_back({ w, vv });
	}

	for (int i = 0; i <= V; i++)
	{
		visited[i] = INT_MAX;
	}

	pq.push({ 0, K });
	while (!pq.empty())
	{
		pair<int, int> front = pq.top();
		pq.pop();
		if (front.first < visited[front.second])
		{
			visited[front.second] = front.first;

			for (auto v : vec[front.second])
			{
				if (front.first + v.first < visited[v.second])
				{
					pq.push({ front.first + v.first, v.second });
				}
			}
		}
	}

	for (int i = 1; i <= V; i++)
	{
		if (visited[i] == INT_MAX)
		{
			cout << "INF";
		}
		else
		{
			cout << visited[i];
		}
		
		cout << '\n';
	}


	return 0;
}
