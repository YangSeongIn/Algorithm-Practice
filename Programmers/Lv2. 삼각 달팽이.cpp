#include <string>
#include <vector>

using namespace std;

int curVal = 1;
int row_idx = 0;
int col_idx = 0;
int len;
int mat[1001][1001] = {0, };

void left()
{
    for (int i = 0; i < len; i++)
    {
        mat[row_idx++][col_idx] = curVal++;
    }
    row_idx--;
    col_idx++;
    len--;
}

void bottom()
{
    for (int i = 0; i < len; i++)
    {
        mat[row_idx][col_idx++] = curVal++;
    }
    col_idx -= 2;
    row_idx--;
    len--;
}

void right()
{
    for (int i = 0; i < len; i++)
    {
        mat[row_idx--][col_idx--] = curVal++;
    }
    row_idx += 2;
    col_idx++;
    len--;
}

vector<int> solution(int n) {
    vector<int> answer;
    len = n;
    if (n == 1) return vector<int>({1});
    if (n == 2) return vector<int>({1, 2, 3});
    while (len > 0)
    {
        left();
        bottom();
        right();
    }
    int idx = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < idx; j++)
        {
            answer.push_back(mat[i][j]);
        }
        idx++;
    }
    return answer;
}
