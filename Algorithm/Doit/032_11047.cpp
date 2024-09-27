#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K;
	cin >> N >> K;

	vector<int> vec;
	vec.reserve(N);
	int index = 0;
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;

		vec.push_back(num);

		if (num <= K)
		{
			index = i;
		}
	}

	int result = 0;
	for (int i = index; i >= 0; i--)
	{
		result += K / vec[i];
		K %= vec[i];

		if (K == 0)
		{
			break;
		}
	}

	cout << result << "\n";


	return 0;
}
