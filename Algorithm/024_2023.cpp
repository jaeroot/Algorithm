#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

void DFS(int num, int N)
{
	bool bFlag = true;
	for (int i = 2; i <= sqrt(num); i++)
	{
		if (num % i == 0)
		{
			bFlag = false;
			break;
		}
	}

	if (!bFlag)
	{
		return;
	}

	if (N == 0)
	{
		cout << num << "\n";

		return;
	}

	for (int i = 1; i < 10; i++)
	{
		DFS(num * 10 + i, N - 1);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	for (int i = 2; i < 10; i++)
	{
		DFS(i, N - 1);
	}

	return 0;
}
