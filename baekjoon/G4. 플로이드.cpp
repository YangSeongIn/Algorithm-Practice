#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

const int INF = 987654321;

int N, M;
int mat[101][101];

void solution()
{
    for (int k = 1; k <= N; k++)
    {
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
			      {
                mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
			      }
		    }
    }
}

int main()
{
    cin.tie();
    cout.tie();
    ios_base::sync_with_stdio(false);

    cin >> N;
    cin >> M;
    fill(&mat[0][0], &mat[100][100], INF);

    for (int i = 0; i < M; i++)
    {
        int q, w, e;
        cin >> q >> w >> e;
        mat[q][w] = min(mat[q][w], e);
    }

    solution();

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (mat[i][j] == INF || i == j) mat[i][j] = 0;
            cout << mat[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}
