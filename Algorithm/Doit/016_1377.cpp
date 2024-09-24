#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<pair<int, int>> vec;
	vec.reserve(N);

	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;

		vec.push_back({ num, i });
	}

	sort(vec.begin(), vec.end());

	int MaxCount = 0;
	for (int i = 0; i < N; i++)
	{
		int CurrentCount = vec[i].second - i;

		MaxCount = max(MaxCount, CurrentCount);
	}

	cout << MaxCount + 1 << "\n";


	return 0;
}
