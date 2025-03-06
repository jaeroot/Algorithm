#include <iostream>
#include <string>
#include <cmath>
#include <limits.h>

using namespace std;

long long arr1[36] = {};
long long arr2[36] = {};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str1, str2;
	cin >> str1 >> str2;

	for (int i = str1.size() - 1; i >= 0; i--)
	{
		int temp = str1[i] - (str1[i] >= 'a' ? 'a' - 10 : '0');
		
		for (int j = 2; j <= 36; j++)
		{
			if (arr1[j - 1] == -1)
			{
				continue;
			}

			if (temp >= j)
			{
				arr1[j - 1] = -1;

				continue;
			}

			long long CurrentValue = pow(j, str1.size() - 1 - i);
			double MaxQuotient = LLONG_MAX - arr1[j - 1] / CurrentValue;
			if (MaxQuotient < temp)
			{
				arr1[j - 1] = -1;
				
				continue;
			}

			arr1[j - 1] += temp * CurrentValue;
		}
	}

	for (int i = str2.size() - 1; i >= 0; i--)
	{
		int temp = str2[i] - (str2[i] >= 'a' ? 'a' - 10 : '0');

		for (int j = 2; j <= 36; j++)
		{
			if (arr2[j - 1] == -1)
			{
				continue;
			}

			if (temp >= j)
			{
				arr2[j - 1] = -1;

				continue;
			}

			long long CurrentValue = pow(j, str2.size() - 1 - i);
			double MaxQuotient = LLONG_MAX - arr2[j - 1] / CurrentValue;
			if (MaxQuotient < temp)
			{
				arr2[j - 1] = -1;

				continue;
			}

			arr2[j - 1] += temp * CurrentValue;
		}
	}
	
	int Count = 0;
	int X, A, B;
	for (int i = 2; i < 36; i++)
	{
		for (int j = 2; j < 36; j++)
		{
			if (i != j && arr1[i] == arr2[j] && arr1[i] != -1)
			{
				Count++;

				X = arr1[i];
				A = i + 1;
				B = j + 1;
			}
		}
	}

	if (Count == 0)
	{
		cout << "Impossible" << '\n';
	}
	else if (Count == 1)
	{
		cout << X << ' ' << A << ' ' << B << '\n';
	}
	else
	{
		cout << "Multiple" << '\n';
	}

	return 0;
}
