#include <iostream>
#include <queue>

using namespace std;

int T, N, M, K;
int arr[52][52] = {};
int move_x[4] = {1, 0, -1, 0};
int move_y[4] = {0, 1, 0, -1};
int result = 0;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	while (T-- > 0)
	{
		// initialize
		result = 0;
		for (int i = 0; i < N + 2; i++)
		{
			for (int j = 0; j < M + 2; j++)
			{
				arr[i][j] = 0;
			}
		}

		// input
		cin >> M >> N >> K;
				
		int input1, input2;
		for (int i = 0; i < K; i++)
		{
			cin >> input1 >> input2;

			arr[input2 + 1][input1 + 1] = 9999;
		}

		// logic
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= M; j++)
			{
				if (arr[i][j] == 9999)
				{
					queue<pair<int, int>> q;
					q.push({ i, j });

					arr[i][j] = ++result;

					while (!q.empty())
					{
						auto front = q.front();
						int current_x = front.second;
						int current_y = front.first;
						q.pop();

						for (int l = 0; l < 4; l++)
						{
							int next_x = current_x + move_x[l];
							int next_y = current_y + move_y[l];
							if (arr[next_y][next_x] == 9999)
							{
								q.push({ next_y, next_x });
								arr[next_y][next_x] = result;
							}
						}
					}
				}
			}
		}

		cout << result << '\n';
	}


	return 0;
}
