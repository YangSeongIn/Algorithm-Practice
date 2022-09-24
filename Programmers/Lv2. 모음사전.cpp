#include <string>
#include <vector>

using namespace std;

string aeiou = "AEIOU";
int cnt = 0;
int answer;

void dfs(string s, string ans)
{
    if (s == ans)
    {
        answer = cnt;
        return;
    }
    if (s.length() > 5) return;
    cnt++;
    for (char& i : aeiou)
    {
        dfs(s + i, ans);
    }
}

int solution(string word) {
    dfs("", word);
    return answer;
}
