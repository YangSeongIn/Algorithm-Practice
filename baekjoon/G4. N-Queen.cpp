#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

int N, cnt(0);
vector<int> v;

bool check(int level) {
    for (int i = 0; i < level; i++) {
        if (v[i] == v[level] || abs(v[level] - v[i]) == level - i) {
            return false;
        }
    }
    return true;
}

void dfs(int n) {
    if (n == N) cnt++;
    else {
        for (int i = 0; i < N; i++) {
            v[n] = i;
            if (check(n)) {
                dfs(n + 1);
            }
        }
    }
}

int main() {
    cin.tie();
    cout.tie();
    ios_base::sync_with_stdio(false);

    cin >> N;
    v.resize(N + 1);

    dfs(0);
    cout << cnt;

    return 0;
}
