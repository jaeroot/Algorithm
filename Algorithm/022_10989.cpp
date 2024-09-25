#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[10001] = {};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;

		arr[num]++;
	}

	for (int i = 0; i < 10001; i++)
	{
		while (arr[i]-- > 0)
		{
			cout << i << "\n";
		}
	}

	return 0;
}
