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

	vector<int> vec;

	for (auto s : str)
	{
		vec.push_back(s - '0');
	}

	sort(vec.begin(), vec.end(), greater<int>());

	for (auto v : vec)
	{
		cout << v;
	}

	return 0;
}
