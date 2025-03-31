#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <map>

using namespace std;

constexpr long long MOD = 1000000007;

int N;
vector<int> vec;
vector<int> position;
vector<vector<pair<int, long long>>> answer;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	vec.reserve(N);
	answer.reserve(N);
	answer.push_back(vector<pair<int, long long>>());
	answer[0].push_back({ INT_MIN + 1, 1 });

	int input;
	for (int i = 0; i < N; i++)
	{
		cin >> input;

		auto it = lower_bound(vec.begin(), vec.end(), input);
		int current = it - vec.begin() + 1;

		pair<int, long long> target = { INT_MIN, 0 };
		for (const auto& a : answer[current - 1])
		{
			if (a.first < input && target.first < a.first)
			{
				target = a;
			}
		}
		long long value = target.second;

		if (it == vec.end())
		{
			vec.push_back(input);

			answer.push_back(vector<pair<int, long long>>());
			answer.back().push_back({ input, value });
		}
		else
		{
			*it = input;

			bool flag = false;
			for (auto& a : answer[current])
			{
				if (a.first > input)
				{
					a.second += value;
					a.second %= MOD;
				}
				else if (a.first == input)
				{
					flag = true;
					a.second += value;
					a.second %= MOD;
				}
			}

			if (!flag)
			{
				answer.back().push_back({ input, value });
			}
		}
	}

	int length = vec.size();
	cout << length << ' ';

	auto result = answer.back().end();
	result--;
	cout << (*result).second << '\n';


	return 0;
}
