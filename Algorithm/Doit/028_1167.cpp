#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> vec[100001];
bool visited[100001] = {};
int Result = 0;

int DFS(int N, int cost)
{
	visited[N] = true;

	vector<int> CurrentCost;
	CurrentCost.push_back(0);
	CurrentCost.push_back(0);

	for (auto v : vec[N])
	{
		if (!visited[v.first])
		{
			CurrentCost.push_back(DFS(v.first, v.second));
		}
	}

	sort(CurrentCost.begin(), CurrentCost.end(), greater<int>());
	
	Result = max(Result, CurrentCost[0] + CurrentCost[1]);
	
	return CurrentCost[0] + cost;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int V;
	cin >> V;

	for (int i = 0; i < V; i++)
	{
		int num;
		cin >> num;

		while (true)
		{
			int a;
			cin >> a;

			if (a == -1)
			{
				break;
			}

			int b;
			cin >> b;

			vec[num].push_back({ a, b });
		}
	}

	DFS(1, 0);

	cout << Result << "\n";


	return 0;
}
