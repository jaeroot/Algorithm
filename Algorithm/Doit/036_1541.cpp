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

	string str;
	cin >> str;
	
	str += '*';

	vector<int> vec;
	vector<char> c;
	int num = 0;
	for (auto s : str)
	{
		if (s == '+' || s == '-' || s == '*')
		{
			vec.push_back(num);
			c.push_back(s);

			num = 0;
		}
		else
		{
			num *= 10;
			num += s - '0';
		}
	}

	int result = 0;
	int neg = 0;
	bool bMinus = false;
	for (int i = 0; i < vec.size(); i++)
	{
		if (bMinus)
		{
			neg += vec[i];
		}
		else
		{
			result += vec[i];
			result -= neg;
			neg = 0;
		}

		if (c[i] == '*')
		{
			break;
		}

		if (c[i] == '-')
		{
			bMinus = true;

			result -= neg;
			neg = 0;
		}
	}

	result -= neg;
	cout << result << "\n";


	return 0;
}
