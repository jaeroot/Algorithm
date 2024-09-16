#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<int> arr;
	arr.reserve(N);
	unordered_map<int, int> count;

	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;

		arr.push_back(num);
		if (count.find(num) != count.end())
		{
			count[num]++;
		}
		else
		{
			count.insert({ num, 1 });
		}
	}
	sort(arr.begin(), arr.end());


	int result = 0;
	bool bSucceed = false;
	for (int i = 0; i < arr.size(); i++)
	{
		if (i > 0)
		{
			if (arr[i] == arr[i - 1])
			{
				if (bSucceed)
				{
					result++;
				}

				continue;
			}
		}
		bSucceed = false;
		int StartIndex = 0;
		int EndIndex = N - 1;

		while (StartIndex < EndIndex)
		{
			int sum = arr[StartIndex] + arr[EndIndex];

			if (sum > arr[i])
			{
				EndIndex -= count[arr[EndIndex]];
			}
			else if (sum < arr[i])
			{
				StartIndex += count[arr[StartIndex]];
			}
			else
			{
				if (StartIndex == i)
				{
					StartIndex++;
					continue;
				}
				else if (EndIndex == i)
				{
					EndIndex--;
					continue;
				}

				result++;
				bSucceed = true;
				break;
			}
		}
	}

	cout << result << endl;


	return 0;
}
