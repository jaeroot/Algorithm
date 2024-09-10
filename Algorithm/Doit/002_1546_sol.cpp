#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

int main()
{
	int N = 0;
	int A[1000];
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}

	long sum = 0;
	long max = 0;
	for (int i = 0; i < N; i++)
	{
		if (A[i] > max)
		{
			max = A[i];
		}

		sum = sum + A[i];
	}

	double result = sum * 100.0 / max / N;
	cout << result << "\n";

	return 0;
}
