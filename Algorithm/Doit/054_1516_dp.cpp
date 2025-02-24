#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int t[501] = {};
vector<int> vec[501] = {};
bool visited[501] = {};
int result[501] = {};

void DFS(int index)
{
	visited[index] = true;

	result[index] += t[index];
	for (auto v : vec[index])
	{
		if (visited[v] == false)
		{
			DFS(v);
		}
		result[index] = max(result[index], result[v] + t[index]);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> t[i];

		int input;
		while (true)
		{
			cin >> input;
			if (input == -1)
			{
				break;
			}

			vec[i].push_back(input);
		}
	}

	for (int i = 1; i <= n; i++)
	{
		if (visited[i] == false)
		{
			DFS(i);
		}
	}

	for (int i = 1; i <= n; i++)
	{
		cout << result[i] << '\n';
	}


	return 0;
}
