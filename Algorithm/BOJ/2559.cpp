#include <iostream>

using namespace std;

int N, K;
int arr[100000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;

	int result = -999999999;
	int current = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];

		if (i < K)
		{
			current += arr[i];
		}
		else
		{
			result = max(result, current);
			current = current + arr[i] - arr[i - K];
		}
	}
	result = max(result, current);
	
	cout << result << '\n';


	return 0;
}