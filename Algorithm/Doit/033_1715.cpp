#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N;
vector<int> vec;
priority_queue<int, vector<int>, greater<int>> q;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	vec.reserve(N);
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;

		vec.push_back(num);
	}
	
	sort(vec.begin(), vec.end());
	for (auto v : vec)
	{
		q.push(v);
	}

	int result = 0;
	while (q.size() >= 2)
	{
		int first = q.top();
		q.pop();

		int second = q.top();
		q.pop();

		int current = first + second;
		result += current;
		q.push(current);
	}

	cout << result << "\n";

	return 0;
}
