#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N;
	scanf("%d", &N);

	vector<int> vec;
	vec.reserve(N);

	for (int i = 0; i < N; ++i)
	{
		int num;
		scanf("%d", &num);
		vec.push_back(num);
	}

	sort(vec.begin(), vec.end());

	for (auto v : vec)
	{
		printf("%d\n", v);
	}	


	return 0;
}
