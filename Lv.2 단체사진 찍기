#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void sol(vector<char>& chars, vector<vector<char>>& strVec, int& answer)
{
    int cnt = 0;
    for (int i = 0; i < strVec.size(); i++)
    {
        int a = find(chars.begin(), chars.end(), strVec[i][0]) - chars.begin();
        int b = find(chars.begin(), chars.end(), strVec[i][1]) - chars.begin();
        int gap = abs(a - b);
        if (strVec[i][2] == '=')
        {
            if (gap == (strVec[i][3] - '0') + 1)
            {
                cnt++;
            }
        }
        else if (strVec[i][2] == '<')
        {
            if (gap < (strVec[i][3] - '0') + 1)
            {
                cnt++;
            }
        }
        else
        {
            if (gap > (strVec[i][3] - '0') + 1)
            {
                cnt++;
            }
        }
    }
    if (cnt == strVec.size())
    {
        answer++;
    }
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    int answer = 0;

    vector<vector<char>> strVec(n, vector<char>(4, ' '));
    // data 분리 & 정리
    for (int i = 0; i < data.size(); i++)
    {
        char fir = data[i][0];
        char sec = data[i][2];
        char val = data[i][4];
        char buho = data[i][3];
        strVec[i][0] = fir;
        strVec[i][1] = sec;
        strVec[i][2] = buho;
        strVec[i][3] = val;
    }

    // 순열
    vector<char> characters({ 'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T' });
    do 
    {
        sol(characters, strVec, answer);
    } 
    while (next_permutation(characters.begin(), characters.end()));

    return answer;
}
