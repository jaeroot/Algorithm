#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str;
	cin >> str;

	int result = 0;
	int current = 0;
	int temp = 0;
	int bFlag = 1;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i]  == '-')
		{
			current += temp;
			result += bFlag * current;

			current = 0;
			temp = 0;
			bFlag = -1;

			continue;
		}
		else if (str[i] == '+')
		{
			if (bFlag == -1)
			{
				current += temp;
			}
			else
			{
				result += temp;
			}

			temp = 0;
			
			continue;
		}
		
		int c = str[i] - '0';
		temp = temp * 10 + c;
	}
	current += temp;
	result += bFlag * current;

	cout << result << '\n';

	return 0;
}
