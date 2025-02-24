#include <iostream>
#include <limits.h>

using namespace std;

int n;
int m;
int arr[101][101] = {};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j)
			{
				arr[i][j] = 0;
			}
			else
			{
				arr[i][j] = INT_MAX;
			}
		}
	}

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		arr[a][b] = min(c, arr[a][b]);
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (int k = 1; k <= n; k++)
			{
				if (arr[j][i] == INT_MAX || arr[i][k] == INT_MAX)
				{
					continue;
				}

				int val = arr[j][i] + arr[i][k];
				if (arr[j][k] > val)
				{
					arr[j][k] = val;
				}
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (arr[i][j] == INT_MAX)
			{
				cout << 0 << ' ';
			}
			else
			{
				cout << arr[i][j] << ' ';
			}
		}
		cout << '\n';
	}


	return 0;
}
