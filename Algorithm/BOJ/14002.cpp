#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> vec;
vector<pair<int, int>> position;
vector<int> answer;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	vec.reserve(N);
	position.reserve(N);

	int input;
	for (int i = 0; i < N; i++)
	{
		cin >> input;

		auto it = lower_bound(vec.begin(), vec.end(), input);

		position.push_back({ input, it - vec.begin() + 1 });
		if (it == vec.end())
		{
			vec.push_back(input);
		}
		else
		{
			*it = input;
		}
	}

	int length = vec.size();
	cout << length << '\n';

	answer.reserve(length);
	for (int i = N - 1; i >= 0; i--)
	{
		if (position[i].second == length)
		{
			length--;
			answer.push_back(position[i].first);
		}
	}

	for (int i = answer.size() - 1; i >= 0; i--)
	{
		cout << answer[i] << " ";
	}
	cout << '\n';


	return 0;
}