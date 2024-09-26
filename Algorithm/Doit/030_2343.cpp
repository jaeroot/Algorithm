#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

vector<int> vec;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	int sum = 0;
	int maxnum = 0;
	vec.reserve(N);
	for (int i = 0; i < N; i++)
	{
		int num = 0;
		cin >> num;

		vec.push_back(num);
		maxnum = max(maxnum, num);
		sum += num;
	}

	int Result = INT_MAX;
	int Size = 0;
	int s = maxnum;
	int e = sum;
	while (s <= e)
	{
		Size = (s + e) / 2;

		int count = 1;
		int current = 0;
		for (int i = 0; i < N; i++)
		{
			if (current + vec[i] > Size)
			{
				current = vec[i];
				count++;
			}
			else
			{
				current += vec[i];
			}
		}

		if (count <= M)
		{
			Result = min(Size, Result);
			e = (s + e) / 2 - 1;
		}
		else
		{
			s = (s + e) / 2 + 1;
		}
	}

	cout << Result << "\n";

	return 0;
}
