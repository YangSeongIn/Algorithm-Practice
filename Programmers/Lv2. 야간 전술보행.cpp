#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool check(vector<vector<int>>& scope, vector<vector<int>>& times, int& tmp, int& i, int& mini) {
    for (int j = 0; j < times[i][0]; j++) {
        if (scope[i][0] <= tmp + j && tmp + j <= scope[i][1]) {
            if (mini > tmp + j) {
                mini = tmp + j;
                return true;
            }
        }
    }
    return false;
}

int solution(int distance, vector<vector<int>> scope, vector<vector<int>> times) {
    int arrLen = scope.size();
    int mini = distance + 1;
    
    for (int i = 0; i < arrLen; i++) {
        if (scope[i][0] > scope[i][1]) {
            int tmp;
            tmp = scope[i][0];
            scope[i][0] = scope[i][1];
            scope[i][1] = tmp;
        }
        
        int n = 0;
        while (true) {
            int tmp = 1 + (times[i][0] + times[i][1]) * n;
            if (tmp > scope[i][1] || tmp > distance) break;
            if (tmp < scope[i][0] && tmp + times[i][0] - 1 < scope[i][0]) {
                n++;
                continue;
            }
            if (check(scope, times, tmp, i, mini)) {
                break;
            }
            n++;
        }
    }
    return mini;
}
