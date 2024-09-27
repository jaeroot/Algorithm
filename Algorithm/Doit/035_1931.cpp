#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> vec;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vec.reserve(N);
	int first, second;
	for (int i = 0; i < N; i++)
	{
		cin >> first >> second;

		vec.push_back({ second, first });
	}

	sort(vec.begin(), vec.end());

	int CurrentTime = 0;
	int Result = 0;
	for (auto v : vec)
	{
		if (v.second >= CurrentTime)
		{
			Result++;
			CurrentTime = v.first;
		}
	}

	cout << Result << "\n";


	return 0;
}
