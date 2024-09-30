#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long A, B;
	cin >> A >> B;

	while (true)
	{
		long long Mod = A % B;

		if (Mod == 0)
		{
			for (long long i = 0; i < B; i++)
			{
				cout << 1;
			}
			cout << "\n";

			break;
		}

		A = B;
		B = Mod;
	}


	return 0;
}
