#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> vec1;
vector<int> vec2;
bool bZero = false;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	vec1.reserve(N);
	vec2.reserve(N);
	int num;
	for (int i = 0; i < N; i++)
	{
		cin >> num;

		if (num > 0)
		{
			vec1.push_back(num);
		}
		else if (num == 0)
		{
			bZero = true;
		}
		else
		{
			vec2.push_back(num);
		}
	}

	sort(vec1.begin(), vec1.end(), greater<int>());
	sort(vec2.begin(), vec2.end(), less<int>());

	int result = 0;
	for (int i = 0; i < vec1.size(); i += 2)
	{
		if (i == vec1.size() - 1)
		{
			result += vec1[i];
		}
		else
		{
			if (vec1[i] == 1 || vec1[i + 1] == 1)
			{
				result += vec1[i];
				result += vec1[i + 1];

				continue;
			}

			result += vec1[i] * vec1[i + 1];
		}
	}

	for (int i = 0; i < vec2.size(); i += 2)
	{
		if (i == vec2.size() - 1)
		{
			if (bZero)
			{
				i--;
			}
			else
			{
				result += vec2[i];
			}
		}
		else
		{
			result += vec2[i] * vec2[i + 1];
		}
	}

	cout << result << "\n";


	return 0;
}
