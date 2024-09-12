#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int S, P;
	cin >> S >> P;
	
	string str;
	cin >> str;

	int MinCount[4] = {};
	for (int i = 0; i < 4; i++)
	{
		cin >> MinCount[i];
	}
	unordered_map<char, int> KeytoInt;
	KeytoInt.insert({ 'A', 0 });
	KeytoInt.insert({ 'C', 1 });
	KeytoInt.insert({ 'G', 2 });
	KeytoInt.insert({ 'T', 3 });
	
	int result = 0;
	int CurrentCount[4] = {};
	for (int i = 0; i <= S - P; i++)
	{
		if (i == 0)
		{
			for (int j = 0; j < P; j++)
			{
				CurrentCount[KeytoInt[str[i + j]]]++;
			}
		}
		else
		{
			CurrentCount[KeytoInt[str[i - 1]]]--;
			CurrentCount[KeytoInt[str[i + P - 1]]]++;
		}

		bool bSucceed = true;
		for (int j = 0; j < 4; j++)
		{
			if (CurrentCount[j] < MinCount[j])
			{
				bSucceed = false;
				break;
			}
		}

		if (bSucceed)
		{
			result++;
		}
	}

	cout << result << endl;


	return 0;
}
