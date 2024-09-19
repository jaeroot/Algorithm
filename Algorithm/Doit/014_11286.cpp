#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>

using namespace std;

int N;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;

		if (num == 0)
		{
			if (pq.empty())
			{
				cout << "0" << "\n";
			}
			else
			{
				cout << pq.top().second << "\n";
				pq.pop();
			}
		}
		else
		{
			pq.push({ abs(num), num });
		}
	}


	return 0;
}
