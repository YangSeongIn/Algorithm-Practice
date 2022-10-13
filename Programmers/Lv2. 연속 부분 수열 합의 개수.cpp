#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int dp[1001][1001] = { 0, };
unordered_set<int> s;

int solution(vector<int> elements) {
    int answer(0), idx(1);
    int elementSize = elements.size();
    for (int i = 0; i < elementSize; i++) {
        dp[1][i] = elements[i];
        s.insert(dp[1][i]);
    }
    for (int i = 2; i <= elementSize; i++) {
        for (int j = 0; j < elementSize; j++) {
            dp[i][j] = dp[i - 1][j] + dp[1][(j + idx) % elementSize];
            s.insert(dp[i][j]);
        }
        idx++;
    }
    answer = s.size();
    return answer;
}
