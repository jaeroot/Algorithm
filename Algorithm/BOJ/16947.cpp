#include <iostream>
#include <vector>
#include <limits.h>
#include <stack>
#include <queue>

using namespace std;

int N;
vector<int> vec[3001] = {};
int visited[3001] = {};
int result[3001] = {};
stack<int> s;

void DFS(int index)
{
	visited[index] = 2;
	int before = s.top();
	s.push(index);

	for (const int v : vec[index])
	{
		if (visited[v] == 0)
		{
			DFS(v);
		}
		else if (visited[v] == 2 && v != before)
		{
			stack<int> temp;

			while (true)
			{
				int top = s.top();
				s.pop();

				temp.push(top);
				result[top] = 0;
				
				if (top == v)
				{
					break;
				}
			}

			while (!temp.empty())
			{
				s.push(temp.top());
				temp.pop();
			}
		}
	}

	visited[index] = 1;
	s.pop();
}

void BFS(int index)
{
	queue<pair<int, int>> q;
	q.push({ index, 0 });

	while (!q.empty())
	{
		pair<int, int> front = q.front();
		q.pop();

		for (const int v : vec[front.first])
		{
			if (result[v] > front.second + 1)
			{
				result[v] = front.second + 1;
				q.push({ v, front.second + 1 });
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		result[i] = INT_MAX;
	}

	int input1, input2;
	for (int i = 0; i < N; i++)
	{
		cin >> input1 >> input2;
		
		vec[input1].push_back(input2);
		vec[input2].push_back(input1);
	}

	s.push(0);
	for (int i = 1; i <= N; i++)
	{
		if (visited[i] == 0)
		{
			DFS(i);
		}
	}

	for (int i = 1; i <= N; i++)
	{
		if (result[i] == 0)
		{
			BFS(i);
		}
	}

	for (int i = 1; i <= N; i++)
	{
		cout << result[i] << ' ';
	}
	cout << '\n';


	return 0;
}
