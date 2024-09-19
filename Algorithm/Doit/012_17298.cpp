#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stack>

using namespace std;

int n;
stack<pair<int, int>> s;
int arr[1000001] = {};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int num;
		cin >> num;

		while (!s.empty() && s.top().second < num)
		{
			arr[s.top().first] = num;
			s.pop();
		}

		s.push({ i, num });
	}

	while (!s.empty())
	{
		arr[s.top().first] = -1;
		s.pop();
	}

	for (int i = 1; i <= n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "\n";


	return 0;
}
