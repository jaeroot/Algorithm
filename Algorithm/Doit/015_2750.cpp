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

	bool bFlag = false;
	for (int i = 0; i < N - 1; i++)
	{
		for (int j = 0; j < N - 1; j++)
		{
			if (vec[j] > vec[j + 1])
			{
				int temp = vec[j + 1];
				vec[j + 1] = vec[j];
				vec[j] = temp;

				bFlag = true;
			}
		}

		if (!bFlag)
		{
			break;
		}
	}

	for (auto v : vec)
	{
		cout << v << "\n";
	}

	return 0;
}
