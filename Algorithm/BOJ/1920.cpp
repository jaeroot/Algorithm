#include <iostream>
#include <algorithm>

using namespace std;

int N, M, input;
int A[100000] = {};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}

	sort(A, A + N);

	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> input;

		cout << (binary_search(A, A + N, input) ? 1 : 0) << '\n';
	}

	return 0;
}
