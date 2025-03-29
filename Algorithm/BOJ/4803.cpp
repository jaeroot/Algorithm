#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, t = 1;
vector<int> vec[501] = {};
int visited[501] = {};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true)
	{
		cin >> n >> m;
		if (n == 0 && m == 0)
		{
			break;
		}

		for (int i = 1; i <= n; i++)
		{
			vec[i].clear();
			visited[i] = 0;
		}

		int input1, input2;
		for (int i = 0; i < m; i++)
		{
			cin >> input1 >> input2;
			vec[input1].push_back(input2);
			vec[input2].push_back(input1);
		}

		int current = 1;
		int tree = 0;
		for (int i = 1; i <= n; i++)
		{
			if (visited[i] != 0)
			{
				continue;
			}

			bool bResult = true;
			queue<pair<int, int>> q;
			q.push({ i, 0 });
			visited[i] = current;
			
			while (!q.empty())
			{
				auto front = q.front();
				q.pop();

				for (int v : vec[front.first])
				{
					if (v == front.second)
					{
						continue;
					}

					if (visited[v] != 0)
					{
						bResult = false;

						continue;
					}

					visited[v] = current;
					q.push({ v, front.first });
				}
			}

			current++;
			if (bResult)
			{
				tree++;
			}
		}

		cout << "Case " << t << ": ";
		if (tree == 0)
		{
			cout << "No trees." << '\n';
		}
		else if (tree == 1)
		{
			cout << "There is one tree." << '\n';
		}
		else
		{
			cout << "A forest of " << tree << " trees." << '\n';
		}
		t++;
	}

	return 0;
}