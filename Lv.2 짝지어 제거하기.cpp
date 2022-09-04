// 문자열 문제를 제거하거나 삽입할 때는 stack이나 queue를 생각하자

#include <iostream>
#include <string>
#include <stack>

using namespace std;

int solution(string s)
{
    int answer = -1;
    stack<char> stk;
    if (s.length() == 1) return 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (stk.size() == 0)
        {
            stk.push(s[i]);
            continue;
        }
        if (stk.top() == s[i])
        {
            stk.pop();
        }
        else
        {
            stk.push(s[i]);
        }
    }
    stk.size() == 0 ? answer = 1 : answer = 0;
    return answer;
}
