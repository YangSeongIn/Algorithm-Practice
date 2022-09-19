#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    long long dp[5001] = {0};
    dp[0] = 1;
    dp[2] = 3;
    if (n % 2 == 1) return 0;
    long long tmp = 0;
    for (int i = 4; i <= n; i += 2)
    {
        dp[i] = dp[i - 2] * 3;
        tmp += dp[i - 4] * 2;
        dp[i] += tmp;
        dp[i] %= 1000000007; 
    }
    return (int)dp[n];
}
