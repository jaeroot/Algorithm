#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	int A, B;
	while (T-- > 0)
	{
		cin >> A >> B;

		int ModA = A;
		int ModB = B;
		int GCD = 1;
		while (true)
		{
			int Mod = max(ModA, ModB) % min(ModA, ModB);

			if (Mod == 0)
			{
				GCD = min(ModA, ModB);

				break;
			}
			else
			{
				ModA = min(ModA, ModB);
				ModB = Mod;
			}
		}

		cout << A / GCD * B << "\n";
	}


	return 0;
}
