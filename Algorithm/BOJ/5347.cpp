#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);

	int A, B;
	long long result;
	while (n-- > 0)
	{
		scanf("%d %d", &A, &B);
		
		result = 0;
		long long ModA = A;
		long long ModB = B;
		while (true)
		{
			long long Mod = ModA % ModB;

			if (Mod == 0)
			{
				result = A / ModB * B;

				break;
			}

			ModA = ModB;
			ModB = Mod;
		}

		printf("%lld\n", result);
	}

	return 0;
}
