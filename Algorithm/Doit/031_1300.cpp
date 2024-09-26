#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	int k;
	cin >> k;

	int start = 1;
	int end = k;
	while (start <= end)
	{
		int mid = (start + end) / 2;

		int count = 0;
		for (int i = 1; i <= N; i++)
		{
			count += min(mid / i, N);
		}

		if (count < k)
		{
			start = mid + 1;
		}
		else
		{
			end = mid - 1;
		}
	}

	cout << start << endl;

	return 0;
}
