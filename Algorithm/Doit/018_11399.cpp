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

	int N;
	cin >> N;

	vector<int> vec;
	vec.reserve(N);
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;

		vec.push_back(num);
	}

	sort(vec.begin(), vec.end());

	int Total = 0;
	int Current = 0;
	for (auto v : vec)
	{
		Current += v;
		Total += Current;
	}

	cout << Total << "\n";


	return 0;
}
