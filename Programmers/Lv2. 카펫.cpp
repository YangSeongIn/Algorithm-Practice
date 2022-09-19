// 1차 풀이 (연립 방정식)
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int getAnswer(int b, int y)
{
    int a = ((b - 4) + sqrt((b - 4) * (b - 4) - 16 * y)) / 4;
    return a; 
}

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int a = getAnswer(brown, yellow);
    int b = yellow / a;
    if (a >= b)
    {
        answer.push_back(a + 2);
        answer.push_back(b + 2);
    }
    else if (a > b)
    {
        answer.push_back(b + 2);
        answer.push_back(a + 2);
    }
    return answer;
}

// 2차 풀이 (탐색)
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int sum = brown + yellow;
    for (int i = sum / 2; i > 0; i--)
    {
        if (sum % i == 0)
        {
            int a = i;
            int b = sum / i;
            if ((a - 2) * (b - 2) == yellow)
            {
                answer.push_back(a);
                answer.push_back(b);
                break;
            }
        }
    }
    return answer;
}
