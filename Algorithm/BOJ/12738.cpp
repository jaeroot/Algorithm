#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> vec;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	vec.reserve(N);

	int input;
	for (int i = 0; i < N; i++)
	{
		cin >> input;

		auto it = lower_bound(vec.begin(), vec.end(), input);

		if (it == vec.end())
		{
			vec.push_back(input);
		}
		else
		{
			*it = input;
		}
	}

	cout << vec.size() << '\n';


	return 0;
}