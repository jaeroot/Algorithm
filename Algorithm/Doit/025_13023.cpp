#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>

using namespace std;

vector<int> vec[2000];
bool visited[2000] = {};
int bResult = 0;

void DFS(int current, int depth)
{
	visited[current] = true;

	if (depth == 5)
	{
		bResult = 1;

		return;
	}

	for (auto v : vec[current])
	{
		if (!visited[v])
		{
			DFS(v, depth + 1);

			if (bResult == 1)
			{
				break;
			}
		}
	}

	visited[current] = false;
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

		vec[a].push_back(b);
		vec[b].push_back(a);
	}

	for (int i = 0; i < N; i++)
	{
		DFS(i, 1);

		if (bResult == 1)
		{
			break;
		}
	}

	cout << bResult << "\n";

	return 0;
}
