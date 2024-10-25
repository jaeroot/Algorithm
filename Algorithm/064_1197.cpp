#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int V, E;
vector<tuple<int, int, int>> vec;
int arr[10001] = {};

int Find(int Index)
{
	if (Index == arr[Index])
	{
		return Index;
	}

	arr[Index] = Find(arr[Index]);
	return arr[Index];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> V >> E;
	for (int i = 0; i <= V; i++)
	{
		arr[i] = i;
	}
	vec.reserve(E);

	int A, B, C;
	for (int i = 0; i < E; i++)
	{
		cin >> A >> B >> C;

		vec.push_back({ C, A, B });
	}

	sort(vec.begin(), vec.end());

	int CurrentEdge = 0;
	int Index = 0;
	int Result = 0;
	while (CurrentEdge < V - 1)
	{
		tuple<int, int, int> t = vec[Index];
		Index++;
		
		int Result1 = Find(get<1>(t));
		int Result2 = Find(get<2>(t));
		if (Result1 == Result2)
		{
			continue;
		}
		else if (Result1 < Result2)
		{
			arr[Result2] = Result1;
		}
		else
		{
			arr[Result1] = Result2;
		}

		Result += get<0>(t);
		CurrentEdge++;
	}

	cout << Result << '\n';

	return 0;
}
