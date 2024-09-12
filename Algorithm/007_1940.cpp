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

	int N, M;
	cin >> N;
	cin >> M;

	vector<int> vec;
	vec.reserve(N);
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;

		vec.push_back(num);
	}

	sort(vec.begin(), vec.end());

	int StartIndex = 0;
	int EndIndex = (M > N - 1) ? N - 1 : M;
	int result = 0;
	while (StartIndex < EndIndex)
	{
		int sum = vec[StartIndex] + vec[EndIndex];

		if (sum == M)
		{
			result++;
			StartIndex++;
			EndIndex--;
		}
		else if (sum > M)
		{
			EndIndex--;
		}
		else if (sum < M)
		{
			StartIndex++;
		}
	}

	printf("%d\n", result);

	return 0;
}
