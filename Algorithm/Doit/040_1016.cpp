#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

double MinNum, MaxNum;

bool arr[1000001] = {};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> MinNum >> MaxNum;

	long long num = 2;
	while (true)
	{
		double div1 = MinNum / (num * num);
		double div2 = MaxNum / (num * num);

		if (div2 < 1)
		{
			break;
		}

		for (long long i = div1; i < (long long)(div2 + 1); i++)
		{
			long long index = i * num * num - MinNum;
			if (index < 0)
			{
				continue;
			}
			arr[index] = true;
		}

		num++;
	}

	int count = 0;
	for (long long i = 0; i <= MaxNum - MinNum; i++)
	{
		if (arr[i] == false)
		{
			count++;
		}
	}
	cout << count << "\n";


	return 0;
}
