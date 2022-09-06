#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<bool> visited;
vector<int> arrTmp;

void permutation(int n)
{
	if (n == M)
	{
		for (int i = 0; i < arrTmp.size(); i++)
		{
			printf("%d ", arrTmp[i]);
		}
		printf("\n");
		return;
	}
	for (int i = 1; i <= N; i++)
	{
		if (visited[i]) continue;
		visited[i] = true;
		arrTmp.push_back(i);
		permutation(n + 1);
		arrTmp.pop_back();
		visited[i] = false;
	}
}


int main()
{
	cin >> N >> M;
	visited.resize(N + 1);
	permutation(0);
	return 0;
}
