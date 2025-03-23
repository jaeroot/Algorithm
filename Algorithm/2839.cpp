#include <iostream>
#include <limits.h>

using namespace std;

int N;
int arr[5001] = {};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i <= N; i++)
	{
		arr[i] = 9999;
	}
	arr[3] = 1;
	arr[5] = 1;

	int current;
	for (int i = 6; i <= N; i++)
	{
		arr[i] = min(arr[i - 3], arr[i - 5]) + 1;
	}

	if (arr[N] >= 9999)
	{
		cout << "-1" << '\n';
	}
	else
	{
		cout << arr[N] << '\n';
	}


	return 0;
}
