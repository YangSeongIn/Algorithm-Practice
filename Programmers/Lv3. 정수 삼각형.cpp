#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    if (triangle.size() == 1) return triangle[0][0];
    for (int i = 1; i < triangle.size(); i++)
    {
        triangle[i][0] += triangle[i-1][0];
        for (int k = 1; k < triangle[i].size() - 1; k++)
        {
            triangle[i][k] = max(triangle[i-1][k-1] + triangle[i][k], triangle[i-1][k] + triangle[i][k]);
        }
        triangle[i][i] += triangle[i-1][i-1];
    }
    answer = *max_element(triangle[triangle.size() - 1].begin(), triangle[triangle.size()-1].end());
    return answer;
}
