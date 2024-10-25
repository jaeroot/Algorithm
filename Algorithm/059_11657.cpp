#include <iostream>
#include <vector>
#include <tuple>
#include <limits.h>

using namespace std;

int N, M;
vector<tuple<int, int, int>> vec;
long long Result[501] = {};


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		Result[i] = LLONG_MAX;
	}

	vec.reserve(M);
	for (int i = 0; i < M; i++)
	{
		int A, B, C;
		cin >> A >> B >> C;

		vec.push_back({ A, B, C });
	}

	Result[1] = 0;
	for (int i = 0; i < N - 1; i++)
	{
		for (auto v : vec)
		{
			if (Result[get<0>(v)] != LLONG_MAX && Result[get<0>(v)] + get<2>(v) < Result[get<1>(v)])
			{
				Result[get<1>(v)] = Result[get<0>(v)] + get<2>(v);
			}
		}
	}

	bool bFlag = false;
	for (auto v : vec)
	{
		if (Result[get<0>(v)] != LLONG_MAX && Result[get<0>(v)] + get<2>(v) < Result[get<1>(v)])
		{
			bFlag = true;

			break;
		}
	}

	if (bFlag)
	{
		cout << -1 << '\n';
	}
	else
	{
		for (int i = 2; i <= N; i++)
		{
			if (Result[i] == LLONG_MAX)
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << Result[i] << '\n';
			}
		}
	}


	return 0;
}
