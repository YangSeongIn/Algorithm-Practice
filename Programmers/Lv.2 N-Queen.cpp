#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

int col[13];
int cnt = 0;

bool promising(int n)
{
    for (int j = 0; j < n; j++)
    {
        // 대각선 & 같은 라인 제거
        if (col[j] == col[n] || abs(col[n] - col[j]) == n - j)
        {
            return false;
        }
    }
    return true;
}

void dfs(int n, int N)
{
    if (n == N)
    {
        cnt++;
        return;
    }
    for (int i = 0; i < N; i++)
    {
        col[n] = i;
        if (promising(n))
        {
            dfs(n + 1, N);
        }
    }
}

int solution(int n) {
    int answer = 0;
    dfs(0, n);
    answer = cnt;
    return answer;
}
