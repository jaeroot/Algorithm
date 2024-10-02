#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stack>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int A, B, C;
	cin >> A >> B >> C;

	int GCD = 1;
	int num1 = A, num2 = B;
	stack<pair<int, int>> s;
	while (true)
	{
		int div = num1 / num2;
		int mod = num1 % num2;
		s.push({ div, mod });

		if (mod == 0)
		{
			break;
		}

		num1 = num2;
		num2 = mod;
	}
	GCD = num2;
	
	if (C % GCD != 0)
	{
		cout << -1 << "\n";

		return 0;
	}

	int x = 1, y = 0;
	while (!s.empty())
	{
		auto top = s.top();
		s.pop();

		int NewX = y;
		int NewY = x - (y * top.first);

		x = NewX;
		y = NewY;
	}

	cout << x * (C / GCD) << " ";
	cout << y * (C / GCD) << "\n";


	return 0;
}
