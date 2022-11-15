#include <string>
#include <vector>

using namespace std;

int N;
vector<vector<int>> v;
vector<bool> visited;

void dfs(int i) {
    for (int j = 0; j < v[i].size(); j++) {
        if (visited[v[i][j]] == false) {
            visited[v[i][j]] = true;
            dfs(v[i][j]);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    N = n;
    visited.resize(n);
    v.resize(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            if (computers[i][j] == 1) {
                v[i].push_back(j);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (visited[i] == false) {
            visited[i] = true;
            dfs(i);
            answer++;
        }
    }

    return answer;
}
