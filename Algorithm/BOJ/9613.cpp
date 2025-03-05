#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

int arr[100] = {};

int main()
{
	int t;
	scanf("%d", &t);

	int n;
	long long result, A, B;
	while (t-- > 0)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &arr[i]);
		}

		result = 0;
		for (int i = 0; i < n - 1; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				A = arr[i];
				B = arr[j];

				while (true)
				{
					long long Mod = A % B;

					if (Mod == 0)
					{
						result += B;

						break;
					}

					A = B;
					B = Mod;
				}
			}
		}

		printf("%lld\n", result);
	}

	return 0;
}
