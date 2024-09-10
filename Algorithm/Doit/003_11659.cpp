#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

int N, M;
int SumArr[100001] = { 0 };

int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++)
	{
		int num;
		scanf("%d", &num);

		SumArr[i] = SumArr[i - 1] + num;
	}

	for (int i = 0; i < M; i++)
	{
		int first, second;
		scanf("%d %d", &first, &second);

		int sum = SumArr[second] - SumArr[first - 1];
		printf("%d\n", sum);
	}

	return 0;
}
