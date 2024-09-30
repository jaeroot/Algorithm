#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>

using namespace std;

bool arr[1111111] = { true, true };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	for (int i = 2; i * i <= 1111111; i++)
	{
		for (int j = i; i * j <= 1111111; j++)
		{
			arr[i * j] = true;
		}
	}

	for (int i = N; i <= 1111111; i++)
	{
		if (arr[i] == false)
		{
			string str = to_string(i);

			bool bFlag = true;
			for (int j = 0; j < str.size(); j++)
			{
				if (j < str.size() - 1 - j)
				{
					if (str[j] == str[str.size() - 1 - j])
					{
						continue;
					}
					else
					{
						bFlag = false;

						break;
					}
				}
			}

			if (bFlag == true)
			{
				cout << i << "\n";

				break;
			}
		}
	}

	return 0;
}
