#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> vec[10001] = {};
int num[10001] = {};
bool visited[10001] = {};

void DFS(int data)
{
	int sum = 0;
	cout << data << endl;
	for (auto v : vec[data])
	{
		if (visited[v] == false)
		{
			visited[v] = true;

			if (num[v] == 0)
			{
				DFS(v);
			}

			sum += num[v];
			cout << v << " : " << sum << " ,, ";
		}
	}

	sum++;
	num[data] = sum;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;

		vec[b].push_back(a);
	}

	vector<int> result;
	int max = 0;
	for (int i = 1; i <= N; i++)
	{
		if (num[i] == 0)
		{
			for (int j = 0; j <= N; j++)
			{
				visited[j] = false;
			}

			visited[i] = true;
			DFS(i);
			cout << i << ", " << num[i] << endl;

			if (num[i] > max)
			{
				max = num[i];

				result.clear();
				result.push_back(i);
			}
			else if (num[i] == max)
			{
				result.push_back(i);
			}
		}
	}

	for (auto r : result)
	{
		cout << r << " ";
	}
	cout << "\n";


	return 0;
}
