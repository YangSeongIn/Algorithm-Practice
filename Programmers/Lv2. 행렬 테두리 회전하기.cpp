#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int mat[101][101] = { 0 };

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    int k = 1;
    for (int i = 1; i <= rows; i++)
        for (int j = 1; j <= columns; j++)
            mat[i][j] = k++;
    for (int q = 0; q < queries.size(); q++)
    {
        vector<int> tmpVec = queries[q];
        vector<int> Vec1D;
        // 2 ~ 4
        for (int i = tmpVec[1]; i <= tmpVec[3]; i++)
            Vec1D.push_back(mat[tmpVec[0]][i]);
        // 3 ~ 5
        for (int i = tmpVec[0] + 1; i <= tmpVec[2]; i++)
            Vec1D.push_back(mat[i][tmpVec[3]]);
        // 4 ~ 3
        for (int i = tmpVec[3] - 1; i > tmpVec[1]; i--)
            Vec1D.push_back(mat[tmpVec[2]][i]);
        // 5 ~ 3
        for (int i = tmpVec[2]; i > tmpVec[0]; i--)
            Vec1D.push_back(mat[i][tmpVec[1]]);

        
        int tmp = Vec1D[Vec1D.size() - 1];
        for (int i = Vec1D.size() - 1; i > 0; i--)
        {
            Vec1D[i] = Vec1D[i - 1];
        }
        Vec1D[0] = tmp;
        int min = *min_element(Vec1D.begin(), Vec1D.end());
        answer.push_back(min);
        int index = 0;
        for (int i = tmpVec[1]; i <= tmpVec[3]; i++)
            mat[tmpVec[0]][i] = Vec1D[index++];

        for (int i = tmpVec[0] + 1; i <= tmpVec[2]; i++)
            mat[i][tmpVec[3]] = Vec1D[index++];

        for (int i = tmpVec[3] - 1; i > tmpVec[1]; i--)
            mat[tmpVec[2]][i] = Vec1D[index++];

        for (int i = tmpVec[2]; i > tmpVec[0]; i--)
            mat[i][tmpVec[1]] = Vec1D[index++];

    }
    return answer;
}
