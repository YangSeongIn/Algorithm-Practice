#include <string>
#include <vector>
#include <queue>
#include <algorithm> 

using namespace std;

int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0 ,0};

vector<vector<bool>> visited;
vector<vector<bool>> visitedTmp;

bool bfs(int r, int c, vector<string>& places) {
    queue<vector<int>> q;
    q.push({r, c, 0});
    visited[r][c] = true;
    while (!q.empty()) {
        vector<int> p = q.front();
        q.pop();
        // 3칸 이상이 될 경우
        if (p[2] == 2) {
            continue;
        }
        for (int i = 0; i < 4; i++) {
            int tmpR = p[0] + dr[i];
            int tmpC = p[1] + dc[i];
            if (0 <= tmpR && tmpR < 5 && 0 <= tmpC && tmpC < 5 && !visited[tmpR][tmpC]) {
                if (places[tmpR][tmpC] == 'O') {
                    visited[tmpR][tmpC] = true;
                    q.push({tmpR, tmpC, p[2] + 1});
                }
                // 2칸 이내에 P를 만날 경우
                else if (places[tmpR][tmpC] == 'P') {
                    return false;
                }
            }
        }
    }
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    visited.resize(places.size(), vector<bool>(places[0].size(), false));
    visitedTmp = visited;
    for (int i = 0; i < 5; i++) {
        bool b = false;
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 5; k++) {
                if (places[i][j][k] == 'P') {
                    if (!bfs(j, k, places[i])) {
                        answer.push_back(0);
                        b = true;
                        break;
                    }
                }
            }
            if (b) break;
        }
        if (!b) {
            answer.push_back(1);
        }
        visited = visitedTmp;
    }
    
    return answer;
}
