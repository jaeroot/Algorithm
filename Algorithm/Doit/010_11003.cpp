#define _CRT_SECURE_NO_WARNING

#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, L;
	cin >> N >> L;

	vector<int> vec;
	vec.reserve(N);
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;

		vec.push_back(num);
	}

	priority_queue<int, vector<int>, greater<int>> BinaryQueue;
	priority_queue<int, vector<int>, greater<int>> ToDeleteQueue;
	for (int i = 0; i < N; i++)
	{
		if (i == 0)
		{
			for (int j = i - L + 1; j <= i; j++)
			{
				if (j < 0)
				{
					continue;
				}

				BinaryQueue.emplace(vec[j]);
			}
		}
		else
		{
			if (i - L + 1 > 0)
			{
				ToDeleteQueue.push(vec[i - L]);

				while (!ToDeleteQueue.empty() && BinaryQueue.top() == ToDeleteQueue.top())
				{
					BinaryQueue.pop();
					ToDeleteQueue.pop();
				}
			}
			BinaryQueue.emplace(vec[i]);
		}
		
		cout << BinaryQueue.top() << " ";
	}
	cout << "\n";

	return 0;
}
