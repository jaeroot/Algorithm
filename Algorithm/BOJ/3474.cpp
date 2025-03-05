#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	int N;
	int B, P;
	while (T-- > 0)
	{
		cin >> N;

		B = 0;
		P = 0;

		for (int i = 2; i <= N; i *= 2)
		{
			B += N / i;
		}

		for (int i = 5; i <= N; i *= 5)
		{
			P += N / i;
		}
		
		cout << min(B, P) << '\n';
	}


	return 0;
}
