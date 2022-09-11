#include <string>
#include <vector>
#include <stack>

using namespace std;

int cnt = 0;

bool check(char c1, char c2)
{
    if (c1 == '{' && c2 == '}' || c1 == '[' && c2 == ']' || c1 == '(' && c2 == ')')
        return true;
    return false;
}

void getNum(string s)
{
    stack<char> stk;
    for (int i = 0; i < s.length(); i++)
    {
        if (stk.size() == 0 || !check(stk.top(), s[i]))
            stk.push(s[i]);
        else
            stk.pop();
    }
    if (stk.size() == 0)
        cnt++;
}

int solution(string s) {
    for (int i = 0; i < s.length(); i++)
    {
        getNum(s);
        char tmp = s[0];
        s = s.substr(1, s.length() - 1);
        s += tmp;
    }

    return cnt;
}
