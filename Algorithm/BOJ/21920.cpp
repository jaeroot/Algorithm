#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

const int MAX_ARR = 1000000;
int input[MAX_ARR] = {};
bool arr[MAX_ARR + 1] = { true, true };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, X;
	cin >> N;
	//scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		cin >> input[i];
		//scanf("%d", &input[i]);
	}

	cin >> X;
	//scanf("%d", &X);

	for (int i = 2; i <= X; i++)
	{
		if (X % i == 0)
		{
			for (int j = 1; j * i <= MAX_ARR; j++)
			{
				arr[j * i] = true;
			}
		}
	}

	long long result = 0;
	int TotalNum = 0;
	for (int i = 0; i < N; i++)
	{
		if (!arr[input[i]])
		{
			result += input[i];
			TotalNum++;
		}
	}

	/*
	cout << fixed;
	cout << precision(6);
	*/

	printf("%.6lf", (double)result / TotalNum);


	return 0;
}
