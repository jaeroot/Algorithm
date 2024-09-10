#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

int main()
{
	int N = 0;
	scanf("%d", &N);

	int max = -1;
	float result = 0;
	for (int i = 0; i < N; i++)
	{
		int num;
		scanf("%d", &num);

		result += num;
		max = (num > max) ? num : max;
	}

	result = result / N / max * 100.0;

	printf("%.2f\n", result);

	return 0;
}
