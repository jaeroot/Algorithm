#include <iostream>

using namespace std;

bool arr[1001] = {};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K;
	cin >> N >> K;

	for (int i = 2; i <= N; i++)
	{
		if (arr[i])
		{
			continue;
		}

		for (int j = 1; i * j <= N; j++)
		{
			if (!arr[i * j])
			{
				arr[i * j] = true;
				K--;

				if (K == 0)
				{
					cout << i * j << '\n';

					break;
				}
			}
		}

		if (K == 0)
		{
			break;
		}
	}

	return 0;
}
