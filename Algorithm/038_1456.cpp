#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cmath>

using namespace std;

bool arr[10000001] = { true, true };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	double A, B;
	cin >> A >> B;

	int C = (int)sqrt(B);
	for (int i = 2; i * i <= C; i++)
	{
		for (int j = i; i * j <= C; j++)
		{
			arr[i * j] = true;
		}
	}

	int count = 0;
	for (int i = 2; i <= C; i++)
	{
		if (arr[i] == false)
		{
			double current = i;
			while (true)
			{
				current = current * i;

				if (current < A)
				{
					continue;
				}
				else if (current <= B)
				{
					count++;
				}
				else
				{
					break;
				}
			}
		}
	}

	cout << count << "\n";

	return 0;
}
