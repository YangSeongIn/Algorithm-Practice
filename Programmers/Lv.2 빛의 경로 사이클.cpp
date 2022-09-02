#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// L -> -1 , R -> 1, S -> 0
int dr[4] = { 0, -1, 0, 1 };
int dc[4] = { -1, 0, 1, 0 };
// 왼, 위, 오, 아
bool visited[501][501][4];
vector<vector<char>> mat;

void makeMat(vector<string>& grid) 
{
    vector<char> temp;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[i].length(); j++)
        {
            temp.push_back(grid[i][j]);
        }
        mat.push_back(temp);
        temp.clear();
    }
}

vector<int> solution(vector<string> grid) 
{
    vector<int> answer;

    makeMat(grid);
    int curR, curC;
    int dirIdx;
    int cnt = 0;
    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat[0].size(); j++)
        {
            for (int k = 0; k < 4; k++)
            {
                curR = i;
                curC = j;
                dirIdx = k;
                while (true) 
                {
                    if (!visited[curR][curC][dirIdx])
                    {
                        visited[curR][curC][dirIdx] = true;
                        curR += dr[dirIdx];
                        curC += dc[dirIdx];

                        if (curR == mat.size()) curR = 0;
                        else if (curR < 0) curR = mat.size() - 1;

                        if (curC == mat[0].size()) curC = 0;
                        else if (curC < 0) curC = mat[0].size() - 1;


                        if (mat[curR][curC] == 'R') dirIdx += 1;
                        else if (mat[curR][curC] == 'L') dirIdx -= 1;

                        if (dirIdx == 4) dirIdx = 0;
                        else if (dirIdx < 0) dirIdx = 3;

                        cnt++;
                    }
                    else
                    {
                        if (cnt != 0)
                        {
                            answer.push_back(cnt);
                            cnt = 0;
                            
                        }
                        break;
                    }
                }
            }
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}
