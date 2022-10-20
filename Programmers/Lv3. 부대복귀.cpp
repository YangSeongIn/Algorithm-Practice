#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<bool> visited;
vector<bool> visitedTmp;
vector<vector<int>> v;

int bfs(int s, int d) {
    queue<vector<int>> q;
    q.push({s, 1});
    visited[s] = true;
    while(!q.empty()) {
        vector<int> tmp = q.front();
        q.pop();
        for (int i = 0; i < v[tmp[0]].size(); i++) {
            if (v[tmp[0]][i] == d) return tmp[1];
            if (visited[v[tmp[0]][i]]) continue;
            visited[v[tmp[0]][i]] = true;
            q.push({v[tmp[0]][i], tmp[1] + 1});
        }
    }
    return -1;
}

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    v.resize(n + 1);
    visited.resize(n + 1, false);
    visitedTmp = visited;
    
    for (int i = 0; i < roads.size(); i++) {
        v[roads[i][0]].push_back(roads[i][1]);
        v[roads[i][1]].push_back(roads[i][0]);
    }
    for (int i = 0; i < sources.size(); i++) {
        if (sources[i] == destination) answer.push_back(0);
        else {
            int ans = bfs(sources[i], destination);
            answer.push_back(ans);
            visited = visitedTmp;
        }
    }
    return answer;
}
