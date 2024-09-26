#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>

using namespace std;

int arr[102][102] = {};
int moveX[4] = { 1, 0, -1, 0 };
int moveY[4] = { 0, 1, 0, -1 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i <= N + 1; i++)
	{
		for (int j = 0; j <= M + 1; j++)
		{
			if (i == 0 || i == N + 1 || j == 0 || j == M + 1)
			{
				arr[i][j] = 0;
			}
			else
			{
				char c;
				cin >> c;

				arr[i][j] = c - '0';
			}
		}
	}

	int result = 1;
	queue<pair<pair<int, int>, int>> q;
	q.push({ { 1, 1 }, 1 });
	arr[1][1] = 0;
	while (!q.empty())
	{
		int currentNum = q.front().second;
		int a = q.front().first.first;
		int b = q.front().first.second;
		q.pop();

		if (a == N && b == M)
		{
			result = currentNum;
			break;
		}

		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				int moveA = a + moveX[i];
				int moveB = b + moveY[i];

				if (arr[moveA][moveB] == 1)
				{
					arr[moveA][moveB] = 0;
					q.push({ {moveA, moveB},  currentNum + 1 });
				}
			}
		}
	}

	cout << result << "\n";


	return 0;
}
