#define _CRT_SERCURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<int> vec;
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;

		vec.push_back(num);
	}

	sort(vec.begin(), vec.end());

	for (auto v : vec)
	{
		cout << v << "\n";
	}


	return 0;
}
