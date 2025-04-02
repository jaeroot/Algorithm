#include <iostream>
#include <limits.h>

using namespace std;

int N;
int arr[11] = {};
int op[4] = {};
int result = 0, MinResult = INT_MAX, MaxResult = INT_MIN;

void func(int index)
{
	if (index == N)
	{
		MinResult = min(MinResult, result);
		MaxResult = max(MaxResult, result);

		return;
	}

	for (int i = 0; i < 4; i++)
	{
		if (op[i] > 0)
		{
			int current = result;

			switch (i)
			{
			case 0:
				result += arr[index];
				break;
			case 1:
				result -= arr[index];
				break;
			case 2:
				result *= arr[index];
				break;
			case 3:
				result /= arr[index];
				break;
			default:
				break;
			}

			op[i]--;
			func(index + 1);

			op[i]++;
			result = current;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < 4; i++)
	{
		cin >> op[i];
	}

	result = arr[0];
	func(1);

	cout << MaxResult << '\n';
	cout << MinResult << '\n';

	return 0;
}
