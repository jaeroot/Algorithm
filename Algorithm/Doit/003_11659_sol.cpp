#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

int suNo, quizNo;
int S[100001] = {};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> suNo >> quizNo;

	for (int i = 1; i <= suNo; i++)
	{
		int temp;
		cin >> temp;
		S[i] = S[i - 1] + temp;
	}

	for (int i = 0; i < quizNo; i++)
	{
		int start, end;
		cin >> start >> end;
		cout << S[end] - S[start - 1] << "\n";
	}

	return 0;
}
