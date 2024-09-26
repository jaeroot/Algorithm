#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> vec;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vec.reserve(N);
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;

		vec.push_back(num);
	}
	sort(vec.begin(), vec.end());

	int M;
	cin >> M;

	for (int i = 0; i < M; i++)
	{
		int num;
		cin >> num;

		bool bResult = binary_search(vec.begin(), vec.end(), num);
		cout << bResult << "\n";
	}



	return 0;
}
