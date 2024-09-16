#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

int N, M;
int arr[1025][1025] = {};

int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			int num;
			scanf("%d", &num);

			arr[i][j] = arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1] + num;
		}
	}

	for (int k = 0; k < M; k++)
	{
		int x1, x2, y1, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

		int result = arr[x2][y2] - arr[x2][y1 - 1] - arr[x1 - 1][y2] + arr[x1 - 1][y1 - 1];
		printf("%d\n", result);
	}

	return 0;
}
