#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int c[501] = {};
int t[501] = {};
vector<int> vec[501] = {};
int result[501] = {};

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

			vec[input].push_back(i);
			c[i]++;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (c[j] == 0)
			{
				for (int k = 0; k < vec[j].size(); k++)
				{
					result[vec[j][k]] = max(result[vec[j][k]], result[j] + t[j]);
					c[vec[j][k]]--;
				}

				c[j]--;
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		cout << result[i] + t[i] << '\n';
	}


	return 0;
}
