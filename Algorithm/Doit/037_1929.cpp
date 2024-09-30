#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

bool arr[1000001] = { true, true };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int M, N;
	cin >> M >> N;

	for (int i = 2; i * i <= N; i++)
	{
		for (int j = i; i * j <= N; j++)
		{
			arr[i * j] = true;
		}
	}

	for (int i = M; i <= N; i++)
	{
		if (arr[i] == false)
		{
			cout << i << "\n";
		}
	}

	return 0;
}
