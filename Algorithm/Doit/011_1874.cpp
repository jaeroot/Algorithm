#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int n;
int MaxCount = 1;
stack<int> s;
vector<char> vec;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vec.reserve(200000);

	cin >> n;
	bool flag = false;
	for (int i = 1; i <= n; i++)
	{
		flag = false;

		int num;
		cin >> num;

		while (MaxCount <= num)
		{
			vec.push_back('+');
			s.push(MaxCount);
			MaxCount++;
		}

		while (!s.empty() && s.top() >= num)
		{
			s.pop();
			vec.push_back('-');
			flag = true;
		}
		
		if (!flag)
		{
			cout << "NO" << "\n";

			break;
		}
	}

	if (flag)
	{
		for (auto v : vec)
		{
			cout << v << "\n";
		}
	}

	return 0;
}
