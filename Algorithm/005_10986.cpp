#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

int N, M;
int arr[1000001] = {};
int mod[1000] = {};

int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++)
	{
		int num;
		scanf("%d", &num);

		arr[i] = (arr[i - 1] + num) % M;
		mod[arr[i]]++;
	}

	long long result = mod[0];
	for (int i = 0; i < M; i++)
	{
		result += (mod[i] - 1) / 2.0 * (mod[i]);
	}

	printf("%lld\n", result);

	return 0;
}
