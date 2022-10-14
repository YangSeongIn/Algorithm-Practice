#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> money) {
    int dp[1000001] = {0, };
    int dp2[1000001] = {0, };
    dp[0] = money[0];
    dp[1] = dp[0];
    dp2[1] = money[1];
    for (int i = 2; i <= money.size() - 1; i++) {
        dp2[i] = max(money[i] + dp2[i - 2], dp2[i - 1]);
        if (i == money.size() - 1) continue;
        dp[i] = max(money[i] + dp[i - 2], dp[i - 1]);
    }
    return max(dp[money.size() - 2], dp2[money.size() - 1]);
}
