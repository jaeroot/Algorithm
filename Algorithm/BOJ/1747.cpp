#include <iostream>
#include <string>

using namespace std;

const int MAX_ARR = 1111111;
bool arr[MAX_ARR + 1] = { true, true };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	for (int i = 2; i * i <= MAX_ARR; i++)
	{
		for (int j = i; j * i <= MAX_ARR; j++)
		{
			arr[i * j] = true;
		}
	}

	for (int i = N; i <= MAX_ARR; i++)
	{
		if (!arr[i])
		{
			string s = to_string(i);
			bool bFlag = true;
			for (int j = 0; j <= s.size() / 2; j++)
			{
				if (s[j] != s[s.size() - 1 - j])
				{
					bFlag = false;

					break;
				}
			}

			if (bFlag)
			{
				cout << i << '\n';

				break;
			}
		}
	}

	return 0;
}
