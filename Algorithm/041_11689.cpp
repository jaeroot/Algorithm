#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

long long N;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	long long Result = N;
	for (long long i = 2; i * i <= N; i++)
	{
		if (N % i == 0)
		{
			Result -= Result / i;

			while (N % i == 0)
			{
				N /= i;
			}
		}
	}

	if (N > 1)
	{
		Result -= Result / N;
	}


	cout << Result << "\n";


	return 0;
}
