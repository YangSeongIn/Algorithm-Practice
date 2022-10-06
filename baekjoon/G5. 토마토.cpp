#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;
queue<pair<int, int>> q;
int dr[4] = { 1, -1, 0, 0 };
int dc[4] = { 0, 0, 1, -1 };

int main()
{
	cin.tie();
	cout.tie();
	ios_base::sync_with_stdio(false);

	cin >> N >> M;
	vector<vector<int>> v(M, vector<int>(N));
	vector<vector<char>> visited(M, vector<char>(N));
	vector<pair<int, int>> tomatos;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> v[i][j];
			if (v[i][j] == 1)
			{
				tomatos.push_back(make_pair(i, j));
			}
		}
	}
	for (int i = 0; i < tomatos.size(); i++)
	{
		q.push(tomatos[i]);
	}
	while (!q.empty())
	{
		int r = q.front().first;
		int c = q.front().second;
		q.pop();
		visited[r][c] = true;
		for (int i = 0; i < 4; i++)
		{
			int tmpR = r + dr[i];
			int tmpC = c + dc[i];
			if (0 <= tmpR && tmpR < M && 0 <= tmpC && tmpC < N && !visited[tmpR][tmpC] && v[tmpR][tmpC] == 0)
			{
				visited[tmpR][tmpC] = true;
				v[tmpR][tmpC] = v[r][c] + 1;
				q.push(make_pair(tmpR, tmpC));
			}
		}
	}
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (v[i][j] == 0)
			{
				cout << -1;
				return 0;
			}
		}
	}
	int maxi = -1;
	for (int i = 0; i < M; i++)
	{
		int k = *max_element(v[i].begin(), v[i].end());
		if (k > maxi) maxi = k;
	}
	cout << maxi - 1;

	return 0;
}
