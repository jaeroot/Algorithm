#include <iostream>
#include <unordered_map>

using namespace std;

int N, K;
int arr[200001] = {};
unordered_map<int, long long> um;
int current = 0;
long long result = 0;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;

	int input;
	um.insert({ 0, 1 });
	for (int i = 0; i < N; i++)
	{
		cin >> input;
		current += input;

		if (um.find(current - K) != um.end())
		{
			result += um[current - K];
		}

		if (um.find(current) != um.end())
		{
			um[current]++;
		}
		else
		{
			um.insert({current, 1});
		}
	}

	cout << result << '\n';


	return 0;
}
