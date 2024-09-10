#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

int main()
{
	int N;
	scanf("%d", &N);

	int answer = 0;
	while (N-- > 0)
	{
		int num;
		scanf("%1d", &num);

		answer += num;
	}

	printf("%d\n", answer);

	return 0;
}
