#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

int main()
{
	int N;
	scanf("%d", &N);

	int sum = 0;
	int start = 1;
	int result = 0;
	for (int i = 1; i <= N; i++)
	{
		sum += i;

		if (sum > N)
		{
			for (; start <= i;)
			{
				sum -= start;
				start++;
				if (sum < N)
				{
					break;
				}
				else if (sum == N)
				{
					result++;
					break;
				}
			}
		}
		else if (sum == N)
		{
			result++;
		}
	}

	printf("%d\n", result);

	return 0;
}
