#include <iostream>
#include <vector>

using namespace std;

int n, m;
int arr[1000001] = {};

int FindParent(int Index)
{
	if (arr[Index] == Index)
	{
		return Index;
	}

	arr[Index] = FindParent(arr[Index]);

	return arr[Index];
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		arr[i] = i;
	}
		
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> c >> a >> b;

		if (c == 0)			// Union
		{
			int AParent = FindParent(a);
			int BParent = FindParent(b);

			if (AParent < BParent)
			{
				arr[BParent] = AParent;
			}
			else
			{
				arr[AParent] = BParent;
			}
		}
		else if (c == 1)	// Find
		{
			if (FindParent(a) == FindParent(b))
			{
				cout << "YES" << "\n";
			}
			else
			{
				cout << "NO" << "\n";
			}
		}
	}

	return 0;
}
