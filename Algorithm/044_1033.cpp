#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>

using namespace std;

pair<int, int> arr[10][10] = {};
bool visited[10] = {};
queue<int> q;
int ratio[10] = {};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	for (int i = 1; i < N; i++)
	{
		int a, b, p, q;
		cin >> a >> b >> p >> q;

		arr[a][b] = { p, q };
		arr[b][a] = { q, p };
	}

	q.push(0);
	visited[0] = true;
	ratio[0] = 1;
	while (!q.empty())
	{
		for (int i = 0; i < N; i++)
		{
			if (arr[q.front()][i].first > 0 && visited[i] == false)
			{
				visited[i] = true;
				q.push(i);

				int A = ratio[q.front()];
				int B = arr[q.front()][i].first;
				while (true)
				{
					int Mod = A % B;

					if (Mod == 0)
					{
						break;
					}

					A = B;
					B = Mod;
				}

				int mul1 = arr[q.front()][i].first / B;
				int mul2 = ratio[q.front()] / B;
				for (int j = 0; j < N; j++)
				{
					ratio[j] *= mul1;
				}
				ratio[i] = mul2 * arr[q.front()][i].second;
			}
		}

		q.pop();
	}

	int GCD = ratio[0];
	for (int i = 1; i < N; i++)
	{
		int A = GCD;
		int B = ratio[i];
		while (true)
		{
			int Mod = A % B;

			if (Mod == 0)
			{
				break;
			}

			A = B;
			B = Mod;
		}

		GCD = B;
	}

	for (int i = 0; i < N; i++)
	{
		cout << ratio[i] / GCD << " ";
	}
	cout << "\n";


	return 0;
}
