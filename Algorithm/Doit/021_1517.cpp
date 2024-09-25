#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>

using namespace std;

int N;
long long Result = 0;
vector<int> vec;

void MergeSort(int Index, int Size)
{
	if (Size != 1)
	{
		MergeSort(Index, Size / 2);
		MergeSort(Index + (Size / 2), Size - (Size / 2));
	}
	else
	{
		return;
	}

	vector<int> SortVec;
	SortVec.reserve(Size);

	int First = Index;
	int Second = Index + (Size / 2);

	int Count = 0;
	while (Count++ < Size)
	{
		if (First >= Index + (Size / 2))
		{
			SortVec.push_back(vec[Second]);
			Second++;
		}
		else if (Second >= Index + Size)
		{
			SortVec.push_back(vec[First]);
			First++;
		}
		else
		{
			if (vec[First] <= vec[Second])
			{
				SortVec.push_back(vec[First]);
				First++;
			}
			else
			{
				SortVec.push_back(vec[Second]);
				Result += Index + (Size / 2) - First;
				Second++;
			}
		}
	}

	for (int i = 0; i < Size; i++)
	{
		vec[Index + i] = SortVec[i];
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;

		vec.push_back(num);
	}

	MergeSort(0, N);

	cout << Result << "\n";


	return 0;
}
