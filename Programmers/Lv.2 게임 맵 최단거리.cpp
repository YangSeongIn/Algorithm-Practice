#include<vector>
#include<queue>
using namespace std;

int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};
vector<vector<bool>> visited;
int cnt = 0;

int bfs(int a, int b, vector<vector<int>>& maps)
{
    queue<pair<int, int>> q;
    q.push(make_pair(a, b));
    while(!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        int r = p.first;
        int c = p.second;
        if (r == maps.size() - 1 && c == maps[0].size() - 1) return maps[r][c];
        for (int i = 0; i < 4; i++)
        {
            int tmpR = r + dr[i];
            int tmpC = c + dc[i];
            if (0 <= tmpR && tmpR < maps.size() && 0 <= tmpC && tmpC < maps[0].size() && !visited[tmpR][tmpC] && maps[tmpR][tmpC] != 0)
            {
                visited[tmpR][tmpC] = true;
                q.push(make_pair(tmpR, tmpC));
                maps[tmpR][tmpC] = maps[r][c] + 1;
            }
        }
    }
    return -1;
}

int solution(vector<vector<int>> maps)
{
    int answer = 0;
    visited = vector(maps.size(), vector<bool>(maps[0].size(), false));
    answer = bfs(0, 0, maps);
    return answer;
}
