#include <string>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

map<int, pair<int, vector<int>>> m;
vector<bool> visited;
int q = 0;
int w = 0;

void dfs(int n, int k) {
    if (visited[n]) return;
    visited[n] = true;
    if (k == 0)
    {
        q += m[n].first - 1;
    }
        
    else if (k == 1)
        w += m[n].first - 1;
    for (int i = 0; i < m[n].second.size(); i++) {
        dfs(m[n].second[i], k);
    }
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 987654321;
    visited.resize(n + 1);
    vector<bool> visitedTmp = visited;
    for (int i = 0; i < wires.size(); i++) {
        m[wires[i][0]].first++;
        m[wires[i][0]].second.push_back(wires[i][1]);
        m[wires[i][1]].first++;
        m[wires[i][1]].second.push_back(wires[i][0]);
    }

    for (int i = 0; i < wires.size(); i++) {
        visited = visitedTmp;
        visited[wires[i][1]] = true;
        dfs(wires[i][0], 0);
        visited = visitedTmp;
        visited[wires[i][0]] = true;
        dfs(wires[i][1], 1);
        int tmp = abs(q - w);
        if (answer > tmp) answer = tmp;
        q = 0;
        w = 0;
    }

    return answer;
}
