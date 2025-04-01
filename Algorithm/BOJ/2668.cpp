#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int arr[101] = {};
int visited[101] = {};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}

	vector<int> result;
	int current = 1;
	for (int i = 1; i <= N; i++)
	{
		if (visited[i] != 0)
		{
			continue;
		}

		int index = i;
		vector<int> vec;
		vec.push_back(index);
		while (true)
		{
			visited[index] = current;

			if (visited[arr[index]] == current)
			{
				bool bFlag = false;

				for (int v : vec)
				{
					if (v == arr[index])
					{
						bFlag = true;
					}

					if (bFlag)
					{
						result.push_back(v);
					}
				}

				break;
			}
			else if (visited[arr[index]] == 0)
			{
				index = arr[index];
				vec.push_back(index);
			}
			else
			{
				break;
			}
		}

		current++;
	}

	sort(result.begin(), result.end());

	cout << result.size() << '\n';
	for (int r : result)
	{
		cout << r << '\n';
	}


	return 0;
}
