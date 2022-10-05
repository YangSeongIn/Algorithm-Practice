#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> land)
{
    int answer = 0;
    vector<vector<int>> dp(land.begin(), land.end());
    for (int i = 1; i < land.size(); i++)
    {
        for (int j = 0; j < land[0].size(); j++)
        {
            for (int k = 0; k < land[0].size(); k++)
            {
                if (j == k) continue;
                dp[i][j] = max(dp[i][j], dp[i - 1][k] + land[i][j]);
            }
        }
    }

    answer = *max_element(dp[land.size() - 1].begin(), dp[land.size() - 1].end());

    return answer;
}
